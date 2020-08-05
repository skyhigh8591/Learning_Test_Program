#!/home/pi/RPI_IOT/Python
#-*- coding: UTF-8 -*-
import serial
port = "/dev/ttyACM2"

serialFromArduino = serial.Serial(port,9600)

serialFromArduino.flushInput()

while True:
	if(serialFromArduino.inWaiting()>0):
		input = serialFromArduino.readline()
		input_value=int(input) 
		print(input_value)