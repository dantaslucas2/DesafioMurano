#ifndef __ESTRUTURADEDADOS_H__
#define __ESTRUTURADEDADOS_H__

#include <iostream>

using namespace std;

class EstruturaDeDados{
 
    public:

    int size;
    EstruturaDeDados();
    virtual void setSize(int newSizeVector)=0;
    virtual bool addAresta(int valor1, int valor2)=0;
    virtual bool addAresta(int valor1, int valor2, double weight)=0;
    virtual void show(bool weight)=0;
    virtual int vizinhoDeVertice(int vertice, int posicaoVizinho)=0;
    virtual pair <int,double> vizinhoDeVertice(int vertice, int posicaoVizinho, bool weight)=0;
    virtual int sizeVertice(int vertice)=0;
    //virtual void addVertice();
    //virtual bool addAresta(int valor1, int valor2);

};

#endif