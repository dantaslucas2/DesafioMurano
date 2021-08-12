class Quick_sort():

    def __init__(self, array):
        self.quick_sort(array)

    def quick_sort(self, array):
        tamanho = len(array)
        self.quick_recursivo(array,0,tamanho-1)

    def quick_recursivo(self, array,primeiro_elemento,ultimo_elemento):
        if primeiro_elemento<ultimo_elemento:
            splitpoint = self.partition(array,primeiro_elemento,ultimo_elemento)
            self.quick_recursivo(array,primeiro_elemento,splitpoint-1)
            self.quick_recursivo(array,splitpoint+1,ultimo_elemento)

    def partition(self, array,primeiro_elemento,ultimo_elemento):
        pivot = array[primeiro_elemento]
        done = False

        marador_esquerdo = primeiro_elemento+1
        marador_direito = ultimo_elemento

        while not done:
            while ((marador_esquerdo <= marador_direito) and (array[marador_esquerdo] <= pivot)): marador_esquerdo = marador_esquerdo + 1

            while ((array[marador_direito] >= pivot) and (marador_direito >= marador_esquerdo)):marador_direito = marador_direito -1

            if (marador_direito < marador_esquerdo): done = True
            else:
                array[marador_esquerdo], array[marador_direito] = array[marador_direito], array[marador_esquerdo]

        array[primeiro_elemento], array[marador_direito] = array[marador_direito], array[primeiro_elemento]

        return marador_direito
pass