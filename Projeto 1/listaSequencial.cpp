#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#define TAMANHO 10
using namespace std;


class Pessoa{
public:
    string RG;
    string nome;
};

class Lista {
public:
    int tamanho = TAMANHO;
    Pessoa listaDePessoas[10];
};

void ImprimeMenu1(Lista *Primeira);

int main()
{
    Lista *Primeira = new Lista;

    Pessoa augusto;

    ImprimeMenu1(Primeira);








  return 0;
}
void ImprimeMenu1(Lista *Primeira)
{
    int decisao;
    int i = 0;

    while(i < TAMANHO)
    {

        cout << "1- adicionar mais pessoas" << endl << "2- Imprimir Lista " << endl << "3 - parar de adicionar pessoas" << endl;
        cin >> decisao;

        switch(decisao)
            {
                case 1:
                    cout << "Digite um Nome:" <<endl;
                    cin >> Primeira->listaDePessoas[i].nome;
                    cin.ignore();

                    cout << "Digite um RG: " <<endl;
                    cin >> Primeira->listaDePessoas[i].RG;
                    cin.ignore();

                    Primeira->tamanho++;
                    i++;
                    break;

                case 2:
                    for(int j = 0; j < TAMANHO; j++)
                    {
                        cout << Primeira->listaDePessoas[j].nome << " -- " << Primeira->listaDePessoas[j].RG <<endl;
                    }
                    break;


                default:
                    break;
            }
    }
}

