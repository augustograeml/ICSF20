#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#define TAMANHO 10
using namespace std;

int tamanho_variavel = 10;

class Pessoa{
public:
    int RG;
    char nome[30];
};

class Lista {
public:
    int tamanho = 10;
    Pessoa listaDePessoas[50];
};

void ImprimeMenu1(Lista *Primeira);
void geraLista(Lista *Primeira);

void adicionaNoInicio(Lista* Primeira);
void adicionaNoFinal(Lista* Primeira);
void adicionaNaN(Lista* Primeira);

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
     char url[]="NomeRG10.txt";
     FILE *arq;
     int i = 0;

     arq = fopen(url, "r");

     if(arq == NULL)
       printf("Erro, nao foi possivel abrir o arquivo\n");
     else
      while( (fscanf(arq," %[^,],%d\n", Primeira->listaDePessoas[i].nome, &Primeira->listaDePessoas[i].RG))!=EOF )
       i++;

     fclose(arq);



}
void ImprimeMenu1(Lista *Primeira)
{
    int decisao;
    int decisao2;
    int decisao3;
    int i = 0;

    while(decisao != 4)
    {

        cout << "1- Adicionar mais pessoas" << endl << "2- Imprimir Lista " << endl << "3- Remover pessoas" << endl << "4- Quit" << endl;
        cin >> decisao;

        switch(decisao)
            {
                case 1:
                    cout << "1- Adicionar no inicio" << endl << "2- Adicionar no final " << endl << "3 - Adicionar na posicao N" << endl;
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
                            adicionaNaN(Primeira);
                            break;

                        default:
                            break;
                    }
                    i++;
                    break;

                case 2:
                    for(int j = 0; j < tamanho_variavel; j++)
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
                case 4:
                    exit(0);
                    break;


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
void adicionaNoInicio(Lista* Primeira){

    tamanho_variavel++;

    for(int i= tamanho_variavel-1; i > 0 ; i--)
    {
        strcpy(Primeira->listaDePessoas[i].nome , Primeira->listaDePessoas[i-1].nome);
        Primeira->listaDePessoas[i].RG = Primeira->listaDePessoas[i-1].RG;
    }

    cout << "Digite um Nome:" <<endl;
    cin >> Primeira->listaDePessoas[0].nome;
    cin.ignore();

    cout << "Digite um RG: " <<endl;
    cin >> Primeira->listaDePessoas[0].RG;
    cin.ignore();


}
void adicionaNoFinal(Lista* Primeira){

    tamanho_variavel++;

    cout << "Digite um Nome:" <<endl;
    cin >> Primeira->listaDePessoas[tamanho_variavel - 1].nome;
    cin.ignore();

    cout << "Digite um RG: " <<endl;
    cin >> Primeira->listaDePessoas[tamanho_variavel - 1 ].RG;
    cin.ignore();

}
void adicionaNaN(Lista* Primeira){

    int posicao;
    tamanho_variavel++;

    cout << "Em qual posicao deseja incluir: 1 - " << tamanho_variavel + 1 << endl;
    cin >> posicao;

    for(int i= tamanho_variavel-1; i > posicao -1 ; i--)
    {
        strcpy(Primeira->listaDePessoas[i].nome , Primeira->listaDePessoas[i-1].nome);
        Primeira->listaDePessoas[i].RG = Primeira->listaDePessoas[i-1].RG;
    }

    cout << "Digite um Nome:" <<endl;
    cin >> Primeira->listaDePessoas[posicao -1].nome;
    cin.ignore();

    cout << "Digite um RG: " <<endl;
    cin >> Primeira->listaDePessoas[posicao -1 ].RG;
    cin.ignore();


}

void removeDoInicio(Lista* Primeira){}
void removeDoFinal(Lista* Primeira){}
void removeDaN(Lista* Primeira){}
