using MQTTnet.Client;

namespace SmartHomeMonitoringApp.Logics
{
    public class Commons
    {
        // Windows에 MQTT Broker가 설치되어 있으므로 사용가능한 호스트
        // localhost, 127.0.0.1, 162.168.5.2

        public static string BROKERHOST { get; set; } = "192.168.5.2"; // Window MQTT Broker Mosquitto IP
        public static string MQTTTOPIC { get; internal set; } = "pknu/data/";   // 대소문자 구분 필요, 마지막 /(Slash) 도 빠지면 안됨
        public static string DBCONNSTRING { get; set; } = "Data Source=localhost;Initial Catalog=EMS;Persist Security Info=True;User ID=sa;Encrypt=False;" +
                                                          "Password=mssql_p@ss";
        public static IMqttClient MQTT_CLIENT { get; set; } // 전체 프로젝트에서 다 사용할 공용 MQTT 클라이언트
    }
}
