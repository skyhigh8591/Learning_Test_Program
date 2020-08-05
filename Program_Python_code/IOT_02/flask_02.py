# -*- coding: utf-8 -*-
"""
Created on Thu Jun 11 10:27:55 2020

@author: skyhigh
"""

from flask import Flask
from flask import render_template

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/web1')
def hello():
    return render_template('index_1.html')

@app.route('/web2/<username>')
def name(username):
    return 'my name is : ' +username

@app.route('/web3/<int:number>')
def page(number):
    return 'this is page ' + str(number)

if __name__ == '__main__' :
#    app.run()
    app.run(host='192.168.43.62',port = 6060)