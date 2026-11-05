#include <string.h>
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
    unsigned int bloco = 0; // são os blocos k1, k2, k3, k4 ....
    int contador = 0;

    for (int i = 0; palavra[i] != '\0'; i++) // percorre a palavra toda até chegar no fim dela
    {
        bloco = bloco * 256  + (unsigned char)palavra[i];
        contador++;

        if (contador == 2)
        {
            k += bloco;
            bloco = 0;
            contador = 0;
        }    
    }
    if (contador > 0)
    {
        k += bloco;

    }
    return(int)(k % m); // (h(k) mod m)
}

//funcao para fazer a sondagem linear
int h_sondagem(const char *k, int i) {
    return (calcularHash(k) + i) % m;
}

// função inserir
int inserir(const char *palavra){

    if (palavra == NULL || palavra[0] == '\0')
    {
        return -1;
    }
    if (strlen(palavra) >= TAM_PALAVRA)
    {
        return -1;
    }

    int primeiroRemovido = -1;

    for (int i = 0; i < m; i++)
    {
        // chama a funcao sondagem e faz a sondagem linear
        int posicao = h_sondagem(palavra,i);
        
        // verificar se a posição na tabela que a palavra vai está ocupada
        if (tabela[posicao].estado == OCUPADO)
        {
            // se tiver ocupado, precisamos verificar tambem se a palavra ja existe
            if (strcmp(tabela[posicao].palavra, palavra) == 0){
                tabela[posicao].frequencia++;
                return 0;
            }

        }

        // verificar se esta removida
        else if (tabela[posicao].estado == REMOVIDO)
        {
            if (primeiroRemovido == -1)
            {
                primeiroRemovido = posicao;
            }
            
        }
        
        // verificar se a posicao esta vazia
        else
        {
            if (primeiroRemovido != -1)
            {
                posicao = primeiroRemovido;
            }

            strcpy(tabela[posicao].palavra, palavra);
            tabela[posicao].frequencia = 1;
            tabela[posicao].estado = OCUPADO;

            return 1;
        }
    }

    // caso só existam posições ocupadas ou removidas
    if (primeiroRemovido != -1) {

    strcpy(tabela[primeiroRemovido].palavra, palavra);
    tabela[primeiroRemovido].frequencia = 1;
    tabela[primeiroRemovido].estado = OCUPADO;

    return 1;
    }
    // se a tabela estiver cheia
    return -1;
}


int buscar(const char *palavra) {

    // aqui verifica se a palavra é válida
    if (palavra == NULL || palavra[0] == '\0') {
        printf("Palavra Invalida\n");
        return -1;
    }

    // percorre a sequência de sondagem
    for (int i = 0; i < m; i++) {

        int posicao = h_sondagem(palavra, i);

        // se a posição nunca utilizada a palavra não é encontrada
        if (tabela[posicao].estado == VAZIO) {
            return -1;
        }

        // verifica se a posição contém a palavra
        if (tabela[posicao].estado == OCUPADO) {

            if (strcmp(tabela[posicao].palavra, palavra) == 0) {
                return posicao;
            }
        }
    }

    return -1;
}

int remover(const char *palavra){

    int posicao = buscar(palavra); //precisamos procurar a palavra na tabela primeiro

    if (posicao == -1)
    {
        return -1; // invalido
    }

    // limpar os dados da palavra
    tabela[posicao].palavra[0] = '\0';
    tabela[posicao].frequencia = 0;

    // depois de limpar atualiza o estado
    tabela[posicao].estado = REMOVIDO;

    return 1;
}
