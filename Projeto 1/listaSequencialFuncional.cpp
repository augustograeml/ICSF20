#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include<windows.h>
#include <time.h>
#define TAMANHO 10
#define TAMANHOVETOR 12000000

#define MYFILE "NomeRG10.txt"
#define SAIDA "saidanova123.txt"

using namespace std;

int tamanho_variavel = TAMANHO;

class Pessoa{
public:
    int RG;
    char nome[30];
    int posicao;
    Pessoa *pProxima;
};

class ListaSequencial {
public:
    Pessoa listaDePessoas[TAMANHOVETOR];
};

class ListaEncadeada {
public:
    Pessoa *primeira;
    int tamanho;

    ListaEncadeada()
    {
        primeira = NULL;
        tamanho = 0;
    }
};

void ImprimeMenu2(ListaEncadeada *Lista);

void geraListaEncadeada(ListaEncadeada *Lista);
void escreveListaEncadeada(ListaEncadeada *Lista);

Pessoa* criaPessoa();

void ImprimeListaEncadeada(ListaEncadeada *Lista);

void adicionaNoInicioEncadeada(ListaEncadeada *Lista);
void adicionaNoFinalEncadeada(ListaEncadeada *Lista);
void adicionaNaNEncadeada(ListaEncadeada *Lista);

void removeDoInicioEncadeada (ListaEncadeada *Lista);
void removeDoFinalEncadeada (ListaEncadeada *Lista);
void removeDaNEncadeada (ListaEncadeada *Lista);

//############################# INICIO LISTA SEQUENCIAL FUNCOES ##############################

void ImprimeMenu1(ListaSequencial *Primeira);

void geraListaSequencial(ListaSequencial *Primeira);
void escreveListaSequencial(ListaSequencial *Primeira);

void adicionaNoInicio(ListaSequencial* Primeira);
void adicionaNoFinal(ListaSequencial* Primeira);
void adicionaNaN(ListaSequencial* Primeira);

void removeDoInicio(ListaSequencial* Primeira);
void removeDoFinal(ListaSequencial* Primeira);
void removeDaN(ListaSequencial* Primeira);

int main()
{
    ListaSequencial *Primeira = new ListaSequencial;

    ListaEncadeada *Lista = new ListaEncadeada;
    Lista->primeira = NULL;

    int escolha;
    while(escolha != 3)
    {
        cout << "Qual lista deseja utilizar?" << endl << "1- Sequencial" << endl << "2- Encadeada" <<endl << "3- QUIT" <<endl;
        cin >> escolha;

        system("cls");

        switch(escolha)
        {
        case 1:
            {
            double tempo_gasto1 = 0.0;
            clock_t comeco = clock();

            geraListaSequencial(Primeira);

            clock_t fim = clock();
            tempo_gasto1 += (double) (fim - comeco)/CLOCKS_PER_SEC;

            printf ("Tempo gasto para gerar a lista sequencial %f\n", tempo_gasto1);

            ImprimeMenu1(Primeira);
            break;
            }

        case 2:
            {
            double tempo_gasto2 = 0.0;
            clock_t inicio = clock();

            geraListaEncadeada(Lista);

            clock_t termino = clock();
            tempo_gasto2 += (double) (termino - inicio) / CLOCKS_PER_SEC;

            printf("Tempo gasto para gerar a lista Encadeada %f \n", tempo_gasto2);

            ImprimeMenu2(Lista);
             break;
            }
        case 3:
            exit(0);
            break;

        default:
            cout << "OPÇÃO INVÁLIDA! " << endl;
            break;

        }
    }


    delete Primeira;
    delete Lista;

  return 0;
}
//----------------------------------------- GERA/ESCREVE SEQUENCIAL ------------------------------------------------

