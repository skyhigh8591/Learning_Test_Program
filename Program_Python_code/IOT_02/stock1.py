# -*- coding: utf-8 -*-
"""
Created on Fri Jun 19 08:37:49 2020

@author: mac305
"""

import twstock
from  twstock import Stock,realtime,BestFourPoint
import matplotlib.pyplot as plt
import pandas as pd


tsmcInfo = twstock.codes['2330']
print(tsmcInfo)

tsmc_name = tsmcInfo.name
print(tsmc_name)

tsmc_group=tsmcInfo.group
print(tsmc_group)

print(tsmcInfo.start)

#------------------------------------
stock_2330 =Stock('2330')
print(stock_2330)

price_list =stock_2330.price
print("price list:",price_list)

print("capacity = :",stock_2330.capacity)

print("turnover = :",stock_2330.turnover)
print("transaction = :",stock_2330.transaction)

print("transaction date = :",stock_2330.date)

data_list = stock_2330.data[0]
print ("data = ",data_list)

price = stock_2330.price[-5:]
print("price =",price )
high =stock_2330.high[-5:]
print("high=" ,high)

low=stock_2330.price[-5:]
print("low = ",low)

date=stock_2330.date[-5:]
print("date = ",date)

stock_2330_2020 =stock_2330.fetch_from(2020,1)
stock2020=pd.DataFrame(stock_2330_2020)
stock2020_pd=stock2020.set_index('date')

fig = plt.figure(figsize=(10,6))
plt.plot(stock2020_pd.close,'-',label="close price")
plt.plot(stock2020_pd.open,'-',label="open price")

plt.title("TSMC open/close price", loc='right')
plt.xlabel('date')
plt.ylabel('price')
plt.grid(True,axis='y')
plt.legend()
fig.savefig('year2020_1.png')


#-------------------------------
#best comment
bfp=BestFourPoint(stock_2330)
print("best point to buy =",bfp.best_four_point_to_buy())
print("best point to sell =",bfp.best_four_point_to_sell())

print("comment=",bfp.best_four_point())

ma_p=stock_2330.moving_average(stock_2330.price,5)
print("5 day average =",ma_p)

ma_c=stock_2330.moving_average(stock_2330.capacity,5)
print("5 day capacity =",ma_c)




#---------------------
rt_2330 = realtime.get('2330')
print("real time data = ",rt_2330)

print(type(rt_2330))

rt_2330_info=rt_2330['info']
print("tsmc info:",rt_2330_info)

print("price time :",rt_2330_info['time'])

rt_2330_realtime=rt_2330['realtime']
print("tsmc real time : ",rt_2330_realtime)

print("Latest_trade_price = ", rt_2330_realtime['latest_trade_price'])

print("best_bid_price = ", rt_2330_realtime['best_bid_price'])

print("best_ask_price = ", rt_2330_realtime['best_ask_price'])

print("if data success ?", rt_2330['success'])









