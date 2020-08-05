#! /usr/bin/python
#coding=utf-8

for letter in "python":
	print "current letter",letter

fruits = ["banana","apple","mango"]	

for fruit in fruits:
	print "current letter",fruit

for index in range(len(fruits)):
	print index
	print "current letter",fruit[index]




#########################

for num in range(1,5):
	print num	

print "1~10,num=num+2"
for num in range(1,11,2):
	print num

print "1~10,num=num-2"
for num in range(1,11,-2):
	print num