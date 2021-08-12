# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
import pandas as pd
import numpy as np
import os

tempo = 10
var_media_movel = []

def media_movel(arquivo, dados, tempo):
    dados = dados.iloc[::-1]
    o = 0
    
    total = 0
    for i,row in dados.iterrows():

        total += row['Close']
        if o >= tempo:
            row['Close']
            break
        o+=1
    
    var_media_movel.append([arquivo,total / tempo])
    


stocks = os.listdir("./Data/Stocks/")

etfs = os.listdir("./Data/ETFs/")

i = 0
while i < len(stocks):
    print("arquivo", i)
    dados = pd.read_csv("./Data/Stocks/"+stocks[i])
    media_movel(stocks[i], dados, tempo)
    i += 1
    
i = 0

while i < len(etfs):
    media_movel(etfs[i], tempo)
    i += 1

print("Media Movel Simples de todas ações e ETFs : ", var_media_movel)

input("pressione")


