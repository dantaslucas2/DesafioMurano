#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "Lista_adjacencia.hpp"
#include "Estrutura_de_dados.hpp"
#include "FuncoesAuxiliares.hpp"

using namespace std;

class Grafo
{   

    public:

    int numberNodes;
    int numberArestas;
    int entradaOk;
    vector<bool> hasNode;
    map<int, int> graus;
    bool peso;
    bool valueNegativo = false;

    //1- lista 2-vetor 3-matriz
    int estruturaEscolhida;
    EstruturaDeDados *estruturaGrafo;   
  
    //TP1
    Grafo(string caminho, bool newPeso);
    void Entrada(string fileEntrada);

    void Saida(string fileSaida="./Resultados/Saida.txt");
    vector<vector<int>> BFS(int raiz);
    vector<vector<int>> DFS(int raiz);
    int Grau(int vertice);
    double Distancia(int nodeUm, int nodeDois, string file); //alterado para aceitar peso
    void Diametro();
    vector<vector<int>> ComponentesConexas(string filesaida="./Resultados/ComponentesConexas.txt");
    bool MesmaComponente(int nodeUm, int nodeDois);

    //TP2
    pair<double, vector<double>> Dijkstra(int nodeUm, int nodeDois, string filesaida="./Resultados/Dijkstra.txt"); //caminho mínimo
    void MST(int inicio=1, string filesaida="./Resultados/MST.txt"); //escrita no formato de grafo em um arquivo de saída
    double Excentricidade(int nodeUm);

};