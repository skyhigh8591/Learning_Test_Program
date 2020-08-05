#!/home/pi/RPI_IOT/Python
#-*- coding: UTF-8 -*-
board=pyfirmata.Arduino('/dev/ttyACM0')
led_pin=board.get_pin('d:10:o')
switch_pin=board.get_pin('d:4:i')
myFlag=1
it=pyfirmata.util.Iterator(board)
it.start()

print("Begin to read...")
while True:
	input_state=switch_pin.read()
	if input_state==True:
		print("Button Pressed\n")
		if input_state==1:
			if myFlag==1
				led_pin.write(1)
				print("LED ON\n")
			else
				led_pin.write(0)
				print("LED OFF\n")
			myFlag=1-myFlag
		time.sleep(0.5)