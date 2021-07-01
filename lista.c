/*
    Algoritimo: Lista Encadiada
    Autor: Rafael Mello
    Email: rafaelmello@alunos.utfpr.edu.br

    Descricao: Lista encadiada

*/


#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#include"lista.h"


struct elemento{                    //Elementos de um struct, basta troca-la
    struct Aluno dados;             //A struct vira dados
    struct elemento *prox;          //Os elementos tem proximo
};typedef struct elemento Elemento;

typedef struct elemento* Lista;//criando uma lista de elementos



Lista* cria_lista(){//função de criar uma lista na memoria
    Lista* li = (Lista*) malloc(sizeof(Lista)); //maloca a cabeça da lista
    if(li != NULL){*li = NULL;} //Inicio da lista tem q ser vazio
    return li;//retorna a lista pra principal
}//fim cria_lista






void libera_lista(Lista* li){   //função para destruir a lista
    if(li != NULL){             //se ela nao estiver vazia
        Elemento* no;           //cria um no
        while((*li) != NULL){   //enquanto a lista nao for nula
            no = *li;           //nó recebe conteudo da lsta
            *li = (*li)->prox;  //a lista recebe o proximo
            free(no);           //libera o no
        }free(li);              //por fim libera a lista
    }
}//fim insere_lista_inicio




int insere_lista_final(Lista* li, struct Aluno al){

    if(li == NULL) {return 0;}                          //e a lista for nula retorna
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));//malocar um struc na memoria
    if(no == NULL) {return 0;}   //Se der erro ao malocar, retorna

    no->dados = al;              //preenche dados
    no->prox = NULL;             //recebe null pq será o ultimo da lista

    if((*li) == NULL){ *li = no;}//lista vazia: insere início


    else{               //se nao procura ate achar o nifal
        Elemento*aux;   //crio um aux pra rodar
        aux = *li;      //copio da lista
        //roda ate aux->prox == null - fim da lista
        while(aux->prox != NULL){ aux = aux->prox; }
        aux->prox = no; //depois de rodar ate o fim, ele recebe o nó - os dados
    }

    return 1;
}//fim inserer_lista_final





int insere_lista_inicio(Lista* li, struct Aluno al){ //função para inserir no incio
    if(li == NULL){return 0;}                   //se a lista nao for criada
    Elemento* no;                               //cria um nó
    no = (Elemento*) malloc(sizeof(Elemento));  //maloca ele na memoria
    if(no == NULL) {return 0;}                  //testo o no

    no->dados = al;     //preenche os dados
    no->prox = (*li);   //o proximo deste cara recebe quem a lista apontava, antigo primeiro elementos
    *li = no;           //lista aponta para o novo nó
    return 1;
}




int insere_lista_ordenada(Lista* li, struct Aluno al){
    if(li == NULL){return 0;} //testo a se a lista é nula
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));//crio um novo nó para inserir
    if(no == NULL){return 0;} //testo se maloco

    no->dados = al;//preencho os dados
    if((*li) == NULL){ //lista vazia: insere início
        no->prox = NULL;
        *li = no;
        return 1;
    }
    else{
        Elemento *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){//insere início
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}





int remove_lista(Lista* li, int mat){
    if(li == NULL){return 0;}
    if((*li) == NULL){return 0;}//lista vazia
    Elemento *ant, *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if(no == NULL){return 0;}//não encontrado
    if(no == *li){*li = no->prox;}//remover o primeiro?
    else {ant->prox = no->prox;}
    free(no);
    return 1;
}





int remove_lista_inicio(Lista* li){
    if(li == NULL) {return 0;}
    if((*li) == NULL){return 0;}//lista vazia

    Elemento *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}






int remove_lista_final(Lista* li){
    if(li == NULL) {return 0;}
    if((*li) == NULL){return 0;}//lista vazia


    Elemento *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    if(no == (*li)) {*li = no->prox;} //remover o primeiro?
    else {ant->prox = no->prox;}
    free(no);
    return 1;
}





int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elemento* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}



int lista_cheia(Lista* li){return 0;}




int lista_vazia(Lista* li){
    if(li == NULL) return 1;
    if(*li == NULL)return 1;
    return 0;
}




void imprime_lista(Lista* li){
    if(li == NULL)return;
    Elemento* no = *li;
    while(no != NULL){
        printf("\n\n");
        printf("\nMatricula: %d ", no->dados.matricula);
        printf("\nNome: %s", no->dados.nome);
        printf("\nNotas? %.2f \t %.2f \t %.2f", no->dados.n1, no->dados.n2, no->dados.n3);
        printf("\n...............................................\n");
        no = no->prox;
    }
}




FILE *criar_arquivo(FILE *arquivo){// função de criar um arquivo para a lista
    //FILE *arquivo;

    char nome[30]; scanf("%s", &nome); //nome de entrada do usuario
    char titulo[36];                    //vai ser montado abaixo
    //compila o nome na estrutura src/nome_do_arquivo.txt
    strcpy(titulo,"src/"); strcat(titulo,nome); strcat(titulo,".txt"); //printf("%s", titulo);

    arquivo = fopen(titulo,"r"); //abri para ver se existe um com este nomo
    if(arquivo = NULL){ printf("\nArquivo ja existente!");}//avisa q ja exites
    else {arquivo = fopen(titulo, "w");} //cria se nao existir

    return arquivo;//retorna o arquivo criado ou o arquivo achado
}//fim cria_arquivo





