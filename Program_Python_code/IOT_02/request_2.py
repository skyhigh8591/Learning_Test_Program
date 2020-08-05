# -*- coding: utf-8 -*-
"""
Created on Mon Jun 15 13:52:25 2020

@author: skyhigh
"""


import requests
from bs4 import BeautifulSoup

url_1 = 'http://192.168.1.27:6060/login'
html = requests.get(url_1)
html.encoding='utf-8'
if html.status_code == requests.codes.ok:
    print("ok")
    print("//////////////////////////////")
    
sp = BeautifulSoup(html.text,'html.parser')

data = sp.title
print(data)
print("//////////////////////////////")

data = sp.h1
print(data)
print("//////////////////////////////")

data=sp.button
print(data)
print("//////////////////////////////")

data = sp.find('h1')
print(data)
print("//////////////////////////////")

data = sp.find_all('input',{'id':'Lname'})
print(data)
print("//////////////////////////////")