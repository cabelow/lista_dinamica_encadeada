/*
    Algoritimo: Lista Encadiada
    Autor: Rafael Mello
    Email: rafaelmello@alunos.utfpr.edu.br

    Descricao: Biblioteca padrão de estrutura de dados do academico

        * Listas

*/

//cria Aluno   //ex: {3,"Ana",5.7,6.1,7.4}
struct Aluno{int matricula; char nome[30]; float n1,n2,n3;};  typedef struct Aluno Alu;

typedef struct elemento* Lista;

//controle de arquivos
FILE *criar_arquivo();
FILE *abrir_arquivo();
FILE *reescrever_arquivo();
int fechar_arquivo(FILE *arquivo);
Lista *ler_arquivo();

//listas
Lista* cria_lista();
void libera_lista(Lista* li);

//add
int insere_lista_final(Lista* li, struct Aluno al);
int insere_lista_inicio(Lista* li, struct Aluno al);
int insere_lista_ordenada(Lista* li, struct Aluno al);

//remove
int remove_lista(Lista* li, int mat);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);


//utilidades
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int lista_cheia(Lista* li);
void imprime_lista(Lista* li);


//manipulacao avancada
int procura_lista(Lista* li);
int edita_lista(Lista* li);
int procura_remove_lista(Lista* li);



