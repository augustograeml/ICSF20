#include <stdio.h>
#include <stdlib.h>

struct Header{        //nó
    int tamanho;  //tamanho da lista
    struct Header *primeiro; //endereço do primeiro
    struct Header *ultimo;   // endereço do ultimo
};
struct Node{
    int informacao;
    struct Node *anterior;
    struct Node *proximo;
};

int main()
{
    struct Header lista;
    lista.tamanho = 0;
    struct Node *Ultimo;


        struct Node *Primeiro = (struct Node*) malloc (sizeof (struct Node));

        if (Primeiro != NULL)
        {
            printf("Digite a idade:");
            scanf("%d", &Primeiro->informacao);
            Primeiro->anterior = NULL;
            Primeiro->proximo = NULL;
            //atualização do header
            lista.tamanho++;
            lista.primeiro = &Primeiro;
            lista.ultimo = &Primeiro;
            Ultimo->informacao = Primeiro->informacao;
        }

    while(Ultimo->informacao != 0)
    {
        struct Node *Ultimo = malloc (sizeof (Node));

        if (Ultimo != NULL)
        {
            printf("Digite a idade OU zero se nao quiser mais informar");
            scanf("%d", &Ultimo.informacao);
            Ultimo->anterior = &Ultimo;
            Ultimo->proximo = NULL;
            //atualização do header
            lista.tamanho++;
            lista->ultimo = &Ultimo;

        }
    }




}
