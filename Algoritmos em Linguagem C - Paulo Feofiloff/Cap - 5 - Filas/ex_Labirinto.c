#include <stdio.h>
#include <stdlib.h>

int **Matriz(int n);

void Imprime_Matriz(int **matriz, int n);

void Labirinto(int **matriz, int n);

void Liberar(int **matriz, int n);

int main()
{
    int n = 5;

    int **matriz = Matriz(n);

    Imprime_Matriz(matriz, n); 

    Labirinto(matriz, n);

    Liberar(matriz, n);
}

int **Matriz(int n)
{
    int i, j;

    int labirinto[5][5] = {
    { 0,-1, 0, 0, 0},
    { 0,-1, 0,-1, 0},
    { 0, 0, 0,-1, 0},
    {-1,-1,-1,-1, 0},
    {-1,-1,-1,-1, 1}
    };

    int **matriz = malloc(n * sizeof(int*));
    matriz[0] = malloc(n * n * sizeof(int));

    for(i = 0; i < n; i++) 
    {
        matriz[i] = matriz[0] + i * n;
        for(j = 0; j < n; j++)
        {
            matriz[i][j] = labirinto[i][j];
        }
    }


    return matriz;
}


void Labirinto(int **matriz, int n)
{
    int i = 0, j = 0, c, b, d, e, k;
    int *formiga = &matriz[0][0];

    while (*(formiga + i * n + j) != 1)
    {
            
        printf("Posicao atual: %d %d\n", i, j);
        printf("Valor atual: %d\n", *(formiga + i * n + j));
        
        k = 0;

        c = i - 1;
        b = i + 1;
        d = j + 1;
        e = j - 1;
 
        
        if(c >= 0 && k == 0)
        {
            if(*(formiga + c * n + j) == 0)
            {
                *(formiga + i * n + j) = 2; 
                i = c;
                k++;
            }
        }

        if(b < n && k == 0)
        {
            if(*(formiga + b * n + j) == 0 || *(formiga + b * n + j) == 1)
            {
                *(formiga + i * n + j) = 2;
                i = b;
                k++;
            }
        }

        if(d < n && k == 0) 
        {
            if(*(formiga + i * n + d) == 0 || *(formiga + i * n + d) == 1)
            {
               *(formiga + i * n + j) = 2;
                j = d;
                k++;
            }  
        }
        if(e >= 0 && k == 0)
        {
            if(*(formiga + i * n + e) == 0)
            {
                *(formiga + i * n + j) = 2;
                j = e;
                k++;
            }  
        }
        printf("\n");
        Imprime_Matriz(matriz, n);
    }
    Imprime_Matriz(matriz, n);
}


void Imprime_Matriz(int **matriz, int n)
{
    int i, j;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {            
            if(matriz[i][j] == 0 || matriz[i][j] == 1 || matriz[i][j] == 2) printf(" %d ", matriz[i][j]);
            else printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    system("pause");
    system("cls");
}


void Liberar(int **matriz, int n)
{   
    int i;
    for(i = 0; i < n; i++) free(matriz[i]);

    free(matriz);
}
