# dht11_test.py
import adafruit_dht
import time
import RPi.GPIO as GPIO
import board

log_num = 0
sensor_pin = 18
GPIO.setmode(GPIO.BCM)
GPIO.setup(sensor_pin, GPIO.IN) # DHT11 센서를 통해 값을 받아야하기 때문에 IN 사용
dhtDevice = adafruit_dht.DHT11(board.D18)   # Problem!!

while(True):
    try:
        temp = dhtDevice.temperature
        humid = dhtDevice.humidity
        print(f'{log_num} - Temp : {temp}C / Humind : {humid}%')
        log_num += 1
        time.sleep(2)
        # 예외처리
    except RuntimeError as ex:
        print(ex.args[0])
    except KeyboardInterrupt:
        break

dhtDevice.exit()