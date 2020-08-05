#!/usr/bin/python
# -*- coding: UTF-8 -*-

# 例2：elif用法

num = raw_input("enter your name:")
num = int(num)
if (num == 3) or (num == 4): # 判斷num的值
   print 'boss'
elif num == 2:
   print 'user'
elif num == 1:
   print 'worker'
elif num < 0: # 值小於零時輸出
   print 'error'
else:
   print 'roadman' # 條件均不成立時輸出

