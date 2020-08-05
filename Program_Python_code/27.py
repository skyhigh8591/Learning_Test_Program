#! /usr/bin/python
#coding=utf-8

def multiply(x,y):
	return x*y
def add(x,y):
	return x+y
def minus(x,y):
	return x-y
def divide(x,y):
	x = float(x)
	y = float(y)
	return x/y	
def operation(x,y):
	multiply=x*y
	add=x+y
	minus=x-y
	divide=float(x)/float(y)
	return[multiply,add,minus,divide]



num1 = multiply(2,3)
print "multiply :" + str(num1)

num2 = add(2,3)
print "add :" + str(num2)

num3 = minus(2,3)
print "minus :" + str(num3)

num4 = divide(2,3)
print "divide :" + str(num4)

num = operation(2,3)
for value in num:
	print value

print "operation:" +str(num[0])	
print "operation:" +str(num[1])	
print "operation:" +str(num[2])	
print "operation:" +str(num[3])	
