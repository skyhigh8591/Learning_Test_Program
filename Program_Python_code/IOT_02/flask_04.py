# -*- coding: utf-8 -*-
"""
Created on Thu Jun 11 13:59:24 2020

@author: skyhigh
"""



from flask import Flask,request,render_template,redirect,url_for,flash

app = Flask(__name__)

@app.route('/web1')
def hello_1():
    return 'This is new web'

@app.route('/login', methods=['GET','POST'])
def login():
    if request.method =='POST':
        if login_check(request.valuse['username'], request.values['password']):
            flash('login OK')
        else:
            flash('login fail')
        return redirect(url_for('hello', username=request.values['username']))
    if request.method=='GET':
        return render_template('index_04.html')

def login_check(username,password):
    if username == 'julia' and password == '1234':
        return True
    else:
        return False
 
@app.route('/hello/<username>')
def hell(username):
    return render_template('index_02.html',user_template = username)      
        
if __name__ == '__main__' :
    #    app.run()
    app.secret_key='abc'
    app.run(host='192.168.43.62',port = 6060)