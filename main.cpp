#include "dic.h"
    using namespace std;



int main() {
    int op, dado;
    char pt[50], en[50];
    No* lista = NULL;

    do {
        printf("Me informe qual operacao deve ser feita: \n");
        printf("0- SAIR DA OPERACAO :\n");
        printf("1- INSERIR NO INICIO :\n");
        printf("2- MOSTRAR DICIONARIO :\n");
        cin>>op;

        switch(op) {
            case 1:
                printf("Informe a palavra em portugues: ");
                cin>>pt;
                  printf("Informe a palavra em ingles: ");
                cin>>en;
                inserir_inicio(pt,en, &lista);
                              
                case 2:
                cout << "\n=== DICIONARIO ===" << endl;
                if (lista == NULL) {
                    cout << "Dicionario vazio!" << endl;
                }else{
                  No* aux = lista;
                 while(aux != NULL) {
        cout<<aux->palavra_pt<<" - > "<<aux->palavra_en<<endl;
        aux = aux->proximo;
        break;}
    }

        }

    } while(op != 0);



    //mostrar lista 
  
    

    

    while(lista != NULL) {
        No* aux = lista;
        lista = lista->proximo;
        free(aux);
    }

    
cout << "Programa encerrado!" << endl;
    return 0;
}