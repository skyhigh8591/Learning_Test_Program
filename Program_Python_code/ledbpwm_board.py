#! /usr/bin/python

import time
import RPi.GPIO as GPIO

LED_PIN=12
GPIO.setmode(GPIO.BOARD)

GPIO.setup(LED_PIN,GPIO.OUT)

pwm = GPIO.PWM(LED_PIN,50)
#0.5 => 1/0.5=2

pwm.start(0)

try:
	while True:
		for dc in range(0,101,5):
			print dc
			pwm.ChangeDutyCycle(dc)
			time.sleep(0.01)
		for dc in range(100,-1,-5):
			print dc
			pwm.ChangeDutyCycle(dc)
			time.sleep(0.01)	
except KeyboardInterrupt:
	pwm.stop()
	GPIO.cleanup()				