#include "DIC.H"
#include <bits/stdc++.h>
using namespace std;
No* criar_no(char pt[],char en[]) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de aloca├º├úo de mem├│ria!\n");
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

void traduzir_texto(No* cabeca, char texto[]) {
    char copia[300];
    strcpy(copia, texto);
    char* token = strtok(copia, " ");

    while (token != NULL) {
        No* aux = cabeca;
        int encontrado = 0;
        while (aux != NULL) {
            if (strcmp(aux->palavra_pt, token) == 0) {
                cout << aux->palavra_en << " ";
                encontrado = 1;
                break;
            }
            aux = aux->proximo;
        }

        if (!encontrado) {
            cout << token << " ";
        }

        token = strtok(NULL, " ");
    }
    cout << endl;
}
void carregar_inicial(No **cabeca){
    // Palavras básicas (20 originais)
    inserir_inicio("o", "the", cabeca);
    inserir_inicio("eh", "is", cabeca);
    inserir_inicio("sao", "are", cabeca);
    inserir_inicio("eles", "they", cabeca);
    inserir_inicio("nos", "we", cabeca);
    inserir_inicio("voce", "you", cabeca);
    inserir_inicio("eu", "I", cabeca);
    inserir_inicio("ter", "have", cabeca);
    inserir_inicio("fazer", "do", cabeca);
    inserir_inicio("ir", "go", cabeca);
    inserir_inicio("isto", "this", cabeca);
    inserir_inicio("aquilo", "that", cabeca);
    inserir_inicio("aqui", "here", cabeca);
    inserir_inicio("la", "there", cabeca);
    inserir_inicio("um", "one", cabeca);
    inserir_inicio("tudo", "all", cabeca);
    inserir_inicio("mas", "but", cabeca);
    inserir_inicio("porque", "because", cabeca);
    inserir_inicio("muito", "very", cabeca);
    inserir_inicio("tempo", "time", cabeca);

    inserir_inicio("casa", "house", cabeca);
    inserir_inicio("carro", "car", cabeca);
    inserir_inicio("livro", "book", cabeca);
    inserir_inicio("caneta", "pen", cabeca);
    inserir_inicio("mesa", "table", cabeca);
    inserir_inicio("cadeira", "chair", cabeca);
    inserir_inicio("computador", "computer", cabeca);
    inserir_inicio("celular", "cellphone", cabeca);
    inserir_inicio("agua", "water", cabeca);
    inserir_inicio("comida", "food", cabeca);
    inserir_inicio("pao", "bread", cabeca);
    inserir_inicio("leite", "milk", cabeca);
    inserir_inicio("cafe", "coffee", cabeca);
    inserir_inicio("chá", "tea", cabeca);
    inserir_inicio("amigo", "friend", cabeca);
    inserir_inicio("familia", "family", cabeca);
    inserir_inicio("escola", "school", cabeca);
    inserir_inicio("trabalho", "work", cabeca);
    inserir_inicio("dinheiro", "money", cabeca);
    inserir_inicio("cidade", "city", cabeca);
    
    inserir_inicio("pais", "country", cabeca);
    inserir_inicio("mundo", "world", cabeca);
    inserir_inicio("dia", "day", cabeca);
    inserir_inicio("noite", "night", cabeca);
    inserir_inicio("semana", "week", cabeca);
    inserir_inicio("mes", "month", cabeca);
    inserir_inicio("ano", "year", cabeca);
    inserir_inicio("hoje", "today", cabeca);
    inserir_inicio("ontem", "yesterday", cabeca);
    inserir_inicio("amanha", "tomorrow", cabeca);
    inserir_inicio("agora", "now", cabeca);
    inserir_inicio("depois", "after", cabeca);
    inserir_inicio("antes", "before", cabeca);
    inserir_inicio("sempre", "always", cabeca);
    inserir_inicio("nunca", "never", cabeca);
    inserir_inicio("as vezes", "sometimes", cabeca);
    inserir_inicio("frequentemente", "often", cabeca);
    inserir_inicio("raro", "rare", cabeca);
    inserir_inicio("novo", "new", cabeca);
    inserir_inicio("velho", "old", cabeca);
    
    inserir_inicio("jovem", "young", cabeca);
    inserir_inicio("bonito", "beautiful", cabeca);
    inserir_inicio("feio", "ugly", cabeca);
    inserir_inicio("grande", "big", cabeca);
    inserir_inicio("pequeno", "small", cabeca);
    inserir_inicio("alto", "tall", cabeca);
    inserir_inicio("baixo", "short", cabeca);
    inserir_inicio("longo", "long", cabeca);
    inserir_inicio("curto", "short", cabeca);
    inserir_inicio("largo", "wide", cabeca);
    inserir_inicio("estreito", "narrow", cabeca);
    inserir_inicio("pesado", "heavy", cabeca);
    inserir_inicio("leve", "light", cabeca);
    inserir_inicio("rápido", "fast", cabeca);
    inserir_inicio("devagar", "slow", cabeca);
    inserir_inicio("quente", "hot", cabeca);
    inserir_inicio("frio", "cold", cabeca);
    inserir_inicio("quente", "warm", cabeca);
    inserir_inicio("fresco", "cool", cabeca);
    inserir_inicio("molhado", "wet", cabeca);
    
    inserir_inicio("seco", "dry", cabeca);
    inserir_inicio("limpo", "clean", cabeca);
    inserir_inicio("sujo", "dirty", cabeca);
    inserir_inicio("claro", "clear", cabeca);
    inserir_inicio("escuro", "dark", cabeca);
    inserir_inicio("brilhante", "bright", cabeca);
    inserir_inicio("opaco", "dull", cabeca);
    inserir_inicio("duro", "hard", cabeca);
    inserir_inicio("macio", "soft", cabeca);
    inserir_inicio("suave", "smooth", cabeca);
    inserir_inicio("aspero", "rough", cabeca);
    inserir_inicio("doce", "sweet", cabeca);
    inserir_inicio("azedo", "sour", cabeca);
    inserir_inicio("salgado", "salty", cabeca);
    inserir_inicio("amargo", "bitter", cabeca);
    inserir_inicio("gostoso", "tasty", cabeca);
    inserir_inicio("ruim", "bad", cabeca);
    inserir_inicio("bom", "good", cabeca);
    inserir_inicio("excelente", "excellent", cabeca);
    inserir_inicio("terrivel", "terrible", cabeca);
    
    inserir_inicio("facil", "easy", cabeca);
    inserir_inicio("dificil", "difficult", cabeca);
    inserir_inicio("simples", "simple", cabeca);
    inserir_inicio("complexo", "complex", cabeca);
    inserir_inicio("barato", "cheap", cabeca);
    inserir_inicio("caro", "expensive", cabeca);
    inserir_inicio("rico", "rich", cabeca);
    inserir_inicio("pobre", "poor", cabeca);
    inserir_inicio("feliz", "happy", cabeca);
    inserir_inicio("triste", "sad", cabeca);
    inserir_inicio("contente", "glad", cabeca);
    inserir_inicio("nervoso", "nervous", cabeca);
    inserir_inicio("calmo", "calm", cabeca);
    inserir_inicio("animado", "excited", cabeca);
    inserir_inicio("cansado", "tired", cabeca);
    inserir_inicio("descansado", "rested", cabeca);
    inserir_inicio("doente", "sick", cabeca);
    inserir_inicio("saudavel", "healthy", cabeca);
    inserir_inicio("forte", "strong", cabeca);
    inserir_inicio("fraco", "weak", cabeca);
    
    inserir_inicio("inteligente", "smart", cabeca);
    inserir_inicio("burro", "stupid", cabeca);
    inserir_inicio("sabio", "wise", cabeca);
    inserir_inicio("tolo", "foolish", cabeca);
    inserir_inicio("corajoso", "brave", cabeca);
    inserir_inicio("covarde", "coward", cabeca);
    inserir_inicio("generoso", "generous", cabeca);
    inserir_inicio("egoista", "selfish", cabeca);
    inserir_inicio("honesto", "honest", cabeca);
    inserir_inicio("desonesto", "dishonest", cabeca);
    inserir_inicio("educado", "polite", cabeca);
    inserir_inicio("mal-educado", "rude", cabeca);
    inserir_inicio("paciente", "patient", cabeca);
    inserir_inicio("impaciente", "impatient", cabeca);
    inserir_inicio("criativo", "creative", cabeca);
    inserir_inicio("pratico", "practical", cabeca);
    inserir_inicio("organizado", "organized", cabeca);
    inserir_inicio("desorganizado", "disorganized", cabeca);
    inserir_inicio("cuidadoso", "careful", cabeca);
    inserir_inicio("descuidado", "careless", cabeca);
    
    inserir_inicio("ver", "see", cabeca);
    inserir_inicio("olhar", "look", cabeca);
    inserir_inicio("ouvir", "hear", cabeca);
    inserir_inicio("escutar", "listen", cabeca);
    inserir_inicio("falar", "speak", cabeca);
    inserir_inicio("dizer", "say", cabeca);
    inserir_inicio("conversar", "talk", cabeca);
    inserir_inicio("perguntar", "ask", cabeca);
    inserir_inicio("responder", "answer", cabeca);
    inserir_inicio("explicar", "explain", cabeca);
    inserir_inicio("entender", "understand", cabeca);
    inserir_inicio("saber", "know", cabeca);
    inserir_inicio("pensar", "think", cabeca);
    inserir_inicio("acreditar", "believe", cabeca);
    inserir_inicio("duvidar", "doubt", cabeca);
    inserir_inicio("lembrar", "remember", cabeca);
    inserir_inicio("esquecer", "forget", cabeca);
    inserir_inicio("aprender", "learn", cabeca);
    inserir_inicio("ensinar", "teach", cabeca);
    inserir_inicio("estudar", "study", cabeca);
    
    inserir_inicio("trabalhar", "work", cabeca);
    inserir_inicio("descansar", "rest", cabeca);
    inserir_inicio("dormir", "sleep", cabeca);
    inserir_inicio("acordar", "wake", cabeca);
    inserir_inicio("comer", "eat", cabeca);
    inserir_inicio("beber", "drink", cabeca);
    inserir_inicio("cozinhar", "cook", cabeca);
    inserir_inicio("lavar", "wash", cabeca);
    inserir_inicio("limpar", "clean", cabeca);
    inserir_inicio("arrumar", "tidy", cabeca);
    inserir_inicio("comprar", "buy", cabeca);
    inserir_inicio("vender", "sell", cabeca);
    inserir_inicio("pagar", "pay", cabeca);
    inserir_inicio("ganhar", "earn", cabeca);
    inserir_inicio("gastar", "spend", cabeca);
    inserir_inicio("economizar", "save", cabeca);
    inserir_inicio("emprestar", "lend", cabeca);
    inserir_inicio("pedir", "borrow", cabeca);
    inserir_inicio("devolver", "return", cabeca);
    inserir_inicio("trocar", "exchange", cabeca);
    
    inserir_inicio("viajar", "travel", cabeca);
    inserir_inicio("visitar", "visit", cabeca);
    inserir_inicio("chegar", "arrive", cabeca);
    inserir_inicio("partir", "leave", cabeca);
    inserir_inicio("voltar", "return", cabeca);
    inserir_inicio("ficar", "stay", cabeca);
    inserir_inicio("encontrar", "meet", cabeca);
    inserir_inicio("esperar", "wait", cabeca);
    inserir_inicio("procurar", "search", cabeca);
    inserir_inicio("encontrar", "find", cabeca);
    inserir_inicio("perder", "lose", cabeca);
    inserir_inicio("ganhar", "win", cabeca);
    inserir_inicio("jogar", "play", cabeca);
    inserir_inicio("brincar", "play", cabeca);
    inserir_inicio("assistir", "watch", cabeca);
    inserir_inicio("ouvir", "listen", cabeca);
    inserir_inicio("ler", "read", cabeca);
    inserir_inicio("escrever", "write", cabeca);
    inserir_inicio("desenhar", "draw", cabeca);
    inserir_inicio("pintar", "paint", cabeca);
    
    inserir_inicio("cantar", "sing", cabeca);
    inserir_inicio("dançar", "dance", cabeca);
    inserir_inicio("tocar", "play", cabeca);
    inserir_inicio("gostar", "like", cabeca);
    inserir_inicio("amar", "love", cabeca);
    inserir_inicio("odiar", "hate", cabeca);
    inserir_inicio("preferir", "prefer", cabeca);
    inserir_inicio("querer", "want", cabeca);
    inserir_inicio("precisar", "need", cabeca);
    inserir_inicio("desejar", "wish", cabeca);
    inserir_inicio("esperar", "hope", cabeca);
    inserir_inicio("temer", "fear", cabeca);
    inserir_inicio("preocupar", "worry", cabeca);
    inserir_inicio("confiar", "trust", cabeca);
    inserir_inicio("desconfiar", "distrust", cabeca);
    inserir_inicio("respeitar", "respect", cabeca);
    inserir_inicio("desrespeitar", "disrespect", cabeca);
    inserir_inicio("ajudar", "help", cabeca);
    inserir_inicio("atrapalhar", "hinder", cabeca);
    inserir_inicio("proteger", "protect", cabeca);
    
    inserir_inicio("atacar", "attack", cabeca);
    inserir_inicio("defender", "defend", cabeca);
    inserir_inicio("vencer", "win", cabeca);
    inserir_inicio("perder", "lose", cabeca);
    inserir_inicio("competir", "compete", cabeca);
    inserir_inicio("cooperar", "cooperate", cabeca);
    inserir_inicio("concordar", "agree", cabeca);
    inserir_inicio("discordar", "disagree", cabeca);
    inserir_inicio("aceitar", "accept", cabeca);
    inserir_inicio("recusar", "refuse", cabeca);
    inserir_inicio("permitir", "allow", cabeca);
    inserir_inicio("proibir", "forbid", cabeca);
    inserir_inicio("obedecer", "obey", cabeca);
    inserir_inicio("desobedecer", "disobey", cabeca);
    inserir_inicio("elogiar", "praise", cabeca);
    inserir_inicio("criticar", "criticize", cabeca);
    inserir_inicio("culpar", "blame", cabeca);
    inserir_inicio("perdoar", "forgive", cabeca);
    inserir_inicio("esquecer", "forget", cabeca);
    inserir_inicio("comemorar", "celebrate", cabeca);
    
    inserir_inicio("chorar", "cry", cabeca);
    inserir_inicio("rir", "laugh", cabeca);
    inserir_inicio("sorrir", "smile", cabeca);
    inserir_inicio("gritar", "shout", cabeca);
    inserir_inicio("sussurrar", "whisper", cabeca);
    inserir_inicio("calar", "silence", cabeca);
    inserir_inicio("abraçar", "hug", cabeca);
    inserir_inicio("beijar", "kiss", cabeca);
    inserir_inicio("cumprimentar", "greet", cabeca);
    inserir_inicio("despedir", "say goodbye", cabeca);
}