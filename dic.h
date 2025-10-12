#ifndef DIC.H
#define DIC.H

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

// Declarações das funções
No* criar_no(int valor);
void inserir_inicio(int valor, No** cabeca);

#endif