void geraListaSequencial(ListaSequencial *Primeira)
{
     char url[]= MYFILE;
     FILE *arq;
     int i = 0;

     arq = fopen(url, "r");

     if(arq == NULL)
       printf("Erro, nao foi possivel abrir o arquivo\n");
     else
      while(i < tamanho_variavel && fscanf(arq," %[^,],%d", Primeira->listaDePessoas[i].nome, &Primeira->listaDePessoas[i].RG)!=EOF )
      {
            i++;
      }


     fclose(arq);
}
void escreveListaSequencial(ListaSequencial *Primeira)
{
    char url[] = SAIDA;
    FILE *arq;
    arq = fopen(url, "w");

    if (arq == NULL)
    {
        printf("Erro, não foi possível criar o arquivo\n");
        return;
    }
    else
    {
       for (int i = 0; i < tamanho_variavel - 1; i++)
        {
            fprintf(arq, "%s,%d\n", Primeira->listaDePessoas[i].nome, Primeira->listaDePessoas[i].RG);
        }
        cout << "Arquivo salvo com sucesso!" << endl;
    }

    fclose(arq);
}
// --------------------------------------- GERA/ESCREVE ENCADEADA ------------------------------------------
void geraListaEncadeada(ListaEncadeada* Lista)
{
    Pessoa *pAux = criaPessoa();
    Lista->primeira = pAux;

    char url[] = MYFILE;
    FILE *arq;
    int i = 1;
    char nome[30];
    int rg;

    arq = fopen(url, "r");

    if(arq == NULL)
       cerr << "Erro, nao foi possivel abrir o arquivo" << endl;
     else
      while(i <= tamanho_variavel && fscanf(arq," %[^,],%d", nome, &rg) != EOF )
      {
         strcpy(pAux->nome, nome);
         pAux->RG = rg;
         pAux->posicao = i;
         Pessoa*  Novo = criaPessoa();
         pAux->pProxima = Novo;
         pAux = pAux->pProxima;
         pAux->pProxima = NULL;
         i++;
      }


     Lista->tamanho += tamanho_variavel;
     fclose(arq);


}

void escreveListaEncadeada(ListaEncadeada *Lista)
{
    char url[] = SAIDA;
    FILE *arq;
    arq = fopen(url, "w");

    Pessoa* pAux = Lista->primeira;

    if (arq == NULL)
    {
        cerr << "Erro, não foi possível criar o arquivo" << endl;
        return;
    }
    else
    {
        for (int i = 0; i < Lista->tamanho; i++)
        {
            fprintf(arq, "%s,%d\n", pAux->nome, pAux->RG);
            pAux = pAux->pProxima;
        }
        cout << "Arquivo salvo com sucesso!" << endl;
    }



    fclose(arq);
}


