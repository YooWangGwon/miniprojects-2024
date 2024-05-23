# mqtt_simple.py
import paho.mqtt.client as mqtt
import time

loop_num = 0

def onConnect(Client, userdata, flags, reason_code, properties):
    print(f'Connected result code : {reason_code}')
    Client.subscribe('pknu60/rcv')

def onMessage(Client, userdata, msg):
    print(f'{msg.topic} + {msg.payload}')

mqttc = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2) # 2023.09 이후 버전업
mqttc.on_connect = onConnect # 접속 시 이벤트
mqttc.on_message = onMessage # 메시지 전송 

# 192.168.5.2 window ip
mqttc.connect('192.168.5.2', 1883, 60) #('Window ip',포트번호,60초 이내에 연결되지 않으면 종료)

mqttc.loop_start()
while True:
    mqttc.publish('pknu60/data', loop_num)
    loop_num += 1
    time.sleep(1)

mqttc.loop_stop()