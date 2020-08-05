#! /usr/bin/python
#coding=utf-8

import urllib
import time,datetime
from time import strftime

def fetch_thing(url,params,method):
	params = urllib.urlencode(params)
	#print params
	if method=="GET":
		f=urllib.urlopen(url+"?"+params)
	return(f.read())	

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

content = fetch_thing(
	"http://192.168.58.174:8080/php_code/get_api.php",
	{"userid":50,"temperature":temp},
	"GET")
