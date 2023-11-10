#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

// static void insertionsortH(Item *v,int l,int r,int h)
// {
//   for(int i=l+h;i<=r;i++)
//   {
//     int j=i; Item tmp=v[j];
//     while(j>=l+h && less(tmp,v[j-h]))
//     {
//       v[j]=v[j-h];
//       j-=h;
//     }
//     v[j]=tmp;
//   }
// }

// void shellsort(Item *v,int l,int r)
// {
//   int h;
//   int t=(r-l)+1;
//   for(h=1;h<=(t-1)/9;h=3*h+1);
//   for(;h>0;h/=3)
//     insertionsortH(v,0,t-1,h);
// }

void shell_sort(int *v, int l, int r)
{
    int h;

    for (h = 1; h <= (r - l) / 9; h = 3 * h + 1);

    for (; h > 0; h / 3)
        for (int i = l + h; i < r; i++)
        {
            for (int j = i; j > l + h && v[j] < v[j - h]; j -= h)
            {
                int t = v[j];
                v[j] = v[j - h];
                v[j - h] = t;
            }
        }
}


int main()
{
    int *vetor = malloc(50001 * sizeof(int));
    int numero;
    int i;

    for (i = 0; scanf("%d", &numero) != EOF; i++)
        vetor[i] = numero;

    shell_sort(vetor, 0, i);

    printf("%d", vetor[1]);
 
    for (int j = 2; j <= i; j++)
        printf(" %d", vetor[j]);

    printf("\n");

    return 0;
}