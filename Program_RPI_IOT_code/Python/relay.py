#!/usr/bin/python
# -*- coding: UTF-8 -*-
import RPi.GPIO as GPIO
import time
relayPin=38

GPIO.setmode(GPIO.BOARD)
GPIO.setup(relayPin,GPIO.OUT)
dly=600

while True:
	GPIO.output(relayPin,GPIO.HIGH)
	print"High"
	time.sleep(dly/1000.0)
	GPIO.output(relayPin,GPIO.LOW)
	print "Low"
	time.sleep(dly/1000.0)
	dly-=20
	if dly <100:
		dly=600
GPIO.cleanup()