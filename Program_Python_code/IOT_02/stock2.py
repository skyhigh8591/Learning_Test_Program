# -*- coding: utf-8 -*-
"""
Created on Fri Jun 19 09:11:33 2020

@author: mac305
"""

import pandas_datareader as pdr

startTime = '2020-01-01'
endTime = '2020-06-15'
df_2330 = pdr.DataReader('2330.TW','yahoo',startTime,endTime)
print(df_2330)

data_low = df_2330['Low']
data_low.plot()

data_high = df_2330['High']
data_high.plot()

data_close = df_2330['Close']
data_close.plot(color="red")

