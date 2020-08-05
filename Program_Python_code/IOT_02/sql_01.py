# -*- coding: utf-8 -*-
"""
Created on Thu Jun 11 15:08:23 2020

@author: skyhigh
"""


from flask import Flask,request,render_template
from flask_mysqldb import MySQL

app = Flask (__name__)

app.config['MYSQL_HOST'] = 'localhost' 
app.config['MYSQL_USER'] = 'root' 
app.config['MYSQL_PASSWORD'] = '1234' 
app.config['MYSQL_DB'] = 'iot' 
                            
mysql = MySQL(app)

@app.route('/', methods=['GET','POST'])
def index():
    if request.method == 'GET':
        mycursor = mysql.connection.cursor()
        mycursor.execute("SELECT * FROM temperature_db")
        myresult = mycursor.fetchall()
        mycursor.close()
        
        rows=[]
        for row in myresult:
            rows.append(row)
            print(row)
            
        return str(rows)
    
@app.route('/data', methods=['GET','POST'])
def data():
    if request.method == 'GET':
        mycursor = mysql.connection.cursor()
        mycursor.execute("SELECT * FROM temperature_db")
        myresult = mycursor.fetchall()
        mycursor.close()
        
        return render_template('index_5.html',data = myresult)
    

if __name__ == '__main__':
    app.run()