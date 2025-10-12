#include "DIC.H"
#include <bits/stdc++.h>
using namespace std;
No* criar_no(char pt[],char en[]) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    strcpy(novo->palavra_pt, pt);
    strcpy(novo->palavra_en, en);
    return novo;
}

void inserir_inicio(char pt[],char en[], No** cabeca) {
    No* novo = criar_no(pt,en);
    novo->proximo = *cabeca;
    *cabeca = novo;
}

void remover_palavra(char pt[], No** cabeca){

    if (*cabeca == NULL) {
        cout << "Dicionário vazio!" << endl;
        return;
    }
    
    
    if (strcmp((*cabeca)->palavra_pt, pt) == 0) {
        No* temp = *cabeca;
        *cabeca = (*cabeca)->proximo;
        free(temp);
        cout << "Palavra '" << pt << "' removida!" << endl;
        return;
    }
    
    
    No* atual = *cabeca;
    while (atual->proximo != NULL && strcmp(atual->proximo->palavra_pt, pt) != 0) {
        atual = atual->proximo;
    }
    
    if (atual->proximo != NULL) {
        No* temp = atual->proximo;
        atual->proximo = atual->proximo->proximo;
        free(temp);
        cout << "Palavra '" << pt << "' removida!" << endl;
    } else {
        cout << "Palavra '" << pt << "' não encontrada!" << endl;
    }
}