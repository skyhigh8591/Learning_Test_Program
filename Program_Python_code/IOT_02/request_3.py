# -*- coding: utf-8 -*-
"""
Created on Mon Jun 15 14:26:29 2020

@author: skyhigh
"""


import pandas as pd

columns =['matth','english','science']
indexs = ['John','Julia',"Mary","Henry"]
datas=[[80,70,90],[88,87,99],[77,66,76],[90,98,96]]

df = pd.DataFrame(datas,columns=columns,index=indexs)
print(df)
df.plot(kind='bar', title='scors',fontsize=12)
print("////////////////////////////////////")

df.to_csv('out.csv',encoding='utf-8-sig')

df.to_excel('out.xlsx',encoding='utf-8-sig')

df.to_html('out.html',encoding='utf-8')

df.to_json('out.json',force_ascii=False)


data = pd.read_csv('out.csv', encoding='utf-8-sig',index_col=0)
print(data)
print("////////////////////////////////////")

data = pd.read_excel('out.xlsx', encoding='utf-8-sig',index_col=0)
print(data)
print("////////////////////////////////////")

data = pd.read_html('out.html', encoding='utf-8',index_col=0)
print(data)
print("////////////////////////////////////")

data = pd.read_json('out.json')
print(data)
print("////////////////////////////////////")