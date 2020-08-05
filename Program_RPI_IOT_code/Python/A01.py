#!/home/pi/RPI_IOT/Python
#-*- coding: UTF-8 -*-
import serial
port = "/dev/ttyACM1"

serialFromArduino = serial.Serial(port,9600)

serialFromArduino.flushInput()

while True:
	if(serialFromArduino,inWaiting()>0):
		input - serialFromArduino.read(1)
		print(ord(input))