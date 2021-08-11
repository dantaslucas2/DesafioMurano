package main
import (
	"math/rand"
	"fmt"
	"sync"
)

const n int = 100000

func main() {
	var numerosAleatorios [n]int 
	
	gerarNumerosAleatorios(&numerosAleatorios)

	goroutines(&numerosAleatorios,2) // vetor de números aleatórios, quantidade de threads
}

//--------------------Gera números aleatórios
func gerarNumerosAleatorios (numerosAleatorios* [n]int){
	min := -50
	max := 50
	for i := 0; i < n; i++ {
		numerosAleatorios[i] += (rand.Intn(max - min) + min)
		fmt.Println("int: ",numerosAleatorios[i])
	}
}

//--------------------Cria threads
func goroutines(numerosAleatorios* [n]int, k int){
	var tamanho int = len(numerosAleatorios)/k
	var valorFinal int
	fmt.Println("tamanho = ",tamanho)
	var wg sync.WaitGroup
	var mu sync.Mutex

	for i := 0; i < k; i++ {
		fmt.Println("thread ",i," iniciando")
		wg.Add(1)
		go soma(numerosAleatorios, tamanho, i, &wg, &mu, &valorFinal)
	}

	wg.Wait()
	fmt.Println("Valor total do vetor: ",valorFinal)
}

//--------------------Função onde as threads irão realizar a soma
func soma(numerosAleatorios* [n]int, tamanho int, i int, wg *sync.WaitGroup, mu *sync.Mutex, valorFinal* int){ 
	var total int  

	for o := i*tamanho; o < tamanho*(i + 1); o++ { 
		fmt.Println("thread : ", i ," contando")
		total += numerosAleatorios[o]
	}

	fmt.Println("thread : ",i, " somou : ", total)
	mu.Lock()
		*valorFinal += total
	mu.Unlock()
	defer wg.Done()
}
