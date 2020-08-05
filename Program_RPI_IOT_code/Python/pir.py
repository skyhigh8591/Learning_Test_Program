#!/usr/bin/python
# -*- coding: UTF-8 -*-
import RPi.GPIO as GPIO
import time
pirPin=11

GPIO.setmode(GPIO.BOARD)
GPIO.setup(pirPin,GPIO.IN)

while True:
	print(GPIO.input(pirPin))
	time.sleep(0.5)
GPIO.cleanup()
