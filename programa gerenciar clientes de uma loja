#include <stdio.h>
#include <string.h>
int main(){
   typedef struct {
        char nome[30];
        int codigo;
    }cliente;
    typedef struct {
        int codigo, nconta;
        float vlcompra;
    }dado;
    const int x=5;
    int n=0, i, j, ii, escolha=0, contador=0, y=0, num, posicao=0, excluir=0;
    cliente servico[x];
    dado dados[x];
    
    for(i=0;i<x;i++){
        dados[i].nconta = 0;
    }
    
    i=0;
    while(escolha != 4){
        escolha = 0;
        fflush(stdin);
        printf("\nEscolha:\n 1-Incluir cliente;\n 2-Incluir contas;\n 3-Remover cliente;\n 4-Sair;\n");
        scanf("%d",&escolha);
        switch (escolha)
        {
            case 1:
            y=0;
            while(y!=1){
            contador=0;
            fflush(stdin);
            printf("digite o codigo do cliente: ");
            scanf("%d", &num);
            for(j=0;j<i;j++){
                if(num == servico[j].codigo){
                    contador++;
                }
            }
            if(contador>0){
                  printf("esse código já existe em outro cliente, tente outro:\n");
            }
            else{
                fflush(stdin);
                servico[i].codigo = num;
                dados[i].codigo = num;
                printf("digite o nome do cliente: ");
                gets(servico[i].nome);
                i++;
                y++;
               fflush(stdin);
            }
            
            }
            break;
            case 2:
            y=0;
            while(y!=1){
            contador=0;
            fflush(stdin);
            printf("\ndigite o codigo do cliente: ");
            scanf("%d", &num);
            for(j=0;j<i;j++){
                if(num == servico[j].codigo){
                    contador++;
                    posicao=j;
                }
            }
            if(contador==1){
                printf("\ndigite o numero da conta: ");
                scanf("%d", &dados[posicao].nconta);
                printf("\ndigite o valor da compra: ");
                scanf("%f", &dados[posicao].vlcompra);
                y++;
            }
            else{
                printf("Esse codigo não pertence a nenhum cliente! ");
                y++;
            }
            }
            break;
            
            case 3:
            y=0;
            while(y != 1){
            contador=0;
            printf("\nDigite o codigo do cliente que deseja excluir: ");
            scanf("%d", &n);
            for(j=0;j<i;j++){
                if(n == servico[j].codigo){
                    if(dados[j].nconta == 0){
                        contador++;
                        excluir=j;
                    }
                }
            }
            if(contador > 0){
                for(ii=excluir;ii<x-1;ii++){
                            dados[ii].nconta = dados[ii+1].nconta;
                            dados[ii].codigo = dados[ii+1].codigo;
                            dados[ii].vlcompra = dados[ii+1].vlcompra;
                            servico[ii].codigo = servico[ii+1].codigo;
                            strcpy(servico[ii].nome,servico[ii+1].nome);
                
                }
                printf("\n\nCliente excluido com sucesso! \n");
                y++;
            }
            else{
                printf("\nO cliente de codigo '%d' nao pode ser excluido. \n", n);
                y++;
            }
            }
            
           break;
        
    }
}
    return 0;

}
