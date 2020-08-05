#! /usr/bin/python
#coding=utf-8

listdata = ['abc',798,2.23,'john',70.2]
tinlist = [123,'jon']

print listdata
print listdata[0]
print listdata[1:3] #三不包含
print listdata[2:]
print listdata *2
print listdata + tinlist

#updata
listdata[2]="aaaa"
print listdata

#delete
del listdata[2]
print listdata

#append
listdata.append("4444")
print listdata

#count
listdata.append("44444")
print.listdata.count("44444")

#sort
listdata.sort()
print listdata