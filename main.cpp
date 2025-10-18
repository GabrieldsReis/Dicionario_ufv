#include "dic.h"
    using namespace std;



int main() {
    int op, dado;
    char pt[50], en[50];
    No* lista = NULL;

 carregar_inicial(&lista);

    do {
        printf("Me informe qual operacao deve ser feita: \n");
        printf("0- SAIR DA OPERACAO :\n");
        printf("1- INSERIR PALAVRA :\n");
        printf("2- REMOVER PALAVRA :\n");
        printf("3- MOSTRAR DICIONARIO :\n");
        printf("4- BUSCA DE PALAVRA :\n");

        cin>>op;

        switch(op) {
            case 1:
                printf("Informe a palavra em portugues: ");
                cin>>pt;
                  printf("Informe a palavra em ingles: ");
                cin>>en;
                inserir_inicio(pt,en, &lista);
                break;
                case 2:
printf("Informe a palavra em portugues para remover: ");
cin>>pt;
remover_palavra(pt,&lista);                
                break;
                case 3:
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
        case 4:
        cout<<"Qual palavra devera ser buscada para traducao ?";
        cin>>pt;
        
        busca_palavra(pt,&lista);
        break;
        
    case 5:
    cin.ignore();
    printf("Digite o texto para traduzir: ");
    cin.getline(texto, 500);
    traduzir_texto(lista, texto);
    break;

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