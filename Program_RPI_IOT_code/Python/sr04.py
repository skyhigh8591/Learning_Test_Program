#!/usr/bin/python
# -*- coding: UTF-8 -*-
import RPi.GPIO as GPIO
import time
trigPin=13
echoPin=15

GPIO.setmode(GPIO.BOARD)
GPIO.setup(trigPin,GPIO.OUT)
GPIO.setup(echoPin,GPIO.IN)

def getDistance():
	GPIO.output(trigPin,False)
	print "Waiting for sensor to settle"
	time.sleep(2)
	GPIO.output(trigPin,True)
	time.sleep(0.00001)
	GPIO.output(trigPin,False)
	while GPIO.input(echoPin)==0:
		pulse_start=time.time()
	while GPIO.input(echoPin)==1:
		pulse_end=time.time()		
	pulse_duration=pulse_end-pulse_start
	distance=pulse_duration*17150
	distance=round(distance,2)
	return distance
while True:
	print "distance: ",getDistance(), " cm"
	time.sleep(1)

GPIO.cleanup()