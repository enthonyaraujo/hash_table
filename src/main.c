#include <stdio.h>
#include "tabela.h"

int main(){
    inicializarTabela();
    printf("Tabela Iniciada....\n");

    printf("casa: %d\n", calcularHash("casa"));
    printf("saca: %d\n", calcularHash("saca"));
    printf("dado: %d\n", calcularHash("dado"));
    
    return 0;
}