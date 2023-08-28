#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char nome[30];
    int rg;
    Node *anterior;
    Node *atual;
};
struct Header{
    int tamanho;
    Node *Primeiro;
    Node *Ultimo;
};

int main()
{
    char n[30];
    int rg;
    Node *Primeiro;
    Primeiro = (Node*) malloc (sizeof (Node));

    if(Primeiro != NULL)
    {
        printf("Digite o RG:\n");
        scanf("%d", &rg);

        Primeiro->rg = rg;

        printf("Digite o nome:\n");
        scanf("%s", &n);

        strcpy(Primeiro->nome, n);

    }
}
