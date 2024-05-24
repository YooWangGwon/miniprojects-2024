# led_blink.py
# Red led
import RPi.GPIO as GPIO
import time

# RGB LED PinNumber setting
red_pin = 4
green_pin = 6
blue_pin = 5

GPIO.setmode(GPIO.BCM) # GPIO.BOARD(1~40)
GPIO.setup(red_pin, GPIO.OUT) # 4pin output
GPIO.setup(green_pin, GPIO.OUT) # 5pin output
GPIO.setup(blue_pin, GPIO.OUT) # 6pin output


try:
    while (True):
        GPIO.output(red_pin, False)
        GPIO.output(green_pin, False)
        GPIO.output(blue_pin, False)
        time.sleep(1) # 1sec

        # GPIO.output(red_pin, False)
        # GPIO.output(green_pin, True)
        # GPIO.output(blue_pin, False)
        # time.sleep(0.5)   # 0.5sec // G

        # GPIO.output(red_pin, False)
        # GPIO.output(green_pin, False)
        # GPIO.output(blue_pin, True)
        # time.sleep(0.5)   # 0.5 sec // B

        GPIO.output(red_pin, True) # 0.5sec
        GPIO.output(green_pin, True) # 0.5sec
        GPIO.output(blue_pin, True) # 0.5sec
        time.sleep(0.5) # white
except KeyboardInterrupt:
    GPIO.cleanup()

