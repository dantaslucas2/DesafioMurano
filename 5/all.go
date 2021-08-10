package main
import (
	"math/rand"
	"fmt"
)

const n int = 100000000

func main() {
	var numerosAleatorios [n]int 
	min := -50
	max := 50
	for i := 0; i < 10; i++ {
		numerosAleatorios[i] = (rand.Intn(max - min) + min)
		fmt.Println("int: ",numerosAleatorios[i])
	}

	goroutines(&numerosAleatorios,1)
}

func goroutines(numerosAleatorios* [n]int, k int){
	var tamanho int = len(numerosAleatorios)/k
	fmt.Println(tamanho)

	for i := 0; i < k; i++ {
		go soma(numerosAleatorios, tamanho, i)
	}
}

func soma(numerosAleatorios* [n]int, tamanho int, i int){
	
}
