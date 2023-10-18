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

celula *cria_lista_n_nos(int numero_nos, int *valores)
{
    celula *lista = cria_lista();

    for (int i = 0; i < numero_nos; i++)
    {
        celula *no = cria_no(valores[i]);
        insere_final(lista, no);
    }
    

    return lista;
}

void insere_inicio(celula *le, int x)
{
    celula *novo = malloc(sizeof(celula));
    novo->info = x;
    novo->prox = le->prox;

    le->prox = novo;
}

void insere_antes(celula *le, int x, int y)
{
    celula *nova = malloc(sizeof(celula));
    nova->info = x;

    celula *anterior = le, *atual = le->prox;

    while (atual != NULL && atual->info != y)
    {
        anterior = atual;
        atual = anterior->prox;
    }
    
    nova->prox = atual;
    anterior->prox = nova;
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
    celula *impar_ant = l1, *impar = l1->prox;
    celula *par_ant = l2, *par = l2->prox;

    while (l != NULL)
    {
        if (l->info % 2)
        {
            celula *salva = l->prox;
            impar_ant = l;
            impar = impar_ant->prox;
            impar_ant = impar;
            impar = NULL;
            l = salva;
        }
        else
        {  
            celula *salva = l->prox;
            par_ant = l;
            par = par_ant->prox;
            par_ant = par;
            par = NULL;
            l = salva;
        }
    }

}

void mescla_listas (celula *l1, celula *l2, celula *l3)
{
    celula *atual_l1 = l1->prox;
    celula *atual_l2 = l2->prox;
    celula *atual_l3= l3;

    while (atual_l1 != NULL && atual_l2 != NULL)
    {
        if (atual_l1->info < atual_l2->info)
        {
            atual_l3->prox = atual_l1;
            atual_l1 = atual_l1->prox;
        }
        else
        {
            atual_l3->prox = atual_l2;
            atual_l2 = atual_l2->prox;
        }
        atual_l3 = atual_l3->prox;
    }

    while (atual_l1 != NULL)
    {
        atual_l3->prox = atual_l1;
        atual_l1 = atual_l1->prox;
        atual_l3 = atual_l3->prox;
    }

    while (atual_l2 != NULL)
    {
        atual_l3->prox = atual_l2;
        atual_l2 = atual_l2->prox;
        atual_l3 = atual_l3->prox;
    }

    atual_l3->prox = NULL;

    l1->prox = NULL;
    l2->prox = NULL;
}
// void imprime(celula *lista)
// {
//     celula *temp = lista;

//     while (temp != NULL)
//     {
//         // if (temp->info != 0)
//         printf("%d -> ", temp->info);
//         temp = temp->prox;
//     }

//     printf("NULL");
// }

// void imprime(celula *le)
// {
//     celula *temp;

//     if (le != NULL)
//         temp = le->prox;
//     else
//         temp = le;

//     while (temp != NULL)
//     {
//         printf("%d -> ", temp->info);
//         temp = temp->prox;
//     }
    
//     printf("NULL");
// }

// void imprime_rec(celula *le)
// {
//     if (le->prox != NULL)
//     {
//         printf("%d -> ", (le->prox)->info);
//         imprime_rec(le->prox);
//     }
//     else
//         printf("NULL");
// }

void imprime(celula *le) {
    celula *atual = le->prox;

    while (atual != NULL) {
        printf("%d", atual->info);

        if (atual->prox != NULL) {
            printf(" -> ");
        } else {
            printf(" -> NULL");
        }

        atual = atual->prox;
    }
}

// Função para imprimir a lista de forma recursiva
void imprime_rec(celula *le) {
    if (le->prox == NULL) {
        // printf("NULL");
        return;
    }

    printf("%d", le->prox->info);

    if (le->prox->prox != NULL) {
        printf(" -> ");
    } else {
        printf(" -> NULL");
    }

    imprime_rec(le->prox);
}

int main()
{
    int valores_1[] = {1, 7, 9, 10};
    int valores_2[] = {2, 3, 8};
    int valores[] = {0, 0, 0, 0, 0, 0, 0};

    celula *lista_1 = cria_lista_n_nos(4, valores_1);
    celula *lista_2 = cria_lista_n_nos(3, valores_2);
    celula *lista_3 = cria_lista_n_nos(7, valores);

    imprime(lista_1);
    printf("\n");

    imprime(lista_2);
    printf("\n");

    mescla_listas(lista_1, lista_2, lista_3);

    imprime(lista_3);
    printf("\n");

    return 0;
}