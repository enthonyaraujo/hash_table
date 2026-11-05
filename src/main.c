
#include <stdio.h>
#include "tabela.h"

int main(void) {

    inicializarTabela();

    inserir("casa");
    inserir("saca");
    inserir("casa");

    int indice = calcularHash("casa");

    printf("h(casa) = %d\n\n", indice);

    for (int i = 0; i < 3; i++) {

        int posicao = h_sondagem("casa", i);

        if (tabela[posicao].estado == OCUPADO) {
            printf("Posicao %d: %s | Frequencia: %d\n",
                   posicao,
                   tabela[posicao].palavra,
                   tabela[posicao].frequencia);
        }
    }

    printf("Posicao de casa: %d\n", buscar("casa"));
    printf("Posicao de saca: %d\n", buscar("saca"));
    printf("Posicao de bola: %d\n", buscar("bola"));
    return 0;
}
