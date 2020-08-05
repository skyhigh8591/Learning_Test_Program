#! /usr/bin/python
#coding=utf-8


#10~20質數


while(True):
    num = raw_input("enter your number:")
    num = int(num)

    for i in range(2,num):
        if (num%i==0):
            j=num/i
            print '%d 等於 %d * %d' %(num,i,j)
            print '不是質數'
            break
    else:
        print num, '是質數'







