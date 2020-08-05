#!/usr/bin/python
# -*- coding: UTF-8 -*-

i = 1
while i < 10:   
    i += 1
    if i%2 > 0:     # 非雙數時跳過輸出
        continue
    print i         # 輸出雙數2、4、6、8、10

i = 1
while 1:            # 迴圈條件為1必定成立
    print i         # 輸出1~10
    i += 1
    if i > 10:     # 當i大於10時跳出迴圈
        break

