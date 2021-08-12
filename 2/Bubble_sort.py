class Bubble_sort():
    
    def __init__(self, array):
        tamanho = len(array)
        for o in range(tamanho-1):
            for i in range(o):
                if array[i] > array[i+1]:
                    array[i], array[i+1] = array[i+1], array[i]
