#! /usr/bin/python
#coding=utf-8


#10~20質數


while(True):
    num = input("enter your number:")
    #num = int(num)

    i=2
    while(i<num):
        if (num%i==0):
            j=num/i
            print '%d 等於 %d * %d' %(num,i,j)
            print '不是質數'
            break
        i=i+1
    else:
        print num, '是質數'







