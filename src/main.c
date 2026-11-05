#include <stdio.h>
#include "tabela.h"

int main(void) {

    inicializarTabela();

    inserir("casa");
    inserir("saca");
    inserir("casa");

    atualizar("saca", 5);

    printf("ANTES DA REMOCAO\n");
    exibirEstrutura();

    remover("casa");

    printf("\nDEPOIS DA REMOCAO\n");
    exibirEstrutura();

    return 0;
}
