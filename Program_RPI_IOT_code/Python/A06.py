#!/home/pi/RPI_IOT/Python
#-*- coding: UTF-8 -*-
import pyfirmata
import threading
import time
board=pyfirmata.Arduino('/dev/ttyACM0')
led_pin=board.get_pin('d:13:o')
pwm_pin=board.get_pin('d:10:p')

it=pyfirmata.util.Iterator(board)
it.start()

def led_flash():
	while True:
		led_pin.write(1)
		time.sleep(1)
		led_pin.write(0)
		time.sleep(1)
t1=threading.Thread(target=led_flash)
t1.start()

while True:
	duty_s=raw_input("Enter Brightness(0 to 100):")
	duty=int(duty_s)
	pwm_pin.write(duty/100.0)