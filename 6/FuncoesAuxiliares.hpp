#ifndef __FUNCOESAUXILIARES_H__
#define __FUNCOESAUXILIARES_H__

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <map>
#include <stack>
#include <sstream>
#include "Lista_adjacencia.hpp"
#include "FuncoesAuxiliares.hpp"

using namespace std;

void ShowVetor(string nome, vector<int> vetorShow);
void ShowVetor(string nome, vector<bool> vetorShow);
void ShowVetor(string nome, map<int,int> vetorShow);
void ShowVetor(string nome, vector<ListaAdjacencia> vetorShow);
void ShowVetor(string nome, vector<vector<int>> vetorShow);


int MinimoVector(vector<int> vetor);
int MaximoVector(vector<int> vetor);

vector<int> Split(const string &text, char delimitador=' ');

vector<int> Popular(vector<int> vetorAuxiliar, int ultimoValor, int valorAtual);
vector<bool> Popular(vector<bool> vetorAuxiliar, int ultimoValor, int valorAtual, bool valuePreencher = false);
vector<ListaAdjacencia> Popular(vector<ListaAdjacencia> vetorAuxiliar, int ultimoValor, int valorAtual);

vector<bool> MapeiaIntBool(vector<int> vertices, int sizeVetorMapeado, vector<bool> verticesMapeados);
void EscreveNovoGrafo(vector<pair<int,double>> pai, string filesaida, double custoTotal);
void EscreveNovoGrafo(vector<pair<int,double>> pai, string filesaida, double custoTotal, int verticeInicial, int verticeFinal);
void EscreveNovoGrafo(vector<int> pai, string filesaida, double custoTotal);

bool verticeValido(int vertice);

void inputInterface(string output, int &input);
void inputInterface(string output, vector<string> input, int &opcao);
void inputInterface(string output, bool &valor);
void inputInterface(string output, string &input, string pasta);

#endif