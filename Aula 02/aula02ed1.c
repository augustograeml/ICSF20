#include <stdio.h>
#include <stdlib.h>

struct Header{        //nó
    int tamanho;  //tamanho da lista
    Header *primeiro; //endereço do primeiro
    Header *atual;   // endereço do ultimo
};
struct Node{
    int informacao;
    Node *anterior;
    Node *proximo;
};

int main()
{
    Header Lista;
    lista.tamanho = 0;
    Node *Atual;
    Node *Primeiro;


        Primeiro = (Node*) malloc (sizeof (struct Node));

        if (Primeiro != NULL)
        {
            printf("Digite a idade:");
            scanf("%d", &Primeiro->informacao);
            Primeiro->anterior = NULL;
            Primeiro->proximo = NULL;
            //atualização do header
            lista.tamanho++;
            lista.primeiro = &Primeiro;
            lista.atual = &Primeiro;
            Atual->informacao = Primeiro->informacao;
        }

    while(Atual->informacao != 0)
    {
        struct Node *Atual = malloc (sizeof (Node));

        if (Ultimo != NULL)
        {
            printf("Digite a idade OU zero se nao quiser mais informar");
            scanf("%d", &Ultimo.informacao);
            Atual->anterior = &Ultimo;
            Atual->proximo = NULL;
            //atualização do header
            lista.tamanho++;
            lista->atual = &Atual;

        }
    }




}
