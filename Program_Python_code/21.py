#! /usr/bin/python
#coding=utf-8

#10~20 質數
for num in range(10,21):
	#print num
	for i in range(2,num/2+1):
		if num%i==0:
			j=num/i
			print "%d等於 %d * %d" % (num,i,j)
			break
		else:
			print num,"是一個質數"	