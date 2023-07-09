#include <stdio.h>
#include <stdlib.h>

struct no
{
    int dado;
    struct no *esq, *dir;
};
struct no *raiz = NULL;

void insere(int valor)
{
    struct no *aux, *atual;
    aux=(struct no*)malloc(sizeof(struct no));
    aux->dado=valor;
    aux->esq=NULL;
    aux->dir=NULL;
    if(raiz==NULL)
    {
        raiz=aux;
        printf("Valor inserido com sucesso\n\n");
        return;
    }
    atual=raiz;
    while(1)
    {
        if(aux->dado >= atual->dado)
        {
            if(atual->dir==NULL)
            {
                atual->dir=aux;
                printf("Valor inserido com sucesso\n\n");
                return;
            }
            atual=atual->dir;
        }
        else
        {
            if(atual->esq==NULL)
            {
                atual->esq=aux;
                printf("Valor inserido com sucesso\n\n");
                return;
            }
            atual=atual->esq;
        }
    }
}

void busca(int valor)
{
    struct no* atual;
    atual=raiz;
    if(atual==NULL)
    {
        printf("Arvore vazia\n\n");
        return;
    }
    while(atual!=NULL)
    {
        if(atual->dado==valor)
        {
            printf("Valor encontrado\n\n");
            return;
        }
        if(valor>atual->dado)
        {
            atual=atual->dir;
        }
        else
        {
            atual=atual->esq;
        }
    }
    printf("Valor nao encontrado\n\n");
}

void em_ordem(struct no *atual)
{
    if(raiz==NULL)
    {
        printf("Arvore vazia\n\n");
        return;
    }
    if(atual!=NULL)
    {
        em_ordem(atual->esq);
        printf("-%d",atual->dado);
        em_ordem(atual->dir);
    }
}

void pre_ordem(struct no *atual)
{
    if(raiz==NULL)
    {
        printf("Arvore vazia\n\n");
        return;
    }
    if(atual!=NULL)
    {
        printf("-%d",atual->dado);
        pre_ordem(atual->esq);
        pre_ordem(atual->dir);
    }
}

void pos_ordem(struct no *atual)
{
    if(raiz==NULL)
    {
        printf("Arvore vazia\n\n");
        return;
    }
    if(atual!=NULL)
    {
        pos_ordem(atual->esq);
        pos_ordem(atual->dir);
        printf("-%d",atual->dado);
    }
}

int main()
{
    int opcao, valor;

    opcao=-1;
    while(opcao!=0)
    {
        printf("1 - INSERIR\n2 - BUSCAR\n3 - IMPRIMIR EM ORDEM\n4 - IMPRIMIR PRE ORDEM\n5 - IMPRIMIR POS ORDEM\n0 - SAIR\nSelecione uma opcao: ");
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valor);
            insere(valor);
            break;

        case 2:
            printf("Digite o valor a ser buscado: ");
            scanf("%d", &valor);
            busca(valor);
            break;

        case 3:
            em_ordem(raiz);
            printf("\n");
            break;

        case 4:
            pre_ordem(raiz);
            printf("\n");
            break;

        case 5:
            pos_ordem(raiz);
            printf("\n");
            break;

        case 0:
            printf("Encerrando o programa\n");
            break;

        default:
            printf("Opcao invalida, tente novamente\n\n");
            break;
        }
    }

    return 0;
}
