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
    int tamanho = 0;
    Pessoa listaDePessoas[10];
};

void ImprimeMenu1(Lista *Primeira);
void geraLista(Lista *Primeira);

void adicionaNoFinal(Lista* Primeira);
void adicionaNoInicio(Lista* Primeira);
void adicionaNoN(Lista* Primeira);

void removeDoInicio(Lista* Primeira);
void removeDoFinal(Lista* Primeira);
void removeDaN(Lista* Primeira);

int main()
{

    Lista *Primeira = new Lista;

    geraLista(Primeira);

    ImprimeMenu1(Primeira);








  return 0;
}
void geraLista(Lista *Primeira)
{
      int i = 0;
      char nome[30];
      char RG[10];
      char line[80];

      ifstream myfile ("NomeRG10.txt");

      if (myfile.is_open())
      {
        while (getline(myfile, &line))
        {

         getline(line, nome, ',');
         getline(line, RG); // to int depois para transformar rg para inteiro

         Primeira->tamanho++;
         i++;

        }
        myfile.close();
      }

      else cout << "Unable to open file";



}
void ImprimeMenu1(Lista *Primeira)
{
    int decisao;
    int decisao2;
    int decisao3;
    int i = 0;

    while(i < TAMANHO)
    {

        cout << "1- Adicionar mais pessoas" << endl << "2- Imprimir Lista " << endl << "3 - Remover pessoas" << endl;
        cin >> decisao;

        switch(decisao)
            {
                case 1:
                    cout << "1- adicionar no inicio" << endl << "2- adicionar no final " << endl << "3 - Adicionar na posição N" << endl;
                    cin >> decisao2;

                    switch(decisao2)
                    {
                        case 1:
                            adicionaNoInicio(Primeira);
                            break;

                        case 2:
                            adicionaNoFinal(Primeira);
                            break;

                        case 3:
                            adicionarNaN(Primeira);
                            break;
                    }

                    break;

                case 2:
                    for(int j = 0; j < TAMANHO; j++)
                    {
                        cout << Primeira->listaDePessoas[j].nome << " -- " << Primeira->listaDePessoas[j].RG <<endl;
                    }
                    break;

                case 3:
                    cout << "1- Remove do inicio" << endl << "2- Remove do final " << endl << "3 - Remove da posição N" << endl;
                    cin >> decisao3;

                    switch(decisao3)
                    {
                        case 1:
                            removeDoInicio(Primeira);
                            break;

                        case 2:
                            removeDoFinal(Primeira);
                            break;

                        case 3:
                            removeDaN(Primeira);
                            break;
                    }

                default:
                    break;
            }
    }
}

/** INSERIR NOME E RG

    cout << "Digite um Nome:" <<endl;
    cin >> Primeira->listaDePessoas[i].nome;
    cin.ignore();

    cout << "Digite um RG: " <<endl;
    cin >> Primeira->listaDePessoas[i].RG;
    cin.ignore();

    Primeira->tamanho++;
    i++;

**/
