#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <map>
#include <stack>
#include <sstream>
#include <string>
#include <time.h>
#include <dirent.h>
#include <random>
#include <stdlib.h>
#include "Grafo.hpp"
#include "FuncoesAuxiliares.hpp"
#include "Estrutura_de_dados.hpp"
#include "Lista_adjacencia.hpp"

int main(){


    Grafo grafo("grafo_W_1.txt",true);
    grafo.Dijkstra(10,20,"ResultadoDijkstra.txt");


}
