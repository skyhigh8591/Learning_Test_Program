#! /usr/bin/python
#coding=utf-8

#1+2+3+4+5

num = raw_input("enter your number")
num = int(num)

count = 0
i=0
while(i<num):
    i=i+1
    print "The number is:", i
    count = count + i

print "the total is:", count

