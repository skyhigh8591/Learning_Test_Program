#!/home/pi/RPI_IOT/Python
#-*- coding: UTF-8 -*-
import pyfirmata
import time
board=pyfirmata.Arduino('/dev/ttyACM0')
led_pin=board.get_pin('d:13:o')
it=pyfirmata.util.Iterator(board)
it.start()

while True:
	led_pin.write(1)
	print("LED ON\n")
	time.sleep(1)
	led_pin.write(0)
	print("LED OFF\n")
	time.sleep(1)