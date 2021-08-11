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
#include "Grafo.hpp" //precisa editar makefile para incluir essa biblioteca
#include "Lista_adjacencia.hpp"

using namespace std;

void ShowVetor(string nome, vector<int> vetorShow){
    
    cout<<nome<<endl;

    for (int i = 0; i < vetorShow.size(); i++){
        cout <<i<<":"<< vetorShow.at(i) << endl;
    }
}

void ShowVetor(string nome, vector<vector<int>> vetorShow){
    
    cout<<nome<<endl;

    for (int i = 0; i < vetorShow.size(); i++){
        cout<<"cc "<<i<<"|";
        for(int sub=0; sub<vetorShow.at(i).size(); sub++)
        {
            cout <<sub<<":"<< vetorShow.at(i).at(sub);
        }
        cout<<endl;
    }
}

void ShowVetor(string nome, vector<bool> vetorShow){
    
    cout<<nome<<endl;

    for (int i = 0; i < vetorShow.size(); i++){
        cout <<i<<":"<< vetorShow.at(i) << endl;
    }
}

void ShowVetor(string nome, map<int,int> vetorShow){
    
    cout<<nome<<endl;
    for (int i = 0; i < vetorShow.size(); i++){
        auto value = vetorShow.find(i+1);
        cout <<i+1<<":"<< value->second << '\n';
    }
}

void ShowVetor(string nome, vector<ListaAdjacencia> vetorShow){
    
    cout<<nome<<endl;

    for (int i = 0; i < vetorShow.size(); i++){
        cout<<i<<endl;
        vetorShow.at(i).show();
        cout<<endl;
    }
}


int MaximoVector(vector<int> vetor){
    int maximo=0;

    for (int i = 0; i < vetor.size(); i++){
        if(vetor.at(i)>maximo){
            maximo = vetor.at(i);
        }
    }
    return maximo;
}

int MinimoVector(vector<int> vetor){
    int minimo=vetor.at(0);

    for (int i = 0; i < vetor.size(); i++){
        if(vetor.at(i)<minimo){
            minimo = vetor.at(i);
        }
    }

    return minimo;
}

vector<int> Split (const string &text, char delimitador) {
    vector<int> result;
    stringstream ss (text);
    string item;

    while (getline (ss, item, delimitador)) {
        int vertice;
        vertice=stoi(item);
        result.push_back(vertice);
    }

    return result; // vector<int>
}   

vector<int> Popular(vector<int> vetorAuxiliar, int ultimoValor, int valorAtual){
    vetorAuxiliar.reserve(vetorAuxiliar.size()+valorAtual);
    for (int i = ultimoValor; i < valorAtual+1; i++)
    {
        vetorAuxiliar.push_back(0);
    }
    return vetorAuxiliar;
}

vector<bool> Popular(vector<bool> vetorAuxiliar, int ultimoValor, int valorAtual, bool valuePreencher){
    vetorAuxiliar.reserve(vetorAuxiliar.size()+valorAtual);

    for (int i = ultimoValor; i < valorAtual+1; i++)
    {
        vetorAuxiliar.push_back(valuePreencher);
    }
    return vetorAuxiliar;
}

vector<ListaAdjacencia> Popular(vector<ListaAdjacencia> vetorAuxiliar, int ultimoValor, int valorAtual){
    vetorAuxiliar.reserve(vetorAuxiliar.size()+valorAtual);

    for (int i = ultimoValor; i < valorAtual+1; i++)
    {
        ListaAdjacencia listaAuxiliar;
        vetorAuxiliar.push_back(listaAuxiliar);
    }
    return vetorAuxiliar;
}



vector<bool> MapeiaIntBool(vector<int> vertices, int sizeVetorMapeado, vector<bool> verticesMapeados){

    for(int i=0; i<vertices.size(); i++){
        verticesMapeados.at(vertices.at(i)) = true;
    }
    return verticesMapeados;
}


void EscreveNovoGrafo(vector<pair<int,double>> pai, string filesaida, double custoTotal){

    const char * filenameChar = filesaida.c_str();
    ofstream arquivoCC (filenameChar);
    int valueDois;
    double pesoAresta;

    if (arquivoCC.is_open())
    {

        arquivoCC<<pai.size()-1<<endl;

        for(int valueUm=1; valueUm<pai.size(); valueUm++){
            
            valueDois=pai.at(valueUm).first;
            pesoAresta=pai.at(valueUm).second;
            if(valueDois!=-1){
                arquivoCC<<valueUm<<" "<<valueDois<<" "<<pesoAresta<<endl;
            }

        }
        
        arquivoCC<<"Custo Total: "<<custoTotal<<endl;
    }else{
        cout << "Erro ao criar arquivo de Saída."<<endl;        
    }
    arquivoCC.close();
}

