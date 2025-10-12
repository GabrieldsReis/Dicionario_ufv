#include "DIC.H"

No* criar_no(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
}

void inserir_inicio(int valor, No** cabeca) {
    No* novo = criar_no(valor);
    novo->proximo = *cabeca;
    *cabeca = novo;
}