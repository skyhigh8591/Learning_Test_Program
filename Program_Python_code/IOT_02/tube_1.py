# -*- coding: utf-8 -*-
"""
Created on Mon Jun 15 15:22:07 2020

@author: skyhigh
"""


from pytube import YouTube

yt - YouTube ("https://www.youtube.com/watch?v=cxBZzf8lzqo&list=RDcxBZzf8lzqo&start_radio=1")
print ("start dowmload")
yt.streams.first.dowmload()
print("download OK")