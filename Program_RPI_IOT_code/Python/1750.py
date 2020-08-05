#!/home/pi/RPI_IOT/Python
#-*- coding: UTF-8 -*-
import smbus
import time

DEVICE				=0x23
POWER_DOWN			=0x00
POWER_ON 			=0x01
RESET				=0x07

CONTINOUS_LOW_RES_MODE=0x13
CONTINOUS_HIGE_RES_MODE_1=0x01
CONTINOUS_HIGE_RES_MODE_2=0x11
ONE_TIME_HIGH_RES_MODE_1=0x20
ONE_TIME_HIGH_RES_MODE_2=0x21
ONE_TIME_LOW_RES_MODE=0x23

bus=smbus.SMBus(1)
def convertToNumber(data)
	return((data[1]+(256*data[0]))/1.2)

def readLight(addr=DEVICE):
	data=bus.read_i2c_block_data(addr,ONE_TIME_HIGH_RES_MODE_1)
	return convertToNumber(data)

def main():
	while True:
		print "Light Level :"+str(readLight())+" 1x"
		time.sleep(1)

if __name__=="__name__":
	main()	