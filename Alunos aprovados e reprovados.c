//Programa pra um professor cadastrar alunos, e ver se foram aprovados ou não, no menu é possível escolher:

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    typedef struct{
        char nome[20], email[30];
        float nota1, nota2;
        int chamada, faltas;
    }alunos;

    const int x = 3;
    alunos dados[x];
    int i, j=0, escolha, escolha2, escolha3, chamada=0, chamada2=0, posicao=0, aux=0, aux2=0, faltasaux=0, contador, nIgual, qtdfaltas=0, maiorfalta=0;
    char nomeaux[20], menu[20], excluir[20], excluiraux[20];
    float media=0.0, mediaaux=0.0;
    strcpy(excluiraux, "1");

    while(escolha != 5){
        escolha = 0;
        fflush(stdin);
        printf("\n------------------------- menu ------------------------- \n\nEscolha: \n\n 1-Para cadastrar alunos:\n 2-Para excluir aluno: \n 3-Para Buscar aluno:\n 4-Para ver estatus dos alunos cadastrados:\n 5-Para sair:\n");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
        if(j<x){
        fflush(stdin);
        printf("\ndigite o nome do aluno: ");
        gets(dados[j].nome);
        fflush(stdin);
        printf("\ndigite o email do aluno: ");
        gets(dados[j].email);
        int nIgual=0;
        do{
            nIgual=0;
            int matricula=0;
            printf("\nDigite o numero da chamada: ");
            scanf("%d", &matricula);
            for( i=0; i<j; i++){
                if(matricula==dados[i].chamada){
                    nIgual++;
                }
            }
            if(nIgual>0){
                printf("\nNumero repetido\n");
            }
            else{
                dados[j].chamada=matricula;
            }
        }while(nIgual>0);
        fflush(stdin);
        printf("\ndigite a nota da primeira prova: ");
        scanf("%f", &dados[j].nota1);
        printf("\ndigite a nota da segunda prova: ");
        scanf("%f", &dados[j].nota2);
        printf("\ndigite o numero de faltas: ");
        scanf("%d", &dados[j].faltas);
        system("cls");

        j++;
        }
        else{
            printf("\n numero de alunos exedido! ");
        }
        break;
        case 2:
            printf("\n Escolha\n\n 1-Para excluir um aluno pelo numero de chamada: ");
            printf("\n 2-Para excluir o aluno com maior numero de faltas: \n");
            scanf("%d",&escolha3);
            switch(escolha3){
                case 1:
                contador=0;
                do{
                    printf("digite o numero da chamada do aluno que deseja excluir: ");
                    scanf("%d",&chamada);
                    for(i=0;i<j;i++){
                        if(chamada == dados[i].chamada){
                            contador++;
                            posicao = i;
                        }
                    }
                    if(contador > 0){
                        for(i=posicao;i<j;i++){
                            dados[i].chamada = dados[i+1].chamada;
                            strcpy(dados[i].email,dados[i+1].email);
                            dados[i].faltas = dados[i+1].faltas;
                            dados[i].nota1 = dados[i+1].nota1;
                            dados[i].nota2 = dados[i+1].nota2;
                            strcpy(dados[i].nome,dados[i+1].nome);
                            
                        }
                        j--;
                        printf("\naluno excluido com sucesso! ");
                    }
                    else{
                        printf("\naluno nao encontrado, essa chamada nao existe, tente novamente...\n");
                    }
                }while(contador == 0);
                break;
                case 2:
                    nIgual=0;
                    for(i=0;i<j;i++){
                        if(dados[i].faltas > qtdfaltas){
                            maiorfalta = i;
                        }
                    }
                    printf("\no aluno com maior numero de faltas e: ");
                    fflush(stdin);
                    printf("\naluno: %s, chamada: %d, nota 1: %0.2f, nota 2: %0.2f, media: %0.2f, faltas: %d\n", dados[maiorfalta].nome, dados[maiorfalta].chamada, dados[maiorfalta].nota1, dados[maiorfalta].nota2, (dados[maiorfalta].nota1 + dados[maiorfalta].nota2)/2, dados[maiorfalta].faltas);
                    fflush(stdin);
                    printf("\ndigite '1' se tem certeza que deseja excluir ou qualquer coisa caso nao queira: ");
                    gets(excluir);
                    aux2 = strcmp(excluir, excluiraux);
                    if(aux2 == 0){
                        nIgual++;
                    }
                    if(nIgual != 0){
                        for(i=maiorfalta;i<j;i++){
                            dados[i].chamada = dados[i+1].chamada;
                            strcpy(dados[i].email,dados[i+1].email);
                            dados[i].faltas = dados[i+1].faltas;
                            dados[i].nota1 = dados[i+1].nota1;
                            dados[i].nota2 = dados[i+1].nota2;
                            strcpy(dados[i].nome,dados[i+1].nome);        
                        }
                        j--;
                        printf("\naluno excluido com sucesso! ");
                        fflush(stdin);
                    }
                    else{
                        fflush(stdin);
                        printf("aluno nao excluido!");
                    }
                    break;
                    


                }
                break;
        
        case 3:
            escolha2=0;
            printf("\n\n Escolha:\n\n 1-para pesquisar por numero de chamada:\n 2-para pesquisar pelo nome:\n  \n- ou digite qualquer coisa para voltar ao menu:\n\n");
            scanf("%d", &escolha2);
            switch(escolha2){
                case 1:
                do{
                fflush(stdin);
                printf("\ndigite o numero da chamada do aluno: ");
                scanf("%d", &chamada2);
                
                    nIgual = 0;
                    for(i=0; i<j; i++){
                        if(chamada2 == dados[i].chamada){
                            nIgual++;
                            posicao = i;
                        }
                    }
                    if(nIgual==0){
                        printf("\naluno nao encontrado, chamda nao cadastrada tente novamente... ");
                    }
                    else{
                        fflush(stdin);
                        printf("\naluno: %s, chamada: %d, nota 1: %0.2f, nota 2: %0.2f, media: %0.2f, faltas: %d\n", dados[posicao].nome, dados[posicao].chamada, dados[posicao].nota1, dados[posicao].nota2, (dados[posicao].nota1 + dados[posicao].nota2)/2, dados[posicao].faltas);
                        printf("\nseu email e: %s", dados[posicao].email);
                        printf("\n\ndigite qualquer coisa para voltar ao menu: ");
                        gets(menu);
                        system("cls");
                    }
                }while(nIgual == 0);
                break;

                case 2:
                    do{
                        fflush(stdin);
                        printf("digite o nome do aluno: ");
                        gets(nomeaux);

                        nIgual=0;
                        for(i=0;i<j;i++){
                            aux = strcmp(nomeaux, dados[i].nome);
                            if( aux == 0){
                                nIgual++;
                                posicao = i;
                            }
                        }
                        if(nIgual == 0){
                            fflush(stdin);
                            printf("\naluno nao cadastrado! ");
                            fflush(stdin);
                        }
                        else{
                            printf("\naluno: %s, chamada: %d, nota 1: %0.2f, nota 2: %0.2f, media: %0.2f faltas: %d\n", dados[posicao].nome, dados[posicao].chamada, dados[posicao].nota1, dados[posicao].nota2, (dados[posicao].nota1 + dados[posicao].nota2)/2, dados[posicao].faltas);
                            printf("\nseu email e: %s", dados[posicao].email);
                            fflush(stdin);
                            printf("\n\ndigite qualquer coisa para voltar ao menu: ");
                            gets(menu);
                            system("cls");
                        }
                        

                    }while(nIgual == 0);
                    break;
                    
                    default :
                    printf("\ndigite qualquer coisa para voltar ao menu: ");
                    gets(menu);
                    system("cls");
                    break;
            }
        break;
        
        case 4:
            fflush(stdin);
            printf("\ndigite a media para passar: ");
            scanf("%f", &mediaaux);
            printf("\ndigite a quantidade maxima de faltas: ");
            scanf("%d", &faltasaux);
            system("cls");
            printf("\nLISTA DE APROVADOS E REPROVADOS:\n");
            fflush(stdin);
            for(i=0;i<j;i++){
                media = (dados[i].nota1 + dados[i].nota2)/2;
                if(media >= mediaaux && dados[i].faltas <= faltasaux){
                        fflush(stdin);
                        printf("\nAPROVADO: aluno: %s, chamada: %d, nota 1: %0.2f, nota 2: %0.2f, media: %0.2f faltas: %d\n", dados[i].nome, dados[i].chamada, dados[i].nota1, dados[i].nota2, media, dados[i].faltas);   
                }
                else{
                        fflush(stdin);
                        printf("\nREPROVADO: aluno: %s, chamada: %d, nota 1: %0.2f, nota 2: %0.2f, media: %0.2f faltas: %d\n", dados[i].nome, dados[i].chamada, dados[i].nota1, dados[i].nota2, media, dados[i].faltas);
                }
            }
            printf("\n\ndigite qualquer coisa para voltar ao menu: ");
            gets(menu);
            system("cls");
            break;
            

        case 5:
            break;

        default :
            system("cls");
            printf("essa escolha nao e valida, tente novamente; \n\n");
            break;

        }
        }
       
    
    return 0;
}
