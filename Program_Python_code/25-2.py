#!/usr/bin/python
#coding=utf-8
#字典創建 while開關 字典添加 字典尋找
dictionary = {}
flag = 'a'
pape = 'a'
off = 'a'
while flag == 'a' or 'c' :
    flag = raw_input("添加或查找单词 ?(a/c)")
    if flag == "a" :                             #開啟
        word = raw_input("輸入單詞(key):")
        defintion = raw_input("輸入定義值(value):")
        dictionary[str(word)] = str(defintion)  # 添加字典
        print "添加成功!"
        pape = raw_input("您是否要查找字典?(a/0)")   #read
        if pape == 'a':
            print dictionary
        else :
            continue
    elif flag == 'c':
        check_word = raw_input("要查找的單詞:")  # 檢索
        for key in sorted(dictionary.keys()):            # yes
            if str(check_word) == key:
                print "該單詞存在! " ,key, dictionary[key]
                break
            else:                                       # no
                off = 'b'
        if off == 'b':
            print "抱歉，該值不存在！"
    else:                               # 停止
        print "error type"
        break

