using LiveChartsCore.SkiaSharpView.Drawing;
using LiveChartsCore;
using LiveChartsCore.SkiaSharpView.Extensions;
using LiveChartsCore.VisualElements;
using MahApps.Metro.Controls;
using MQTTnet;
using MQTTnet.Client;
using Newtonsoft.Json;
using SmartHomeMonitoringApp.Logics;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Threading;
using LiveChartsCore.SkiaSharpView.VisualElements;
using LiveChartsCore.Defaults;
using LiveChartsCore.SkiaSharpView;

namespace SmartHomeMonitoringApp.Views
{
    /// <summary>
    /// RealTimeControl.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class RealTimeControl : UserControl
    {
        public RealTimeControl()
        {
            InitializeComponent();

            // 타이머 설정
            DispatcherTimer timer = new DispatcherTimer();
            timer.Interval = new TimeSpan(0, 0, 1);   // 1초마다
            timer.Tick += Timer_Tick;
            timer.Start();
        }

        // 라벨에 현재 시간 표시 이벤트
        private void Timer_Tick(object sender, EventArgs e)
        {
            LblSensingDt.Content = DateTime.Now.ToString("yyyy년 MM월 dd일 HH:mm:ss");
        }

        private async void UserControl_Loaded(object sender, RoutedEventArgs e)
        {
            if(Commons.MQTT_CLIENT != null && Commons.MQTT_CLIENT.IsConnected)
            {   // 이미 다른 화면에서 MQTT를 연결한 경우
                Commons.MQTT_CLIENT.ApplicationMessageReceivedAsync += MQTT_CLIENT_ApplicationMessageReceivedAsync;
            }
            else
            {
                // 한번도 연결된 적이 없을 경우
                var mqttFactory = new MqttFactory();
                Commons.MQTT_CLIENT = mqttFactory.CreateMqttClient();
                var mqttClientOptions = new MqttClientOptionsBuilder().WithTcpServer(Commons.BROKERHOST).Build();
                await Commons.MQTT_CLIENT.ConnectAsync(mqttClientOptions, CancellationToken.None);
                Commons.MQTT_CLIENT.ApplicationMessageReceivedAsync += MQTT_CLIENT_ApplicationMessageReceivedAsync;

                var mqttSubscribeOptions = mqttFactory.CreateSubscribeOptionsBuilder().WithTopicFilter(
                    f =>
                    {
                        f.WithTopic(Commons.MQTTTOPIC);
                    }).Build();
                await Commons.MQTT_CLIENT.SubscribeAsync(mqttSubscribeOptions, CancellationToken.None);
            }
        }

        private Task MQTT_CLIENT_ApplicationMessageReceivedAsync(MQTTnet.Client.MqttApplicationMessageReceivedEventArgs arg)
        {
            var payload = Encoding.UTF8.GetString(arg.ApplicationMessage.Payload);
            Debug.WriteLine(payload);
            UpdateChart(payload);

            return Task.CompletedTask; // Async에서 Task값을 넘겨주려면 이렇게
        }

        // 앵귤러 차트를 위한 변수, 속성 선언
        int sectionOuter = 130;
        int sectionWidth = 20;

        public IEnumerable<ISeries> HumidSeries { get; set; }

        public IEnumerable<VisualElement<SkiaSharpDrawingContext>> VisualElements { get; set; }

        public NeedleVisual Needle { get; set; }    // 

        private static void SetStyle(double sectionsOuter, double sectionsWidth, PieSeries<ObservableValue> series)
        {
            series.OuterRadiusOffset = sectionsOuter;
            series.MaxRadialColumnWidth = sectionsWidth;
        }

        private void UpdateChart(string payload)
        {
            this.Invoke(() =>
            {
                var currValue = JsonConvert.DeserializeObject<Dictionary<string, string>>(payload);

                var splitValue = currValue["VALUE"].Split('|');
                var temp = Convert.ToDouble(splitValue[0]);
                var humid = Convert.ToDouble(splitValue[1]);

                // 온도차트 값
                var tempVal = GaugeGenerator.BuildSolidGauge(new GaugeItem(
                    temp,
                    series =>
                    {
                        series.MaxRadialColumnWidth = 30;
                        series.DataLabelsSize = 50;
                    }
                ));

                // 네개의 방 차트에 같은 갑승ㄹ 할당
                ChtLivingTemp.Series = ChtDiningTemp.Series = ChtBedTemp.Series = ChtBathTemp.Series = tempVal;

                // 습도를 나타낼 앵귤러 차트를 초기화

                //위에서 만든 차트 화면 디자인을 실제 화면의 차트에 적용

                var sectionsOuter = 130;
                var sectionsWidth = 20;
                // 습도 차트 값 할당
                HumidSeries = GaugeGenerator.BuildAngularGaugeSections(
                    new GaugeItem(humid,
                    s => SetStyle(sectionsOuter, sectionsWidth, s))
                );
                ChtLivingHumid.Series = ChtDiningHumid.Series = ChtBedHumid.Series = ChtBathHumid.Series = HumidSeries;

                // 습도를 나타낼 앵귤러차트를 초기화
                Needle = new NeedleVisual { Value = humid };   // 차트 바늘의 초기값이 20
                // 앵귤러 차트를 그리기 위한 속성들
                VisualElements = new VisualElement<SkiaSharpDrawingContext>[]
                {
                new AngularTicksVisual
                {
                    // 앵귤러 차트를 꾸미는 속성들
                    LabelsSize = 12,
                    LabelsOuterOffset = 15,
                    OuterOffset = 65, // 차트 선이 퍼져있는 정도
                    TicksLength = 15 // 차트 실선 길이
                },
                Needle
                };

                //위에서 만든 차트 화면 디자인을 실제 화면의 차트에 적용
                ChtLivingHumid.VisualElements = ChtDiningHumid.VisualElements = ChtBedHumid.VisualElements = ChtBathHumid.VisualElements = VisualElements;
            });
        }

        private void BtnWaring_Click(object sender, RoutedEventArgs e)
        {
            Commons.MQTT_CLIENT.PublishStringAsync("pknu/rcv/", "{'control':'warning'}");
        }

        private void BtnNoraml_Click(object sender, RoutedEventArgs e)
        {
            Commons.MQTT_CLIENT.PublishStringAsync("pknu/rcv/", "{'control':'normal'}");
        }

        private void BtnOff_Click(object sender, RoutedEventArgs e)
        {
            Commons.MQTT_CLIENT.PublishStringAsync("pknu/rcv/", "{'control':'off'}");
        }
    }
}
