#include "DIC.H"

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