void EscreveNovoGrafo(vector<pair<int,double>> pai, string filesaida, double custoTotal, int verticeInicial, int verticeFinal){

    const char * filenameChar = filesaida.c_str();
    ofstream arquivoCC (filenameChar);
    int valueDois, paiAtual;
    double pesoAresta, pesoAtual;
    vector<pair<int,double>> pathReverse;

    if (arquivoCC.is_open())
    {

        arquivoCC<<pai.size()-1<<endl;

        for(int valueUm=1; valueUm<pai.size(); valueUm++){
            
            valueDois=pai.at(valueUm).first;
            pesoAresta=pai.at(valueUm).second;
            if(valueDois!=-1){
                arquivoCC<<valueUm<<" "<<valueDois<<" "<<pesoAresta<<endl;
            }

        }
      
        arquivoCC<<"Comprimento do caminho: "<<custoTotal<<endl;
        cout<<"Comprimento do caminho: "<<custoTotal<<endl;

        paiAtual = verticeFinal;
        pesoAtual = pai.at(paiAtual).second; //peso até o pai
        while(paiAtual!= verticeInicial){
            pathReverse.push_back({paiAtual, pesoAtual});
            pesoAtual = pai.at(paiAtual).second;
            paiAtual = pai.at(paiAtual).first;
        }
        pathReverse.push_back({paiAtual, pesoAtual});

        arquivoCC<<"Descrição do caminho: ";
        cout<<"[";
        for(int i=(pathReverse.size()-1); i>=0; i--){
            arquivoCC<<pathReverse.at(i).first;
            cout<<pathReverse.at(i).first;
            if(i>0) {arquivoCC<<"--"<<pathReverse.at(i).second<<"-->"; cout<<",";}
        }
        cout<<"]"<<endl;

    }else{
        cout << "Erro ao criar arquivo de Saída."<<endl;        
    }
    arquivoCC.close();
}

void EscreveNovoGrafo(vector<int> pai, string filesaida, double custoTotal){

    const char * filenameChar = filesaida.c_str();
    ofstream arquivoCC (filenameChar);
    int valueDois;

    if (arquivoCC.is_open())
    {

        arquivoCC<<pai.size()-1<<endl;

        for(int valueUm=1; valueUm<pai.size(); valueUm++){
            
            valueDois=pai.at(valueUm);
            if(valueDois!=-1){
                arquivoCC<<valueUm<<" "<<valueDois<<endl;
            }

        }
        
        arquivoCC<<"Custo Total: "<<custoTotal<<endl;
    }else{
        cout << "Erro ao criar arquivo de Saída."<<endl;        
    }
    arquivoCC.close();
}

bool verticeValido(int vertice){

    if(vertice>0)
        return true;
    return false;
}

void inputInterface(string output, int &input){
    cout<<output;
    cin>>input;
    cout<<endl;
    while (!verticeValido(input)){
        cout<<"Digite um valor válido"<<endl;
        cout<<output;
        cin>>input;
        cout<<endl;

    }    
}


void inputInterface(string output, vector<string> input, int &opcao){

    cout<<output;
    cout<<endl;

    for(int i=0; i<input.size(); i++){
        cout<<i+1<<": "<<input.at(i)<<endl;;
    }

    cout<<endl;
    inputInterface("Qual a opção escolhida? ", opcao);
}

void inputInterface(string output, bool &valor){

    string input;

    cout<<output;
    cin>>input;

    if(input=="Sim" || input=="S" ) valor=true;
    else if(input=="Nao" || input=="N" ) valor=false;
    else{
        while(input!="Sim" && input!="S" && input!="Nao" && input!="N" ){
            cout<<"O valor digitado não é válido. Digite novamente:"<<endl;
            cout<<output;
            cin>>input;
        }
    }
}

void inputInterface(string output, string &input, string pasta){

    string nameFile;

    cout<<output;
    cin>>nameFile;
    input = "./"+pasta+"/"+nameFile+".txt";;
    cout<<endl;
}