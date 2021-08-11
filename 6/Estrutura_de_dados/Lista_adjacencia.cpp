#include <iostream>
#include "Lista_adjacencia.hpp"
#include "Estrutura_de_dados.hpp"
//#include "../FuncoesAuxiliares.hpp"

using namespace std;

NodeList::NodeList(int dataa){
    this->next = NULL;
    this->data = dataa;
    weight = 0;
}

NodeList::NodeList(int dataa, double newWeight){
    this->next = NULL;
    this->data = dataa;
    weight = newWeight;
}

void NodeList::set(int i){
    this->data = i;
}

int NodeList::get(){
    return data;
}

NodeList* NodeList::get_next(){
    return next;
}

void NodeList::add(NodeList* data){
    next = data;
}

ListaAdjacencia::ListaAdjacencia(){
    top = NULL;
    last = NULL;
    nextIterator = NULL;
    sizeLista = 0;
}

ListaAdjacencia::ListaAdjacencia(int node){
    top = new NodeList(node);
    last = top;
    nextIterator = top;
    sizeLista = 1;
}

bool ListaAdjacencia::add(int data){
    if(!search(data)){
        NodeList* new_node = new NodeList(data);
        if (top == NULL)
        {
            top = new_node;
            last = new_node;
        }else{
            last->add(new_node);
            this->last = new_node;
        }
        sizeLista++;
        return true;        
    }
    return false;
}

bool ListaAdjacencia::sortedInsert(int data){ 
    if(!search(data)){

        NodeList* node = new NodeList(data);
        NodeList* pre = NULL;
        NodeList *curr = top;

        while(curr!=NULL && data>curr->data){
            pre = curr;
            curr = curr->next;
        }
        node->next = curr;
        if(pre==NULL){
            top = node;
        }else{
            pre->next = node;
        }
        sizeLista++;
        return true;
    }
    return false;
}

bool ListaAdjacencia::sortedInsert(int data, double newWeight){ 

    
    if(!search(data)){

        NodeList* node = new NodeList(data, newWeight);
        NodeList* pre = NULL;
        NodeList *curr = top;

        while(curr!=NULL && data>curr->data){
            pre = curr;
            curr = curr->next;
        }
        node->next = curr;
        if(pre==NULL){
            top = node;
        }else{
            pre->next = node;
        }
        sizeLista++;
        return true;
    }
    return false;
}

void ListaAdjacencia::show(){

    NodeList* nodee = top;
    while (nodee != NULL)
    {
        int c = nodee->get();
        double b = nodee->weight;
        cout<<c<<" - Peso: "<<b<<" , ";
        nodee = nodee->get_next();
    }
    printf("\n\n\n\n\n");
}

bool ListaAdjacencia::search(int i){
    NodeList* nodee = top;
    while (nodee != NULL)
    {
        int c = nodee->get();
        if (c == i)
        {
            return true;
        }
        nodee = nodee->get_next();
    }
    return false;
}

int ListaAdjacencia::size(){
    return sizeLista;
}

NodeList* ListaAdjacencia::getNodePosition(int position){

    if(position>sizeLista){
        return nextIterator;
    }
    
    
    if(position<iterator){
        iterator = 0;
        nextIterator = top;
    }

    if(nextIterator==NULL){
        nextIterator = top;
    }

    while (iterator<position)
    {
        int node = nextIterator->get();
        double weightNode = nextIterator->weight;
        nextIterator = nextIterator->get_next();
        iterator++;
    }
    return nextIterator;

}

NodeList* ListaAdjacencia::getTop(){    
    return top;
}

//Essa funcao popular e ineficiente, pois ele recebe uma vetor de lista e cria outro
//Pra se tornar mais eficiente ele deveria modificar o vetor de lista, custando menos memoria assim

void VectorListaAdjacencia::setSize(int newSizeVector){
    size = newSizeVector; //size será a quantidade de nós
    vetorDeListas = Popular(vetorDeListas,0 ,newSizeVector);
}

bool VectorListaAdjacencia::addAresta(int valor1, int valor2){
    bool resposta; //precisa setar o tamanho antes
    resposta = vetorDeListas.at(valor1).sortedInsert(valor2);
    return resposta;
}

bool VectorListaAdjacencia::addAresta(int valor1, int valor2, double weight){
    bool resposta; //precisa setar o tamanho antes
    resposta = vetorDeListas.at(valor1).sortedInsert(valor2, weight);
    return resposta;
}

void VectorListaAdjacencia::show(bool weight){
    for(int i = 0; i<=size; i++){
        cout<<endl<<"lista "<<i<<" :";
        vetorDeListas.at(i).show();
    }
}

int VectorListaAdjacencia::vizinhoDeVertice(int vertice, int posicaoVizinho){
    pair <int, double> dupla;
    int vizinho;
    int sizeValue = sizeVertice(vertice);

    if(sizeValue ==-1 || posicaoVizinho+1>sizeValue){
        vizinho = -1;
    }else{
        NodeList* nodeVizinho = vetorDeListas.at(vertice).getNodePosition(posicaoVizinho);
        vizinho = nodeVizinho->data;
    }

    return vizinho;
}

pair <int,double> VectorListaAdjacencia::vizinhoDeVertice(int vertice, int posicaoVizinho, bool weight){

    pair <int, double> dupla;
    int vizinho;
    double pesoVertice;
    int sizeValue = sizeVertice(vertice);

    if(sizeValue ==-1 || posicaoVizinho>=sizeValue){
        pesoVertice = nan("");
        dupla = {-1, pesoVertice};
    }else{
        NodeList* nodeVizinho = vetorDeListas.at(vertice).getNodePosition(posicaoVizinho);
        pesoVertice = nodeVizinho->weight;
        vizinho = nodeVizinho->data;
        dupla = {vizinho, pesoVertice};
    }

    return dupla;    
}

int VectorListaAdjacencia::sizeVertice(int vertice){

    if(vertice>=vetorDeListas.size()){
        return -1;
    }
    int sizeValue = vetorDeListas.at(vertice).size();
    return sizeValue;
}