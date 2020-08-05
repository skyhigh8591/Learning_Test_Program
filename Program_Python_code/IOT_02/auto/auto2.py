# -*- coding: utf-8 -*-
"""
Created on Fri Jun 19 11:14:04 2020

@author: skyhigh
"""


from selenium import webdriver
import requests

url = 'https://zh-tw.facebook.com/'
html = requests.get(url)
html.encoding="utf-8"
print(html.text)

driver = webdriver.Chrome()
driver.get(url)

driver.find_element_by_id('email').send_keys()
driver.find_element_by_id('pass').send_keys()
driver.find_element_by_id('loginbutton').clicl()