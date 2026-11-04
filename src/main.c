#include <stdio.h>
#include "tabela.h"

int main(){
    inicializarTabela();
    printf("Tabela Iniciada....\n");

    for (int i = 0; i < 5; i++)
    {
        printf("Posição %d: ",i);
    
        if (tabela[i].estado == VAZIO){
            printf("VAZIO\n");
        }
        else if (tabela[i].estado == OCUPADO)
        {
            printf("OCUPADO\n");
        }
        else
        {
            printf("OCUPADO\n");
        }
        
        
    }
    
    return 0;
}