#ifndef DIC_H
#define DIC_H

#include <bits/stdc++.h>

typedef struct No {
    char palavra_pt[50];
    char palavra_en[50];
    struct No* proximo;
} No;

// Declarações das funções
No* criar_no(char pt[],char en[]);
void inserir_inicio(char pt[],char en[], No** cabeca);
void remover_palavra(char pt[],No** cabeca);
void busca_palavra(char pt[],No** cabeca);
void traduzir_texto(No *cabeca, char texto[]);

#endif