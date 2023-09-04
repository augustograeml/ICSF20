#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;

class Node {

public:
    char RG[10];
    char nome[30];
};

class Lista {

private:
    Pessoa *listaDePessoas;
    int tamanho;


};



int main()
{
    Node Lista[7];

    for(int i = 0; i < 7; i++)
    {
        Node Lista[i] =  new Node;

        cout << "Digite um Nome:" <<endl;
        cin.get(Lista[i]->nome, 30);
        cin.ignore();

        cout << "Digite um RG: " <<endl;
        cin.get(Lista[i]->RG, 10);
        cin.ignore();

    }

     for(int i = 0; i < 7; i++)
    {
        cout << Lista[i]->nome << " -- " << Lista[i]->RG <<endl;
    }

    delete [] Lista;

  return 0;
}



