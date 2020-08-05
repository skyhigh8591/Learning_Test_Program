# -*- coding: utf-8 -*-
"""
Created on Mon Jun 15 10:42:03 2020

@author: skyhigh
"""


from flask import Flask,request,render_template
from flask_mysqldb import MySQL
import datetime

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
    
@app.route('/insert', methods=['GET','POST'])  
def insert_data():
    if request.method == 'POST':
        userid = request.values['userid']
        temperature=request.values['temperature']
        mycursor =  mysql.connection.cursor()
        time = datetime.datetime.now()
        print(time)
        currenttime = time.strftime('%Y-%m-%d %H:%M:%S')
        print(currenttime)
        
        sql = "INSERT INTO temperature_db(userid,temperature,datetime)VALUES( %s,%s,%s)"
        value = (userid,temperature,currenttime)
        mycursor.execute(sql,value)
        mysql.connection.commit()
        count=mycursor.rowcount
        print(count)
        mycursor.close()
        if count > 0:
            result = str(count)+"insert data ok"
            return render_template('index_6.html', insert_result=result)
        else:
            return "insert data ok"
        
    if request.method == 'GET':
        return render_template('index_6.html')
        
@app.route('/update', methods=['GET','POST'])  
def update_data():
    if request.method == 'POST':
        userid = request.values['userid_update']
        temperature = request.values['temperature_update']
        mycursor =  mysql.connection.cursor()
        sql = "UPDATE temperature_db SET temperature = %s WHERE userid = %s"
        value = (temperature,userid)
        mycursor.execute(sql,value)
        mysql.connection.commit()
        count=mycursor.rowcount
        print(count)
        mycursor.close()
        if count > 0:
            result = str(count) +"update data ok"
            return render_template('index_7.html', update_result = result)
        else:
            return "update data fail"
        
    if request.method == 'GET':
        return render_template('index_7.html')
    
@app.route('/delete', methods=['GET','POST'])  
def delete_data():
    if request.method == 'POST':
        userid = request.values['userid_delete']
        mycursor =  mysql.connection.cursor()
        sql = "DELETE FROM temperature_db WHERE userid = %s "
        value = (userid,)
        mycursor.execute(sql,value)
        mysql.connection.commit()
        count=mycursor.rowcount
        print(count)
        mycursor.close()
        if count > 0:
            result = str(count) +"delete data ok"
            return render_template('index_8.html', delete_result = result)
        else:
            return "delete data fail"
    if request.method == 'GET':
        return render_template('index_8.html')


if __name__ == '__main__':
    app.run()