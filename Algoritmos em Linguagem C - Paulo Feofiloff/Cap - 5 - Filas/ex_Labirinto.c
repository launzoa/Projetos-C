#include <stdio.h>
#include <stdlib.h>

int **Matriz(int n);

void Imprime_Matriz(int **matriz, int n);

int Labirinto(int **matriz, int n);

void Liberar(int **matriz, int n);

int main()
{
    int n = 5;

    int **matriz = Matriz(n);

    Imprime_Matriz(matriz, n); 
    
    printf("A distancia encontrada para a formiga chegar ate o destino foi de %d passos", Labirinto(matriz, n));

    Liberar(matriz, n);
}

int **Matriz(int n)
{
    int i, j;

    int labirinto[5][5] = {
    { 0,-1, 0, 0, 0},
    { 0,-1, 0,-1, 0},
    { 0, 0, 0,-1, 0},
    { -1,-1,-1,-1, 0},
    { -1, -1, -1, -1, 1}
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


int Labirinto(int **matriz, int n)
{
    int cima, baixo, direita, esquerda, k = 0, i = 0, j = 0;
    
    int *fila = malloc(n * n * sizeof(int));
    int *formiga = fila[0] = &matriz[0][0];
    
    while(1)
    {   
        formiga = fila[k];

        if(*formiga == 1) break;

        cima = *(formiga - n);
        if(cima == 0 && i != 0)
        {
            fila[++k] = &*(formiga - n);
            
        }

        baixo = *(formiga + n);
        if(baixo == 0 || baixo == 1 && i != n-1)
        {
            fila[++k] = &*(formiga + n);
            
        }

        direita = *(formiga + 1);
        if(direita == 0 || direita == 1 && j != n-1)
        {
            fila[++k] = &*(formiga + 1);
        }

        esquerda = *(formiga - 1);
        if(esquerda == 0 && j != 0)
        {
            fila[++k] = &*(formiga - 1);
        }

        (cima == 0 && i != 0) ? i-- : i;
        (baixo == 0 && i != n-1) ? i++ : i;
        (direita == 0 && j != n-1) ? j++ : j;
        (esquerda == 0 && j != 0) ? j-- : j;
        *formiga = 2;

        Imprime_Matriz(matriz, n);
    }
    return k;
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
