# -*- coding: utf-8 -*-
"""
Created on Thu Jun 11 09:10:14 2020

@author: mac305
"""

from flask import Flask,request,render_template,redirect,url_for,flash

app = Flask(__name__)

@app.route('/')
def hello_1():
    return 'This is new world!'

@app.route('/login',methods=['GET','POST'])
def login():
    if request.method == 'POST':
        if login_check(request.values['username'], request.values['password']):
#            flash('Login OK')
            return redirect(url_for('hello', username=request.values['username'])) 
        else :
#            flash('Login failed')
#            return render_template('index4.html')
            return "input error !"
    
    if request.method == 'GET':
        return render_template('index4.html')
        
def login_check(username,password):
    if username == 'David' and password == '1234':
        return True
    else :
        return False

@app.route('/hello/<username>')
def hello(username):
      return render_template('index2.html',user_template = username) 
        
if __name__ == '__main__':
#    app.run()
    app.secret_key = 'abc'
#    app.run(host='192.168.58.128',port=6060)
    app.run()