//--------------------------------------- IMPRIME MENUS ----------------------------------------------------
void ImprimeMenu1(ListaSequencial *Primeira)
{
    int decisao = 0;
    int decisao2 = 0;
    int decisao3 = 0;
    int registroGeral = 0;
    int i = 0;

    while(decisao != 5)
    {
        cout << "---------LISTA SEQUENCIAL---------" << endl;

        cout <<"0- Procurar por RG" <<endl << "1- Adicionar mais pessoas" << endl << "2- Imprimir Lista " << endl << "3- Remover pessoas" << endl << "4- Salvar arquivo" << endl << "5- Quit" <<endl;
        cin >> decisao;

        switch(decisao)
            {
                case 0:
                {
                    system("cls");
                    double tempoDeProcura = 0.0;
                    int n = 0;

                    cout << "Insira o RG que deseja procurar: " <<endl;
                    cin >> registroGeral;

                    clock_t iniciodetempodeprocura = clock();
                    for(i = 0; i < tamanho_variavel; i++)
                    {
                        if (Primeira->listaDePessoas[i].RG == registroGeral )
                        {
                            clock_t fimdetempodeprocura = clock();
                            tempoDeProcura += (double) (fimdetempodeprocura - iniciodetempodeprocura) / CLOCKS_PER_SEC;

                            cout << Primeira->listaDePessoas[i].nome << " " << Primeira->listaDePessoas[i].RG <<endl;
                            cout << "Esta na posicao " << i+1 << " da lista" <<endl;
                            printf("O tempo de procura foi de %f segundos \n", tempoDeProcura);
                            cout << "O numero de comparacoes foi de " << n << endl;


                        }
                        n++;
                    }
                    break;
                 }
                case 1:
                    {
                        system("cls");

                        cout << "1- Adicionar no inicio" << endl << "2- Adicionar no final " << endl << "3- Adicionar em posicao especifica" << endl;
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
                                cout << "OPERACAO INVALIDA" << endl;
                                break;
                        }
                    break;
                    }
                case 2:
                    {
                        system("cls");

                        for(int j = 0; j < tamanho_variavel ; j++)
                        {
                            cout << j << " " << Primeira->listaDePessoas[j].nome << " -- " << Primeira->listaDePessoas[j].RG <<endl;
                        }
                        cout << "\n" <<endl;
                        break;
                    }

                case 3:
                    {
                      system("cls");

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

                            default:
                                system("cls");
                                cout << "OPERACAO INVALIDA"<<endl;
                                break;
                        }
                    break;
                    }

                case 4:
                    escreveListaSequencial(Primeira);
                    break;

                case 5:
                    system("cls");
                    break;

                default:
                    system("cls");
                    cout << "OPCAO INDISPONIVEL" <<endl;
                    break;
            }

    }
}
void ImprimeMenu2(ListaEncadeada *Lista)  /**$$$$$$$$$$$$$$$$$$$$$$$ MENU 2 $$$$$$$$$$$$$$$$$$$$$$$$$**/
{
    int decisao = 0;
    int decisao2 = 0;
    int decisao3 = 0;
    int registroGeral = 0;
    int i = 0;

    while(decisao != 5)
    {
        cout << "---------LISTA ENCADEADA---------" << endl;

        cout <<"0- Procurar por RG" <<endl << "1- Adicionar mais pessoas" << endl << "2- Imprimir Lista " << endl << "3- Remover pessoas" << endl << "4- Salvar arquivo" << endl << "5- Quit" <<endl;
        cin >> decisao;

        switch(decisao)
            {
                case 0:
                {
                    system("cls");
                    double tempoDeProcura = 0.0;
                    int n = 0;
                    Pessoa* pAux = Lista->primeira;
                    int registroGeral;

                    cout << "Insira o RG que deseja procurar: " <<endl;
                    cin >> registroGeral;

                    clock_t iniciodetempodeprocura = clock();
                    if(Lista == NULL)
                    {
                        cerr << "A LISTA ESTA VAZIA!" << endl;
                    }
                    else
                    {
                       while(pAux != NULL)
                        {
                            if (pAux->RG == registroGeral )
                            {
                                clock_t fimdetempodeprocura = clock();
                                tempoDeProcura += (double) (fimdetempodeprocura - iniciodetempodeprocura) / CLOCKS_PER_SEC;

                                cout << pAux->nome << " " << pAux->RG <<endl;
                                cout << "Esta na posicao " << pAux->posicao << " da lista" <<endl;
                                printf("O tempo de procura foi de %f segundos \n", tempoDeProcura);
                                cout << "O numero de comparacoes foi de " << n << endl;


                            }
                            pAux = pAux->pProxima;
                            n++;
                        }
                    }

                    break;
                 }
                case 1:
                    system("cls");

                    cout << "1- Adicionar no inicio" << endl << "2- Adicionar no final " << endl << "3- Adicionar em posicao especifica" << endl;
                    cin >> decisao2;

                    switch(decisao2)
                    {
                        case 1:
                            adicionaNoInicioEncadeada(Lista);
                            break;

                        case 2:
                            adicionaNoFinalEncadeada(Lista);
                            break;

                        case 3:
                            adicionaNaNEncadeada(Lista);
                            break;

                        default:
                            cout << "OPERACAO INVALIDA" << endl;
                            break;
                    }
                    break;

                case 2:
                    system("cls");
                    ImprimeListaEncadeada(Lista);
                    break;

                case 3:
                    system("cls");

                    cout << "1- Remove do inicio" << endl << "2- Remove do final " << endl << "3 - Remove da posição N" << endl;
                    cin >> decisao3;

                    switch(decisao3)
                    {
                        case 1:
                            removeDoInicioEncadeada (Lista);
                            break;

                        case 2:
                            removeDoFinalEncadeada(Lista);
                            break;

                        case 3:
                            removeDaNEncadeada(Lista);
                            break;

                        default:
                            system("cls");
                            cout << "OPERACAO INVALIDA"<<endl;
                            break;
                    }
                    break;
                case 4:
                    escreveListaEncadeada(Lista);
                    break;

                case 5:
                    system("cls");
                    break;

                default:
                    system("cls");
                    cout << "OPCAO INDISPONIVEL" <<endl;
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

################################################ INICIO DAS FUNCOES DA LISTA SEQUENCIAL ####################################### **/

void adicionaNoInicio(ListaSequencial* Primeira){

    tamanho_variavel= tamanho_variavel + 1;
    double tempoparaadicionarsequencial = 0.0;
    clock_t iniciodaadicao = clock();

    for(int i= tamanho_variavel - 1; i > 0 ; i--)
    {
        strcpy(Primeira->listaDePessoas[i].nome , Primeira->listaDePessoas[i-1].nome);
        Primeira->listaDePessoas[i].RG = Primeira->listaDePessoas[i-1].RG;
    }
    clock_t fimdaadicao = clock();
    tempoparaadicionarsequencial += (double) (fimdaadicao - iniciodaadicao) / CLOCKS_PER_SEC;

    cout << "Digite um Nome: " <<endl;
    cin >> Primeira->listaDePessoas[0].nome;
    cin.ignore();

    cout << "Digite um RG: " <<endl;
    cin >> Primeira->listaDePessoas[0].RG;
    cin.ignore();

     cout << Primeira->listaDePessoas[0].nome << " " << Primeira->listaDePessoas[0].RG <<endl;
     cout << "Esta na posicao " << 1 << " da lista" <<endl;
     printf("O tempo de execucao foi de %f segundos \n", tempoparaadicionarsequencial);
     cout << "O numero de comparacoes foi de " << 0 << endl;
}
void adicionaNoFinal(ListaSequencial* Primeira){

    tamanho_variavel++;

    cout << "Digite um Nome:" <<endl;
    cin >> Primeira->listaDePessoas[tamanho_variavel - 1].nome;
    cin.ignore();

    cout << "Digite um RG: " <<endl;
    cin >> Primeira->listaDePessoas[tamanho_variavel - 1 ].RG;
    cin.ignore();

    cout << Primeira->listaDePessoas[tamanho_variavel - 1].nome << " " << Primeira->listaDePessoas[tamanho_variavel - 1].RG <<endl;
     cout << "Esta na posicao " << tamanho_variavel << " da lista" <<endl;
     printf("O tempo de execucao foi de 0 segundos \n");
     cout << "O numero de comparacoes foi de " << 0 << endl;

}
void adicionaNaN(ListaSequencial* Primeira){

    double tempodeadicao = 0.0;
    int posicao;
    tamanho_variavel++;

    cout << "Em qual posicao deseja incluir: 1 - " << tamanho_variavel << endl;
    cin >> posicao;

    clock_t iniciodaadicao = clock();
    for(int i= tamanho_variavel-1; i > posicao -1 ; i--)
    {
        strcpy(Primeira->listaDePessoas[i].nome , Primeira->listaDePessoas[i-1].nome);
        Primeira->listaDePessoas[i].RG = Primeira->listaDePessoas[i-1].RG;
    }
    clock_t fimdaadicao = clock();

    cout << "Digite um Nome:" <<endl;
    cin >> Primeira->listaDePessoas[posicao -1].nome;
    cin.ignore();

    cout << "Digite um RG: " <<endl;
    cin >> Primeira->listaDePessoas[posicao -1 ].RG;
    cin.ignore();

    cout << Primeira->listaDePessoas[posicao - 1].nome << " " << Primeira->listaDePessoas[posicao -1].RG <<endl;
     cout << "Esta na posicao " << posicao << " da lista" <<endl;
     printf("O tempo de execucao foi de %f segundos \n", tempodeadicao);
     cout << "O numero de comparacoes foi de " << 0 << endl;

}

void removeDoInicio(ListaSequencial* Primeira){
    double tempoderemove = 0.0;

    cout << Primeira->listaDePessoas[0].nome << " " << Primeira->listaDePessoas[0].RG <<endl;
    cout << "Sera removido da posicao " << 1 << " da lista" <<endl;

    if(tamanho_variavel > 0)
    {
        clock_t inicio = clock();
        for(int i= 0; i < tamanho_variavel - 1 ; i++)
        {
            strcpy(Primeira->listaDePessoas[i].nome , Primeira->listaDePessoas[i+1].nome);
            Primeira->listaDePessoas[i].RG = Primeira->listaDePessoas[i+1].RG;
        }
         tamanho_variavel--;
         clock_t fim = clock();

         tempoderemove += (double) (fim - inicio)/ CLOCKS_PER_SEC;

         strcpy(Primeira->listaDePessoas[tamanho_variavel].nome, "");
         Primeira->listaDePessoas[tamanho_variavel].RG = 0;
    }
    else
        cout << "A lista esta vazia" <<endl;

     printf("O tempo de execucao foi de %f segundos \n", tempoderemove);
     cout << "O numero de comparacoes foi de " << 0 << endl;
}
void removeDoFinal(ListaSequencial* Primeira)
{
    double tempoderemove = 0.0;
    cout << Primeira->listaDePessoas[tamanho_variavel].nome << " " << Primeira->listaDePessoas[tamanho_variavel].RG <<endl;
    cout << "Sera removido da posicao " << tamanho_variavel << " da lista" <<endl;

    if(tamanho_variavel > 0)
    {
       clock_t inicio = clock();
       for(int i= tamanho_variavel-1; i > 0 ; i--)
        {
            strcpy(Primeira->listaDePessoas[i].nome , Primeira->listaDePessoas[i-1].nome);
            Primeira->listaDePessoas[i].RG = Primeira->listaDePessoas[i-1].RG;
        }
        tamanho_variavel--;
        clock_t fim = clock();

        tempoderemove += (double) (fim - inicio)/ CLOCKS_PER_SEC;

         strcpy(Primeira->listaDePessoas[0].nome, "");
         Primeira->listaDePessoas[0].RG = 0;

         printf("O tempo de execucao foi de %f segundos \n", tempoderemove);
         cout << "O numero de comparacoes foi de " << 0 << endl;

    }
    else
        cout << "A lista esta vazia" <<endl;

}
void removeDaN(ListaSequencial* Primeira)
{
    int posicao = 0;
    double tempoderemove = 0.0;

    if(tamanho_variavel > 0)
    {
        cout << "Em qual posicao deseja remover: 1 - " << tamanho_variavel << endl;
        cin >> posicao;

        cout << Primeira->listaDePessoas[posicao-1].nome << " " << Primeira->listaDePessoas[posicao-1].RG <<endl;
        cout << "Sera removido da posicao " << posicao << " da lista" <<endl;

        clock_t inicio = clock();
        for(int i= posicao-1; i < tamanho_variavel - 1 ; i++)
        {
            strcpy(Primeira->listaDePessoas[posicao-1].nome , Primeira->listaDePessoas[i+1].nome);
            Primeira->listaDePessoas[posicao-1].RG = Primeira->listaDePessoas[i+1].RG;
        }
         tamanho_variavel--;
         clock_t fim = clock();

        tempoderemove += (double) (fim - inicio)/ CLOCKS_PER_SEC;

         strcpy(Primeira->listaDePessoas[tamanho_variavel].nome, "");
         Primeira->listaDePessoas[tamanho_variavel].RG = 0;
    }
    else
        cout << "A lista esta vazia" <<endl;

        printf("O tempo de execucao foi de %f segundos \n", tempoderemove);
        cout << "O numero de comparacoes foi de " << 0 << endl;


}
/**###################################### FINAL DAS FUNCOES LISTA SEQUENCIAL #####################################################**/

Pessoa* criaPessoa()
 {
     Pessoa* nova = new Pessoa;
     return nova;
 }

//I************************************************ADICIONA NA ENCADEADA *****************************************************
void adicionaNoInicioEncadeada(ListaEncadeada *Lista)
{
    double tempodeadicao = 0.0;
    Pessoa *Novo1 = criaPessoa();
    Lista->tamanho++;

    clock_t inicio = clock();

    if(Lista->primeira == NULL)
    {
        Lista->primeira = Novo1;
        Novo1->posicao = 1;
        Novo1->pProxima = NULL;

        clock_t fimdaaadicao = clock();
        tempodeadicao += (double) (fimdaaadicao - inicio)/CLOCKS_PER_SEC;
    }
    else
    {
        Pessoa *pAux = Lista->primeira;
        Lista->primeira = Novo1;
        Novo1->pProxima = pAux;
        Novo1->posicao = 1;
        clock_t fimdaadicao = clock();
        tempodeadicao += (double) (fimdaadicao - inicio)/CLOCKS_PER_SEC;

        for(int i = 2; i < (Lista->tamanho + 1) && pAux->pProxima != NULL; i++)
        {
            pAux->posicao = i;
            pAux = pAux->pProxima;
        }
    }


    cout << "Digite um Nome:" <<endl;
    cin >> Novo1->nome;
    cin.ignore();

    cout << "Digite um RG: " <<endl;
    cin >> Novo1->RG;
    cin.ignore();

    cout << Novo1->nome << " " << Novo1->RG <<endl;
    cout << "Esta na posicao " << Novo1->posicao << " da lista" <<endl;
    printf("O tempo de execucao foi de %f segundos \n", tempodeadicao);
    cout << "O numero de comparacoes foi de " << 0 << endl;


}
void adicionaNoFinalEncadeada(ListaEncadeada *Lista)
{
    int n = 0;
    Pessoa *pAux = Lista->primeira;
    Pessoa *Novo2 = criaPessoa();
    double tempodeadicao = 0.0;

    clock_t inicio = clock();

    while(pAux->pProxima != NULL)
    {
        pAux = pAux->pProxima;
        n++;
    }
    pAux->pProxima = Novo2;
    Lista->tamanho++;
    Novo2->posicao = Lista->tamanho;
    Novo2->pProxima = NULL;

    clock_t fim = clock();
    tempodeadicao += (double) (fim-inicio)/CLOCKS_PER_SEC;

    cout << "Digite um Nome:" <<endl;
    cin >> Novo2->nome;
    cin.ignore();

    cout << "Digite um RG: " <<endl;
    cin >> Novo2->RG;
    cin.ignore();

    cout << Novo2->nome << " " << Novo2->RG <<endl;
    cout << "Esta na posicao " << Novo2->posicao << " da lista" <<endl;
    printf("O tempo de execucao foi de %f segundos \n", tempodeadicao);
    cout << "O numero de comparacoes foi de " << n << endl;


}
void adicionaNaNEncadeada(ListaEncadeada *Lista)
{
    double tempodeadicao = 0.0;
    Pessoa *pAux = Lista->primeira;
    Pessoa *pAux2;
    Pessoa *Novo3 = criaPessoa();
    Lista->tamanho++;
    int posicao;
    int n = 0;

    cout << "Em qual posicao deseja incluir: 1 - " << Lista->tamanho  << endl;
    cin >> posicao;

    clock_t inicio = clock();
    while(pAux->posicao != posicao )
    {
        pAux = pAux->pProxima;
        n++;
    }
    pAux2 = pAux->pProxima;
    pAux->pProxima = Novo3;
    Novo3->pProxima = pAux2;
    Novo3->posicao = posicao;
    pAux = pAux2;

    while(pAux != NULL)
    {
        pAux->posicao++;
        pAux = pAux->pProxima;
        n++;
    }
    clock_t fim = clock();
    tempodeadicao += (double) (fim - inicio)/CLOCKS_PER_SEC;

    cout << "Digite um Nome:" <<endl;
    cin >> Novo3->nome;
    cin.ignore();

    cout << "Digite um RG: " <<endl;
    cin >> Novo3->RG;
    cin.ignore();

    cout << Novo3->nome << " " << Novo3->RG <<endl;
    cout << "Esta na posicao " << Novo3->posicao - 1 << " da lista" <<endl;
    printf("O tempo de execucao foi de %f segundos \n", tempodeadicao);
    cout << "O numero de comparacoes foi de " << n << endl;


}
//********************************************* REMOVE DA ENCADEADA ***********************************************************
void removeDoInicioEncadeada(ListaEncadeada *Lista)
{
double tempoderemove = 0.0;
int n = 0;

  if(Lista->tamanho > 0)
  {
    cout << Lista->primeira->nome << " " << Lista->primeira->RG <<endl;
    cout << "Sera removido da posicao " << 1 << " da lista" <<endl;

    clock_t inicio = clock();
    Lista->tamanho = Lista->tamanho - 1;
    Lista->primeira = Lista->primeira->pProxima;
    Pessoa *pAux = Lista->primeira;

    for(int i = 0; i < Lista->tamanho; i++)
    {
        pAux->posicao = i;
        pAux = pAux->pProxima;
    }
    clock_t fim = clock();
    tempoderemove += (double) (fim-inicio)/CLOCKS_PER_SEC;
  }
  else
    cerr << "ERRO! A LISTA ESTÁ VAZIA" <<endl;

    printf("O tempo de execucao foi de %f segundos \n", tempoderemove);
    cout << "O numero de comparacoes foi de " << n << endl;

}
void removeDoFinalEncadeada(ListaEncadeada *Lista)
{
    double tempoderemove = 0.0;
    int n = 0;

    if(Lista->tamanho > 0)
    {
        clock_t inicio =clock();
        Pessoa *pAux = Lista->primeira;
        Pessoa *pAux2;

        while (pAux->pProxima != NULL)
        {
            pAux2 = pAux;
            pAux = pAux->pProxima;
            n++;
        }
        pAux2->pProxima = NULL;
        clock_t fim = clock();
        tempoderemove += (double) (fim-inicio)/CLOCKS_PER_SEC;
        cout << pAux->nome << " " << pAux->RG <<endl;
        cout << "Sera removido da posicao " << Lista->tamanho << " da lista" <<endl;

    }
    else
        cerr << "ERRO! A LISTA ESTÁ VAZIA" <<endl;

    printf("O tempo de execucao foi de %f segundos \n", tempoderemove);
    cout << "O numero de comparacoes foi de " << n << endl;
}

void removeDaNEncadeada(ListaEncadeada *Lista)
{
    int posicao = 0;
    int n = 0;
    double tempoderemove = 0.0;
    Pessoa *pAux = Lista->primeira;
    Pessoa *pAux2;

    if(Lista->tamanho > 0)
    {
        cout << "Em qual posicao deseja remover: 1 - " << Lista->tamanho << endl;
        cin >> posicao;
        clock_t inicio = clock();

        if(posicao == Lista->tamanho)
        {
            removeDoFinalEncadeada(Lista);
        }
        else
        {
                while(pAux->posicao != posicao)
                {
                    pAux2 = pAux;
                    pAux = pAux->pProxima;
                    n++;
                }

                pAux2->pProxima = pAux->pProxima;

                for(int i = posicao; i < Lista->tamanho; i++)
                {
                    pAux2->posicao--;
                    pAux2 = pAux2->pProxima;
                }
            clock_t fim = clock();
            tempoderemove += (double) (fim-inicio)/CLOCKS_PER_SEC;
            cout << pAux->nome << " " << pAux->RG <<endl;
            cout << "Sera removido da posicao " << posicao << " da lista" <<endl;
        }

        Lista->tamanho--;
    }
    else
        cout << "A lista esta vazia" <<endl;

        printf("O tempo de execucao foi de %f segundos \n", tempoderemove);
        cout << "O numero de comparacoes foi de " << n << endl;
}

//********************************************* IMPRIME A ENCADEADA ***********************************************************
void ImprimeListaEncadeada(ListaEncadeada *Lista)
{
    Pessoa *pAux = criaPessoa();
    pAux = Lista->primeira;
    int i = 0;
    if(Lista == NULL)
    {
        cerr << "ERRO! A LISTA ESTA VAZIA!" << endl;
    }

    while(pAux->pProxima != NULL && i <= Lista->tamanho)
    {
        cout << pAux->posicao << " " << pAux->nome << " " << pAux->RG << endl;
        pAux = pAux->pProxima;
        i++;

    }
}
