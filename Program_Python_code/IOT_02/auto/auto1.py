# -*- coding: utf-8 -*-
"""
Created on Fri Jun 19 09:50:58 2020

@author: mac305
"""

from selenium import webdriver
import requests
from bs4 import BeautifulSoup

driver = webdriver.Chrome()

#driver.get('https://tw.yahoo.com')
#driver.quit()

driver.get("http://localhost:5000/login")

data = driver.page_source
print(data)

username_1 = "john"
password_1 = "abcd"

driver.find_element_by_name('username').send_keys(username_1)
driver.find_element_by_name('password').send_keys(password_1)
driver.find_element_by_id('send').click()


driver.get("http://localhost:5000/login")


username_ok = "David"
password_ok = "1234"

driver.find_element_by_name('username').send_keys(username_ok)
driver.find_element_by_name('password').send_keys(password_ok)
driver.find_element_by_id('send').click()

url = "http://localhost:5000/hello/David"
html = requests.get(url)
html.encoding = "utf-8"
if html.status_code == requests.codes.ok:
    print(html.text)
    sp = BeautifulSoup(html.text,'html.parser')
    print (sp.title.string)
    print (sp.p.string)
    result = sp.find_all('p')
    
    for data in result:
        print(data)
        if str(data).find('David') != -1 :
            print("test ok")
    

