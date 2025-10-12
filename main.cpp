#include "dic.h"

int main() {
    int op, dado;
    No* lista = NULL;

    do {
        printf("Me informe qual operacao deve ser feita: \n");
        printf("0- SAIR DA OPERACAO :\n");
        printf("1- INSERIR NO INICIO :\n ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                printf("Informe o valor a ser inserido no inicio: ");
                scanf("%d", &dado);
                inserir_inicio(dado, &lista);
        }
    } while(op != 0);



    //mostrar lista 
    No* aux = lista;
    while(aux != NULL) {
        printf("%d -> ", aux->valor);
        aux = aux->proximo;
    }

    while(lista != NULL) {
        No* aux = lista;
        lista = lista->proximo;
        free(aux);
    }

    return 0;
}