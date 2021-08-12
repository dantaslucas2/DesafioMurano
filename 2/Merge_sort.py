class Merge_sort():
    
    def __init__(self, array):
        print("Entrou no merge init")
        self.merge_sort_recursivo(array, 0, len(array))

    def merge_sort_recursivo(self, array, esquerda, direita):
        print("Entrou no merge recursivo")
        print("esquerda : ", esquerda, "direita : ", direita)

        if((direita - esquerda) > 1):
            meio = (direita + esquerda) // 2
            self.merge_sort_recursivo(array, esquerda, meio)
            self.merge_sort_recursivo(array, meio, direita)
            self.merge(array, esquerda, meio, direita)

    def merge(self, array, esquerda, meio, direita):
        p_esquerda = 0
        p_direita =  0
        left = array[esquerda:meio]
        right = array[meio:direita]
        for o in range(esquerda, direita):

            if p_esquerda >= len(left):
                array[o] = right[p_direita]
                p_direita = p_direita + 1

            elif p_direita >= len(right):
                array[o] = left[p_esquerda]
                p_esquerda = p_esquerda + 1

            elif left[p_esquerda] < right[p_direita]:
                array[o] = left[p_esquerda]
                p_esquerda = p_esquerda + 1

            else:
                array[o] = right[p_direita]
                p_direita = p_direita + 1

