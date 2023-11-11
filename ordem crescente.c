#include <stdio.h>
#include <string.h>

int main(){

    typedef struct
    {
        int codigo, qtd;
        float valor;
        char nome;
    }DADOS;
    const int x = 3;
    int i, j, ordem_cod, ordem_qtd;
    float ordem_valor;
    char ordem_nome;
    
    
    DADOS produto[x];

    for(i=0;i<x;i++)
    {
        fflush(stdin);
        printf("\ndigite o codigo do produto: ");
        scanf("%d", &produto[i].codigo);
        fflush(stdin);
        printf("\ndigite o nome do produto: ");
        gets(produto[i].nome);
        printf("\ndigite a quantidade de produtos: ");
        scanf("%d", &produto[i].qtd);
        printf("\ndigite o valor do produto: ");
        scanf("%f", &produto[i].valor);    
    }
    for(i=0;i<x;i++)
    {
        for(j=0;j<x;j++)
        {
            if(produto[j].codigo > produto[j+1].codigo)
            {
                ordem_cod = produto[j].codigo;
                ordem_qtd = produto[j].qtd;
                ordem_valor = produto[j].valor;
                ordem_nome = produto[j].nome;

                produto[j].codigo = produto[j+1].codigo;
                produto[j].qtd = produto[j+1].qtd;
                produto[j].valor = produto[j+1].valor;
                produto[j].nome = produto[j+1].nome;   

                produto[j+1].codigo = ordem_cod ;
                produto[j+1].qtd = ordem_qtd;
                produto[j+1].valor = ordem_valor;
                produto[j+1].nome = ordem_nome;         

            }
        }
    }
    for(i=0;i<x;i++)
    {
        printf("%d",  produto[i].codigo);
    }

 
    return 0;
}