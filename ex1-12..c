#include <stdio.h>
#include <string.h>

#define DENTRO 1
#define FORA 0

int main(){
    
    char frase[100];
    int cont,lp_inicio[10],lp_fim[10],nl=0,i=0,estado=DENTRO,ni,j=0,a;


    printf("Entre com a frase: ");
    fgets(frase, 100, stdin);

    for(cont=0;cont<strlen(frase);cont++){

        if((frase[cont] == ' ' || frase[cont] == '\n') && estado == FORA){
            lp_inicio[i] = ni;
            i++;
            lp_fim[j] = nl;
            j++;
            nl=0;
            estado = DENTRO;
        }
        else{
            nl++;

            if(estado == DENTRO){
                ni = cont;
                estado = FORA;
            }
        }
    }

    for(cont=0;cont<i;cont++){
        for(a=lp_inicio[cont];a<lp_inicio[cont]+lp_fim[cont];a++){
            printf("%c", frase[a]);
        }
        printf("\n");
    }

    return 0;
}
