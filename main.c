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

int main(){
    printf("Inicio da Lista!\n");
    /*
    struct Aluno al, a[4] = {
        {2,"Andre",9.5,7.8,8.5},
        {4,"Ricardo",7.5,8.7,6.8},
        {1,"Bianca",9.7,6.7,8.4},
        {3,"Ana",5.7,6.1,7.4}
    };
    */

    Lista* li;
    FILE *arquivo;
    int i;
    //Aluno al;
    Alu al;

    int loop =1;
    int op;
    while(loop == 1){
        printf("\n Sair(0), Criar(1), Abrir(2), Imprimir(3), Add(4), Salvar(5), \n Procurar(6), Editar(7), Remove(8)");
        scanf("%d", &op);
        switch(op){
        case 0: loop = 0; break;
        case 1: li = cria_lista(); arquivo = criar_arquivo(); break;
        case 2: li = cria_lista(); li = ler_arquivo(li);break;
        case 3: imprime_lista(li);break;
        case 4:
            printf("\nAdd Lista");
            printf("\nDig matricula: ");    scanf("%d", &al.matricula);
            printf("\nDig nome: ");         scanf("%s", al.nome);
            printf("\nDig nota1: ");        scanf("%f", &al.n1);
            printf("\nDig nota2: ");        scanf("%f", &al.n2);
            printf("\nDig nota3: ");        scanf("%f", &al.n3);
            insere_lista_final(li, al);
            break;
        case 5:salvar_lista(li);break;
        case 6: procura_lista(li);break;
        case 7: edita_lista(li);break;
        case 8: procura_remove_lista(li); break;
        case 9: break;
        }// fecha menu
    }//fecha loop

    libera_lista(li);
    fechar_arquivo(arquivo);
    printf("\n\n\n\n....\ m /!\n");
    return 0;

}
