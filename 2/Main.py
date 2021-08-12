import random
import time
from Quick_sort import Quick_sort
from Bubble_sort import Bubble_sort
from Merge_sort import Merge_sort

dimensao = 10

array = []

x = random.randint(1,dimensao)

for i in range(dimensao):
    array.append(random.randint(1,dimensao))

print(array)
input("clique")
inicio = time.time()
Merge_sort(array)
fim = time.time()
print(array)
print("tempo de execução quick sorrt: ",fim-inicio)


