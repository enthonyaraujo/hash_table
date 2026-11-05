#include <stdio.h>
#include "tabela.h"

Entrada tabela[m]; // cria o vetor de estruturas com 20.011 posições

// antes de comecar precisamos garantir que a tabela de inicia vazia

void inicializarTabela(void){
    for (int i = 0; i < m; i++)
    {
        tabela[i].palavra[0] = '\0';// transforma a palavra armazenada em uma string vazia
        tabela[i].frequencia = 0; // zera a freq
        tabela[i].estado = VAZIO; 
    }
    
}

// FUNÇÃO DE HASH - DOBRA
int calcularHash(const char *palavra){

    // variaveis auxiliares
    unsigned long long k = 0; // acumula os valores do blocos k = k1 + k2 + k3 ....
    unsigned int k_i = 0; // são os blocos k1, k2, k3, k4 ....
    int contador = 0;

    for (int i = 0; palavra[i] != '\0'; i++) // percorre a palavra toda até chegar no fim dela
    {
        k_i = k_i * 256  + (unsigned char)palavra[i];
        contador++;

        if (contador == 2)
        {
            k += k_i;
            k_i = 0;
            contador = 0;
        }    
    }
    if (contador > 0)
    {
        k += k_i;

    }
    return(int)(k % m); // (h mod m)

}