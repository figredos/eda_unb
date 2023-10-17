#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int info;
    struct celula *prox;
} celula;

// Protótipos de funções
celula *cria_lista();
celula *cria_no(int valor);
void insere_final(celula *lista_1, celula *lista_2);
void imprime(celula *lista);

celula *cria_lista()
{
    celula *lista = malloc(sizeof(celula));

    lista->info = NULL;

    lista->prox = NULL;

    return lista;
}

celula *cria_no(int valor)
{
    celula *novo = malloc(sizeof(celula));

    novo->prox = NULL;

    novo->info = valor;

    return novo;
}

void insere_final(celula *lista_1, celula *lista_2)
{
    celula *temp = lista_1;

    while (temp->prox != NULL)
        temp = temp->prox;

    temp->prox = lista_2;
}

void troca_posicao(celula *lista, int posicao_1, int posicao_2)
{
    int contador = 0;

    if (posicao_1 == posicao_2)
        return;

    celula *atual_1 = lista, *anterior_1 = NULL;
    while (contador <= posicao_1 && atual_1->prox != NULL)
    {
        anterior_1 = atual_1;
        atual_1 = atual_1->prox;
    }

    contador = 0;

    celula *atual_2 = lista, *anterior_2 = NULL;
    while (contador <= posicao_2 && atual_2->prox != NULL)
    {
        anterior_2 = atual_2;
        atual_2 = atual_2->prox;
    }

    if (anterior_1 != NULL)
        anterior_1->prox = atual_2;
    else
        lista = atual_2;

    if (anterior_2 != NULL)
        anterior_2->prox = atual_1;
    else
        lista = atual_1;

    celula *temp = atual_2->prox;
    atual_2->prox = atual_1->prox;
    atual_1->prox = temp;
}
// void divide_lista(celula *l, celula *l1, celula *l2)
// {
//     celula *troca = NULL;
//     celula *temp_ant = l, *temp_atual = l->prox;
//     celula *temp_impar_ant = l1, *temp_impar_atual = l2->prox;
//     celula *temp_par_ant = l2, *temp_par_atual = l2->prox;
//     while (temp_ant != NULL)
//     {
//         if (temp_atual->info % 2)
//         {
//             troca = temp_impar_atual;
//             temp_impar_atual = temp_atual;
//             temp_atual = troca
//         }
//         else
//         {
//             temp_par->info = temp->info;
//             temp_par = temp_par->prox;
//         }
//         temp = temp->prox;
//     }
// }

void divide_lista(celula *l, celula *l1, celula *l2)
{
    celula *impar = l1;
    celula *par = l2;

    while (l != NULL)
    {
        if (l->info % 2)
        {
            celula *salva = l->prox, *impar_prox = impar->prox;
            impar->prox = l;
            impar = impar->prox;
            impar->prox = impar_prox;
            l = salva;
        }
        else
        {  
            celula *salva = l->prox, *par_prox = par->prox;
            par->prox = l;
            par = par->prox ; 
            par->prox = par_prox;
            l = salva;
        }
    }

}
void imprime(celula *lista)
{
    celula *temp = lista;

    while (temp != NULL)
    {
        // if (temp->info != 0)
        printf("%d -> ", temp->info);
        temp = temp->prox;
    }

    printf("NULL");
}

int main()
{
    int numero;
    celula *cabeca = cria_lista();
    celula *no_1 = cria_no(1);
    celula *no_2 = cria_no(2);

    insere_final(cabeca, no_1);
    insere_final(cabeca, no_2);

    celula *par = cria_lista();
    celula *par_1 = cria_no(0);

    insere_final(par, par_1);

    celula *impar = cria_lista();
    celula *impar_1 = cria_no(0);

    insere_final(impar, impar_1);

    celula *temp = cabeca;

    imprime(cabeca);
    printf("\n");

    divide_lista(cabeca, impar, par);

    imprime(par);
    printf("\n");

    imprime(impar);
    printf("\n");

    imprime(cabeca);

    return 0;
}

/*celula *busca(celula *le, int x)
{
    celula *temp = le;
    while (temp != NULL && temp->dado !=x)            
        temp = temp->prox;
    return temp;
}


celula *busca_rec(celula *le, int x)
{
    if (le == NULL)
        return NULL;
    if (le->dado == x)
        return le;
    return busca_rec(le->prox, x);
}*/