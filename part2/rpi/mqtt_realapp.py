# mqtt_realapp.py
# 온습도 센서 데이터 통신, RGB LED Setting
# MQTT -> json transfer

import paho.mqtt.client as mqtt
import RPi.GPIO as GPIO
import adafruit_dht
import board
import time
import json
import datetime as dt

# RGB LED 에 대한 각 핀 넘버
red_pin = 4
green_pin = 6
blue_pin = 5
dht_pin = 18
dev_id = 'PKNU60'

loop_num = 0

## 초기화 시작

def onConnect(Client, userdata, flags, reason_code, properties):
    print(f'연결성공: {reason_code}')
    Client.subscribe('pknu/rcv/')
    #  RGB LED OFF : HIGH -> OFF, LOW -> ON
    GPIO.output(red_pin, GPIO.HIGH)
    GPIO.output(green_pin, GPIO.HIGH)
    GPIO.output(blue_pin, GPIO.HIGH)

def onMessage(Client, userdata, msg):
    # print(f'{msg.topic} + {msg.payload}')
    # byte code -> string
    # '' -> ""
    value = json.loads(msg.payload.decode('utf-8').replace("'",'"'))
    res = value['control']
    if res == 'warning':
        GPIO.output(blue_pin,GPIO.HIGH) # off
        GPIO.output(green_pin,GPIO.HIGH) # off
        GPIO.output(red_pin,GPIO.LOW) # on

    elif res == 'normal':
        GPIO.output(blue_pin,GPIO.HIGH) # off
        GPIO.output(green_pin,GPIO.LOW) # on
        GPIO.output(red_pin,GPIO.HIGH) # off

    elif res == 'off':
        GPIO.output(blue_pin,GPIO.HIGH) # off
        GPIO.output(green_pin,GPIO.HIGH) # off
        GPIO.output(red_pin,GPIO.HIGH) # off

GPIO.cleanup()
GPIO.setmode(GPIO.BCM)
GPIO.setup(red_pin, GPIO.OUT)
GPIO.setup(green_pin, GPIO.OUT) # LED를 키라는 신호를 RPi에서 보내는 것
GPIO.setup(blue_pin, GPIO.OUT)
GPIO.setup(dht_pin, GPIO.IN) # dht센서로 부터 온습도 값을 PRi에서 받는 것

dhtDevice = adafruit_dht.DHT11(board.D18) # 중요!!!

## 초기화 끝

## 실행 시작
mqttc = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2) # 2023.09 이후 버전업
mqttc.on_connect = onConnect # 접속 시 이벤트
mqttc.on_message = onMessage # 메시지 전송 

## 192.168.5.2 window ip
mqttc.connect('192.168.5.2', 1883, 60) #('Window ip',포트번호,60초 이내에 연결되지 않으면 종료)

mqttc.loop_start()
while True:
    time.sleep(2)   
    try:
        # 온습도 값을 받아서 MQTT로 전송
        temp = dhtDevice.temperature
        humid = dhtDevice.humidity
        print(f'{loop_num}- Temp:{temp}/humid:{humid}')

        origin_data = { 'DEV_ID' : dev_id,
                        'CURR_DT' : dt.datetime.now().strftime('%Y-%m-%d %H:%M:%S'),
                        'TYPE' : 'TEMPHUMID',
                        'VALUE' : f'{temp}|{humid}'
                      } # json데이터를 만들기 전에 딕셔너리 데이터 생성
        

        # 딕셔너리 데이터를 json 데이터로 변환
        pub_data = json.dumps(origin_data, ensure_ascii=False)

        mqttc.publish('pknu/data/', pub_data) # mqtt에 json데이터 보내기
        loop_num += 1
    except RuntimeError as ex:
        print(ex.args[0])
    except KeyboardInterrupt:
        break


mqttc.loop_stop()
