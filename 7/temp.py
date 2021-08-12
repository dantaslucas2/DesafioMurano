# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
import pandas as pd
import numpy as np
import os

tempo = 10

def media_movel(arq, tempo):
    print("Arquivo : ", arq)
    dados = pd.read_csv("./Data/Stocks/"+arq)
    print("dados : ", dados)
    dados = dados.iloc[::-1]
    o = 0
    for (i,row in dados.iterrows()) or (w in range(tempo)):
        print("testando lista invertida : ", row['Close'])
        input("pressione")
        row['Close']
        o+=1


stocks = os.listdir("./Data/Stocks/")

etfs = os.listdir("./Data/ETFs/")

i = 0
while i < len(stocks):
    media_movel(stocks[i], tempo)
    i += 1
    
i = 0
while i < len(etfs):
    media_movel(etfs[i], tempo)
    i += 1


input("pressione")
acoes = pd.read_csv("./Data/Stocks/a.us.txt")

fundos = pd.read_csv("./Data/ETFs/aadr.us.txt")

print(acoes)

print(fundos)



