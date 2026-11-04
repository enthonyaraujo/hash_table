#include <stdio.h>
#include "tabela.h"

Entrada tabela[CAPACIDADE]; // cria o vetor de estruturas com 20.011 posições

// antes de comecar precisamos garantir que a tabela de inicia vazia

void inicializarTabela(void){
    for (int i = 0; i < CAPACIDADE; i++)
    {
        tabela[i].palavra[0] = '\0';// transforma a palavra armazenada em uma string vazia
        tabela[i].frequencia = 0; // zera a freq
        tabela[i].estado = VAZIO; 
    }
    
}