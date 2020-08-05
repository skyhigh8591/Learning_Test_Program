# -*- coding: utf-8 -*-
"""
Created on Thu Jun 11 09:10:14 2020

@author: mac305
"""

from flask import Flask, request
from flask import render_template

app=Flask(__name__)

@app.route('/')
def index():
    return 'this is new web'

@app.route('/login', methods=['GET','POST'])
def login():
    if request.method == 'POST':
        return  'user name= '+request.values['username']
    
    if request.method == 'GET':
        return  render_template('index_3.html')
    
@app.route('/login_1', methods=['GET','POST'])
def login_1():
    if request.method == 'POST':
        return  'user name= '+request.values['firstname']+'-'+request.values['lastname']

    if request.method == 'GET':
        return  render_template('index_3.html')
    

if __name__=='__main__':
#    app.run()                   # http://localhost:5000/
    app.run(host='192.168.1.27',port=6060) #http://192.168.58.109:6060/web1