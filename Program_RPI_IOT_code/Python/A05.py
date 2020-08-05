#!/home/pi/RPI_IOT/Python
#-*- coding: UTF-8 -*-
import pyfirmata
import time
board=pyfirmata.Arduino('/dev/ttyACM0')
analog_pin=board.get_pin('a;0:i')
it=pyfirmata.util.Iterator(board)
it.start()
analog_pin.enable_reporting()

while True:
	reading=analog_pin.read()
	if reading!=None
	voltage=reading*5.0
	print("reading=%0.2f\tVoltage=%0.2f"%(reading,voltage))
	time.sleep(1)