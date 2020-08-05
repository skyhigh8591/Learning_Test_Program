#!/usr/bin/python
# -*- coding: UTF-8 -*-

tuple = ( 'abcd', 786 , 2.23, 'john', 70.2 )
tinytuple = (123, 'john')

print tuple # 輸出完整元組
print tuple[0] # 輸出元組的第一個元素
print tuple[1:3] # 輸出第二個至第三個的元素
print tuple[2:] # 輸出從第三個開始至列表末尾的所有元素
print tinytuple * 2 # 輸出元組兩次
print tuple + tinytuple # 打印組合的元組

