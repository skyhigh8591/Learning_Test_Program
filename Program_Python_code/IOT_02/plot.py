# -*- coding: utf-8 -*-
"""
Created on Mon Jun 15 14:47:23 2020

@author: skyhigh
"""


import matplotlib.pyplot as plt

listx1 = [1,5,7,9,13,16]
listy1 = [15,50,80,40,70,50]
plt.plot(listx1,listy1,color="red",ls = "--" , label='male')

listx2 = [2,6,8,11,14,16]
listy2 = [10,40,30,50,80,60]
plt.plot(listx2,listy2,label = 'female')
plt.title("Data")
plt.xlabel("age")
plt.ylabel("money")


plt.show()

labels = ["east","south","north","west"]
sizes = [5,10,20,15]
colors = ["red","green","blue","yellow"]
explode = (0,0,0.05,0)
plt.pie(sizes,explode=explode,labels = labels,colors = colors,labeldistance=1.1,autopct="%3.1f%%,\
        shadow=True",startangle = 90 , pctdistance = 0.6)
plt.axis("equal")
plt.legend()
plt.show