FILE *abrir_arquivo(){//Função de abrir arquivo, recebe ponteiro como paremetro
    FILE *arquivo;
    char nome[30];
    printf("\nDig nome do arquivo: ");
    scanf("%s", &nome);

    char titulo[36];    //vai ser montado abaixo
    //compila o nome na estrutura src/nome_do_arquivo.txt
    strcpy(titulo,"src/"); strcat(titulo,nome); strcat(titulo,".txt");printf("%s", titulo);

    arquivo = fopen(titulo,"r"); //procura o arquivo para a leitura
    if(arquivo == NULL){
        //arquivo = fopen(titulo,"w+");
        printf("\nArquivo nao foi encontrado!");
        return 0;
    }
    else {arquivo = fopen(titulo, "r+");}

    return arquivo;
}//fim abrir_arquivo

FILE *reescrever_arquivo(){//Função de abrir arquivo, recebe ponteiro como paremetro
    FILE *arquivo;
    char nome[30];
    printf("\nDig nome do arquivo: ");
    scanf("%s", &nome);

    char titulo[36];    //vai ser montado abaixo
    //compila o nome na estrutura src/nome_do_arquivo.txt
    strcpy(titulo,"src/"); strcat(titulo,nome); strcat(titulo,".txt");printf("%s", titulo);

    arquivo = fopen(titulo,"r"); //procura o arquivo para a leitura
    if(arquivo == NULL){
        arquivo = fopen(titulo,"w+");
        printf("\nArquivo nao foi encontrado mas foi criado!");
        return 0;
    }
    else {arquivo = fopen(titulo, "w+");}

    return arquivo;
}//fim abrir_arquivo




int fechar_arquivo(FILE *arquivo){
    if(arquivo != NULL) return 0;
    else fclose(arquivo); return 1;
}


void salvar_lista(Lista *li){
    if(li == NULL){exit(0);}//se for vazio nao salva

    FILE *arquivo;
    arquivo = reescrever_arquivo();


    if(arquivo == NULL) printf("\nArquivo nao encontrado");
    else{ printf("\nsalvando a lista no HD...");
        Elemento* no = *li; //criar um nó pra ajudar
        while(no != NULL){printf("\n entro aqui...");
            fprintf(arquivo, "%d %s %f %f %f \n", no->dados.matricula, no->dados.nome, no->dados.n1, no->dados.n2, no->dados.n3);
            no = no->prox;
        }
    }
    fechar_arquivo(arquivo);
}


Lista* ler_arquivo(Lista *li){
    printf("\nProcurar por arquivo...");
    FILE *arquivo;
    arquivo = abrir_arquivo();

    struct Aluno al;
    if(arquivo == NULL){printf("\nArquivo nao encontrado");}
    else {
        int cont =0;
        while(fscanf(arquivo, "%d %s %f %f %f \n", &al.matricula, al.nome, &al.n1, &al.n2, &al.n3) != EOF){
            insere_lista_final(li, al);
        }
    }
    return li;
}


int procura_lista(Lista* li){
    if (li == NULL) return 0;
    int pesquisa; printf("\n dig a matricula"); scanf("%d", &pesquisa);

    Elemento* no = *li;
    while(no != NULL){
        if(no->dados.matricula == pesquisa){
            printf("\n\n");
            printf("\nMatricula: %d \n", no->dados.matricula);
            printf("\nNome: %s", no->dados.nome);
            printf("\nNotas? %.2f \t %.2f \t %.2f", no->dados.n1, no->dados.n2, no->dados.n3);
            printf("\n...............................................\n");
        }
        no = no->prox;
    }
    return 1;
}

int edita_lista(Lista* li){
    if (li == NULL) return 0;
    int pesquisa; printf("\n dig a matricula"); scanf("%d", &pesquisa);

    Elemento* no = *li;
    while(no != NULL){
        if(no->dados.matricula == pesquisa){printf("\n\n");
            printf("\nMatricula: %d \n", no->dados.matricula);
            printf("\nNome: %s", no->dados.nome);
            printf("\nNotas? %.2f \t %.2f \t %.2f", no->dados.n1, no->dados.n2, no->dados.n3);
            printf("\n...............................................\n");

            printf("\n Dig nome:  ");       scanf("%s", &no->dados.nome);
            printf("\n Dig nota1: ");       scanf("%f", &no->dados.n1);
            printf("\n Dig nota2: ");       scanf("%f", &no->dados.n2);
            printf("\n Dig nota3: ");       scanf("%f", &no->dados.n3);
        }
        no = no->prox;
    }
    return 1;
}


int procura_remove_lista(Lista* li){
    if(li == NULL) return 0;
    if((*li) == NULL)return 0;
    int mat; printf("\nDig matricula? "); scanf("%d", &mat);
    Elemento *ant, *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if(no == NULL)return 0;//não encontrado

    if(no == *li)*li = no->prox; //remover o primeiro?
    else ant->prox = no->prox;
    free(no);
    return 1;
}
