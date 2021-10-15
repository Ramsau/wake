import RPi.GPIO as GPIO
import sys
import time

pin = 2

try:
    press_for = float(sys.argv[1])
except:
    press_for = 0.5

GPIO.setmode(GPIO.BCM)

GPIO.setup(pin, GPIO.OUT)
GPIO.output(pin, GPIO.HIGH)
time.sleep(press_for)
GPIO.output(pin, GPIO.LOW)
time.sleep(0.1)
GPIO.cleanup()
