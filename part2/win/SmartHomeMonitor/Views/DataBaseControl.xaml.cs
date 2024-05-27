using MahApps.Metro.Controls;
using MQTTnet;
using MQTTnet.Client;
using Newtonsoft.Json;
using SmartHomeMonitoringApp.Logics;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace SmartHomeMonitoringApp.Views
{
    /// <summary>
    /// DataBaseControl.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class DataBaseControl : UserControl
    {
        // 초기에 필요한 변수또는 속성 선언

        public Boolean IsConnected { get; set; }
        Thread MqttThread { get; set; }  // 없을 경우 UI 컨트롤과 충돌이 발생하여 Log를 찍지 못함(화면 응답없음 방지)
        int MaxCount { get; set; } = 10; // MQTT Log 과적으로 인한 속도저하를 방지하기 위함

        public DataBaseControl()
        {
            InitializeComponent();
        }

        private void UserControl_Loaded(object sender, RoutedEventArgs e)
        {
            TxtBrokerUrl.Text = Commons.BROKERHOST;
            TxtMqttTopic.Text = Commons.MQTTTOPIC;
            TxtConnstring.Text = Commons.DBCONNSTRING;

            IsConnected = false;
            BtnConnect.IsChecked = false;
        }

        private void BtnConnect_Click(object sender, RoutedEventArgs e)
        {
            ConnectSystemAsync(); // DB, MQTT 연결용 함수
        }

        private async Task ConnectSystemAsync()
        {
            if (IsConnected == false) // 연결이 안된 경우 처리
            {
                // 한번도 접속을 안했을 경우 모두 연결
                var mqttFactory = new MqttFactory();    // 디자인 패턴 중 팩토리 패턴
                Commons.MQTT_CLIENT = mqttFactory.CreateMqttClient();
                // MQTT 브로커 아이피 
                var mqttClientOptions = new MqttClientOptionsBuilder().WithTcpServer(TxtBrokerUrl.Text).Build();

                await Commons.MQTT_CLIENT.ConnectAsync(mqttClientOptions, CancellationToken.None); // MQTT 연결
                Commons.MQTT_CLIENT.ApplicationMessageReceivedAsync += MQTT_CLIENT_ApplicationMessageReceivedAsync; // 이벤트 연결

                var mqttSubscribeOptions = mqttFactory.CreateSubscribeOptionsBuilder().WithTopicFilter(
                    f =>
                    {
                        f.WithTopic(Commons.MQTTTOPIC);
                    }).Build();

                await Commons.MQTT_CLIENT.SubscribeAsync(mqttSubscribeOptions, CancellationToken.None);
                

                IsConnected = true;
                BtnConnect.IsChecked = true;
                BtnConnect.Content = "MQTT 연결중";
            }
            else
            {
                // 연결중인 상태에서 연결 끊기
                if (Commons.MQTT_CLIENT.IsConnected)
                {
                    // 이벤트 연결 끊어주기
                    Commons.MQTT_CLIENT.ApplicationMessageReceivedAsync -= MQTT_CLIENT_ApplicationMessageReceivedAsync;
                    await Commons.MQTT_CLIENT.DisconnectAsync();
                    TxtLog.Text += "연결 종료\n";
                    IsConnected = false;
                    BtnConnect.IsChecked = false;
                    BtnConnect.Content = "Connect";
                }
            }
        }

        private Task MQTT_CLIENT_ApplicationMessageReceivedAsync(MqttApplicationMessageReceivedEventArgs arg)
        {
            var payload = Encoding.UTF8.GetString(arg.ApplicationMessage.Payload);
            //Debug.WriteLine(payload);
            UpdateLog(payload); // TextBox에 추가

            InsertData(payload);

            return Task.CompletedTask; // Async에서 Task값을 넘겨주려면 이렇게
        }

        private void InsertData(string payload)
        {
            this.Invoke(() =>
            {

                var currValue = JsonConvert.DeserializeObject<Dictionary<string,string>>(payload); // 보낼때는 Serialize, 받을때는 Deserialize

                Debug.WriteLine(currValue["CURR_DT"]);
                // currValue["DEV_ID"], currValue["TYPE"], currValue["VALUE"]
                if(currValue != null)
                {
                    try
                    {
                        using(SqlConnection conn = new SqlConnection(TxtConnstring.Text))
                        {
                            conn.Open();
                            var insQuery = @"INSERT INTO [dbo].[SmartHomeData]
                                                        ([DEV_ID]
                                                        ,[CURR_DT]
                                                        ,[TEMP]
                                                        ,[HUMID])
                                                    VALUES
                                                        (@DEV_ID
                                                        ,@CURR_DT
                                                        ,@TEMP
                                                        ,@HUMID)";
                            SqlCommand cmd = new SqlCommand(insQuery, conn);
                            cmd.Parameters.AddWithValue("@DEV_ID", currValue["DEV_ID"]);
                            cmd.Parameters.AddWithValue("@CURR_DT", currValue["CURR_DT"]); // 문자열이 날짜 형식에 잘 맞춰있기 때문에 알아서 string -> datatime 자동변환됨
                           // cmd.Parameters.AddWithValue("@TEMP", currValue["TYPE"]);

                            var splitValue = currValue["VALUE"].Split('|'); // splitValue[0] = 온도값, splitValue[1] = 습도값
                            cmd.Parameters.AddWithValue("@TEMP", splitValue[0]);
                            cmd.Parameters.AddWithValue("@HUMID", splitValue[1]);

                            if(cmd.ExecuteNonQuery() == 1)
                            {
                                UpdateLog(">>> DB Success");
                            }
                            else
                            {
                                UpdateLog(">>> DB Failed");

                            }
                        }
                    }
                    catch(Exception ex)
                    {
                        UpdateLog($"DB 에러발생 : {ex.Message}");
                    }

                }
            });

            
        }

        private void UpdateLog(string payload)
        {
            this.Invoke(() =>
                {
                    TxtLog.Text += $"{payload}\n";
                    TxtLog.ScrollToEnd(); // 밑으로 계속 내려가다가 스크롤이 생기기 시작하면 제일 밑으로 포커스를 맞춰줌
                });
        }
    }
}