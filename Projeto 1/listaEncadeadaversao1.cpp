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

    Node* pAnterior;
    Node* pAtual;

    Node()
    {
        pAnterior = NULL;
        pAtual = NULL;
    }

};

class Header{
public:
    Node* Primeiro;
    Node* Ultimo;

};

void imprimeNomeRG(Node *Primeiro)
{
    cout << Primeiro->nome << endl;
    cout << Primeiro->RG << endl;

}

int main()
{
    Node *Primeiro = new Node;
    Primeiro:Node();

    int pAux;
    int decisao;

    Header *cabecalho = new Header;
    cabecalho->Primeiro = Primeiro;

    Primeiro->pAnterior = NULL;
    Primeiro->pAtual = Primeiro;

    cout << "Digite um Nome:" <<endl;
        cin.get(Primeiro->nome, 30);
        cin.ignore();

        cout << "Digite um RG: " <<endl;
        cin.get(Primeiro->RG, 10);
        cin.ignore();

        cout << "Digite 0 se quiser parar: " <<endl;
        scanf("%d", &decisao);

        Node* Atual = new Node;
        Atual:Node();

        Atual->pAnterior = Primeiro->pAtual;
        Atual->pAtual = Atual;


    while(Atual->pAtual != NULL ){
        cout << "Digite um Nome:" <<endl;
        cin.get(Primeiro->nome, 30);
        cin.ignore();

        cout << "Digite um RG: " <<endl;
        cin.get(Primeiro->RG, 10);
        cin.ignore();

        cout << "Digite 0 se quiser parar: " <<endl;
        scanf("%d", &decisao);

        Node* Atual1 = new Node;
        Atual1:Node();

        Atual1->pAnterior = Primeiro->pAtual;
        Atual1->pAtual = Atual;

        if(decisao == 0)
        {
            cabecalho->Ultimo = Atual1;
             break;
        }
        else
        {

        }

    }

    imprimeNomeRG(Primeiro);

    delete Primeiro;
    delete Atual;
    delete cabecalho;



  return 0;
}



