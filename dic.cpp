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
        cout << "Dicionario vazio!" << endl;
        return;
    } 

    
    if (strcmp((*cabeca)->palavra_pt, pt) == 0) { //faz a comparacao de palavra da lista, com 'pt' fornecido pelo usuario.
        No* aux = *cabeca;
        *cabeca = (*cabeca)->proximo;
        free(aux);
        cout << "Palavra '" << pt << "' removida!" << endl;
        return;
    }
    
    
    No* atual = *cabeca;
    while (atual->proximo != NULL && strcmp(atual->proximo->palavra_pt, pt) != 0) {
        atual = atual->proximo;
    }
    
    if (atual->proximo != NULL) {
        No* aux = atual->proximo;
        atual->proximo = atual->proximo->proximo;
        free(aux);
        cout << "Palavra '" << pt << "' removida!" << endl;
    } else {
        cout << "Palavra '" << pt << "' nao encontrada!" << endl;
    }
}

void busca_palavra(char pt[],No** cabeca){
    if(*cabeca == NULL){
        printf("Dicionario Vazio!\n");
        return;
    }
No* aux = *cabeca;
int encontrado = 0;
      while(aux != NULL){
if(strcmp((aux)->palavra_pt,pt) == 0){
       
      
        cout<<"A palavra "<< aux->palavra_pt << " em ingles eh: " << aux->palavra_en<< endl;
    encontrado = 1;
        break;
    }

    aux = aux->proximo;
      }
    if(!encontrado){
        printf("Palavra nao encontrada!\n");
    }

}

void traduzir_texto(No *cabeca, char texto[]) {
    char copia[500];
    strcpy(copia, texto);
    char *token = strtok(copia, " ");

    while(token != NULL) {
        No *aux = cabeca;
        int encontrado = 0;

        while(aux != NULL) {
            if(strcmp(aux->palavra_pt, token) == 0) {
                printf("%s ", aux->palavra_en);
                encontrado = 1;
                break;
       }
            aux = aux->proximo;
   }

        if(!encontrado){
            printf("%s ", token);

        token = strtok(NULL, " ");
    }

    printf("\n");
}
