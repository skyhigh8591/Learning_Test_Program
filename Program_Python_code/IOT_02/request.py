# -*- coding: utf-8 -*-
"""
Created on Mon Jun 15 13:25:43 2020

@author: skyhigh
"""


import requests

url_1 = 'http://192.168.43.62:6060/login'
html = requests.get(url_1)
html.encoding='utf-8'
if html.status_code == requests.codes.ok:
    print("ok")
    
url_1 = 'http://192.168.43.62:6060/web1'
html = requests.get(url_1)
html.encoding='utf-8'
if html.status_code == requests.codes.ok:
    print(html.text)
    
payload = {'username' : 'julia'}
url_1 = 'http://192.168.43.62:6060/login'
html = requests.post(url_1)
html.encoding='utf-8'
if html.status_code == requests.codes.ok:
    print(html.text)
    
url_1 = 'https://www.cwb.gov.tw/V8/C/'
html = requests.get(url_1)
html.encoding='utf-8'
if html.status_code == requests.codes.ok:
    print(html.text)