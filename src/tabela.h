#ifndef TABELA_H
#define TABELA_H

#define m 20011 // quantidade de posições da tabela hash
#define TAM_PALAVRA 64 // quantidade de bytes para armazenar cada palavra

typedef enum{ // criar aqui os 3 possiveis estados para uma posicao na tabela
    VAZIO,
    OCUPADO,
    REMOVIDO
} Estado;

typedef struct entrada // entrada representa uma posicao na tabela
{
    char palavra[TAM_PALAVRA]; // armazena a palavra
    int frequencia; // armazena a quantidade de vezes que aparece
    Estado estado; // indica se esta vazia, ocupada ou removida

} Entrada; 

extern Entrada tabela[m];

void inicializarTabela(void); // funcao de iniciar a tabela
int calcularHash(const char *palavra); // funcao para calcular o valor da hash (posicao)
int h_sondagem(const char *k, int i); // funcao para fazer a sondagem linear (tratar a colisao)
int inserir(const char *palavra); // inserir palavras
int buscar(const char *palavra); // buscar palavras
int remover(const char *palavra); // remover palavras
int atualizar(const char *palavra, int novaFrequencia); // atualizar a frequencia da palavra

#endif