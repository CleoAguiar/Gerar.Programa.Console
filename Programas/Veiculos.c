#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Veiculos.h"

int main()
{
    Dados P;
    FILE *fp;
    int codigo, opcao;
    while(1)
    {
        system("CLS");
        printf("\t\tPrograma Cadastro de Veiculos APC\n");

        printf("\n 1 - Inserir\n 2 - Pesquisar por codigo\n 3 - Listar os Dados\n\n 0 - Sair\n\nOpcao: ");
        scanf ("%d", &opcao);
        system("CLS");
        switch (opcao)
        {
        case 1:
            InserirDadosOrdenado();
            break;
        case 2:
            printf("Digite o codigo: ");
            scanf("%d",&codigo);
            PesquisarDados(fp,codigo);
            break;
        case 3:
            ListarDados(fp);
            break;
        case 0:
            exit(0);
        default:
            printf ("\n OPC%cO INVALIDA\n\n\n",142);
            system("PAUSE");
            system("CLS");
        }
    }
}


Dados DigitarDados()
{
    Dados P;
    Dados aux;
    FILE* fp;
    aux.Codigo=0;
    if ((fp=fopen("Veiculos.dat","ab+"))==NULL)
    {
        printf("Não Abriu o Arquivo!");
        system("PAUSE");
    }
    fseek(fp, 0, SEEK_END);
    fseek(fp, -sizeof(Dados), SEEK_CUR);
    while(ftell(fp)>0)
    {
        fread(&aux, sizeof(Dados), 1, fp);
        if(aux.Codigo>P.Codigo)
        {
            fwrite(&aux, sizeof(Dados), 1, fp);
            fseek(fp, -sizeof(Dados)*3, SEEK_CUR);
        }
        else break;
    }
    printf("Codigo do Veiculos:%d ",aux.Codigo+1);
    P.Codigo=aux.Codigo+1;
    printf ("\nDigite nome: ");
    scanf("%s", P.nome);
    printf ("\nDigite placa: ");
    scanf("%d", &P.placa);
    printf ("\nDigite valor: ");
    scanf("%f", &P.valor);

    return P;
    fclose(fp);
}

void ImpimirDados(Dados P)
{
    printf("\n");

    printf("\nnome: %s",P.nome);
    printf("\nplaca: %d",P.placa);
    printf("\nvalor: %.2f",P.valor);
    printf("\n");
}

Dados PesquisarDados(FILE* fp, int Codigo)
{
    Dados P;
    if ((fp=fopen("Veiculos.dat","ab+"))==NULL)
    {
        printf("Não Abriu o Arquivo!");
        system("PAUSE");
    }
    fseek(fp, 0, SEEK_SET);
    while(fread(&P,sizeof(Dados),1,fp))
    {
        if(Codigo==P.Codigo)
        {
            printf("\nnome: %s",P.nome);
            printf("\nplaca: %d",P.placa);
            printf("\nvalor: %.2f",P.valor);
            printf("\n");
        }
    }
    system("PAUSE");
    fclose(fp);
}
void ListarDados (FILE* fp)
{
    Dados P;
    if ((fp=fopen("Veiculos.dat","ab+"))==NULL)
    {
        printf("Não Abriu o Arquivo!");
        system("PAUSE");
    }
    fseek(fp, 0, SEEK_SET);
    while(fread(&P,sizeof(Dados),1,fp))
    {
        printf("\nnome: %s",P.nome);
        printf("\nplaca: %d",P.placa);
        printf("\nvalor: %.2f",P.valor);
        printf("\n");
    }
    system("PAUSE");
    fclose(fp);
}

void InserirDadosOrdenado (FILE* fp, Dados P)
{
    Dados aux;
    P=DigitarDados();
    if ((fp=fopen("Veiculos.dat","ab+"))==NULL)
    {
        printf("Não Abriu o Arquivo!");
        system("PAUSE");
    }
    fseek(fp, 0, SEEK_END);
    fseek(fp, -sizeof(Dados), SEEK_CUR);
    while(ftell(fp)>0)
    {
        fread(&aux, sizeof(Dados), 1, fp);
        if(aux.Codigo>P.Codigo)
        {
            fwrite(&aux, sizeof(Dados), 1, fp);
            fseek(fp, -sizeof(Dados)*3, SEEK_CUR);
        }
        else break;
    }
    fseek(fp, 0, SEEK_CUR);
    fwrite(&P, sizeof(Dados), 1, fp);
    fclose(fp);
}
