# -*- coding: utf-8 -*-
"""
Created on Thu Jun 11 09:11:07 2020

@author: skyhigh
"""


from flask import Flask

app = Flask(__name__)

@app.route('/web1')
def hello():
    return 'This is new web!!'

if __name__ == '__main__' :
#    app.run()
    app.run(host='192.168.43.62',port = 6060)