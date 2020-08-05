#!/usr/bin/python
# -*- coding: UTF-8 -*-

import urllib
import time, datetime
from time import strftime


def fetch_thing(url,params,method):
	params =urllib.urlencode(params)
	#print parama
	if method=="GET":
		f=urllib.urlencode(url+"?"+params)
	else:
		f=urllib.urlopen(url,params)
	return(f.read())

now = strftime("%H:%M:%S")
#print now
file = open("/sys/bus/w1/devices/28-03168201f2ff/w1_slave")
text = file.read()
file.close()
#print text

secondline = text.split("\n")[1]
#print secondline
tempdata=secondline.split(" ")[9]
#print tempdata

temp=float(tempdata[2:])
temp=temp/1000

print "現在時間:"+now+" 攝氏="+str(temp)




content=fetch_thing(
	"http://192.168.63.119:8080/code/post_api.php",
	{"userid":51,"temperature":temp},
	"POST"
	)
