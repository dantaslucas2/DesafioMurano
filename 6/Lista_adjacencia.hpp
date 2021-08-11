#ifndef __LISTAADJACENCIA_H__
#define __LISTAADJACENCIA_H__

#include <iostream>
#include <vector>
#include "Estrutura_de_dados.hpp"

using namespace std;

class NodeList
{
    public:
        /* data */
        //NodeList* prior;
        NodeList* next;
        int data;
        double weight;

        NodeList(int dataa);
        NodeList(int dataa, double weight);
        void set(int i);
        int get();
        NodeList* get_next();        
        void add(NodeList* data);
};

class ListaAdjacencia
{
    private:
        NodeList* top;
        NodeList* last;
        NodeList* nextIterator;
        int iterator=0;
        int sizeLista;

    public:

        ListaAdjacencia();
        ListaAdjacencia(int node);
        bool add(int data); 
        void show();
        bool search(int i);
        int size();
        NodeList* getNodePosition(int position);
        NodeList* getTop();
        bool sortedInsert(int val);
        bool sortedInsert(int val, double newWeight);
};

class VectorListaAdjacencia: public EstruturaDeDados
{    
    private:
        vector<ListaAdjacencia> vetorDeListas;

    public:
        //VectorListaAdjacencia(int newSizeVector);
        void setSize(int newSizeVector);
        bool addAresta(int valor1, int valor2);
        bool addAresta(int valor1, int valor2, double weight);
        void show(bool weight);
        int vizinhoDeVertice(int vertice, int posicaoVizinho);        
        pair <int,double> vizinhoDeVertice(int vertice, int posicaoVizinho, bool weight);
        int sizeVertice(int vertice);
};
#endif