#! /usr/bin/python
#coding=utf-8

flag = False
name = raw_input("enter your name:")

if(name=="bill"):
	flag = True
	print "Welcome boss"
else: 
	flag = False
	print name
if(flag):
	print "is my family"
else: 
	print "who are you"
