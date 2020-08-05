#! /usr/bin/python
#coding=utf-8

import time,datetime
from time import strftime

temperature_file = file("Temp.txt","w")

for num in range(5):
	now = strftime("%H:%M:%S")
	#print now
	file = open("/sys/bus/w1/devices/28-031681faeeff/w1_slave")
	text = file.read()
	#print text
	secondline=text.split("\n")[1]
	#print secondline
	tempdata=secondline.split(" ")[9]
	#print tempdata
	temp = float(tempdata[2:])
	temp=temp/1000
	#print temp
	print "現在時間" + now + "攝氏溫度" + str(temp)
	temperature_file.write(str(now)+"	"+str(temp))
	temperature_file.write("\n")
	time.sleep(1)

temperature_file.close()	
