#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "project.h"

int main()
{
Progm pgm;
FILE *arqC, *arqH;
int m, i=0, saida, a=0, arqCriar;
char novos, confirm, criar, remov[60], complemento[300];
strcpy(complemento, "\0");
system("mkdir Programas");
system("CLS");
m=menu();
if (m==1){
pgm=digitar_nomes();
arqC=criar_arquivoC(pgm.nome, pgm.titulo);
arqH=criar_arquivoH(pgm.nome);
if (arqC==NULL || arqH==NULL) {
        system("CLS");
        printf("\n\t\tErro! Nao foi possivel criar o arquivo\n\n");
        printf("\n\tVerifique se voce possui permissao para criar arquivos\n\t\tou se ja existe com o mesmo nome\n\n");
        system("PAUSE");
        a=1;
}

while(a==0){ //CONTEUDO
        pgm=conteudo_arquivo(pgm, i, arqC, arqH, complemento);
        system("CLS");
        printf("\nNovos campos?");
        novos=getch();
        if(novos==78 || novos==110){
          system("CLS");
          a=1;
          fprintf(arqC, "\nreturn P;\nfclose(fp);\n}\n\nvoid ImpimirDados(Dados P){\nprintf(\"\\n\");\n");
        }
        if (novos==13 || novos==83 || novos==115){
                a=0;
                printf("\n");
        //system("PAUSE");
        }
    }
}
//printf("\n%s\n", complemento);
while(1){ //GRAVAR
        printf("\nGravar?");
        confirm=getch();
        if (confirm==115 || confirm==83 || confirm==13){ //CRIAR ARQUIVO
            system("CLS");
            printf("\n\tArquivo sendo criado. Por favor aguarde!\n\n");

                fprintf(arqC, "\n%s\n", complemento);
                fprintf(arqC, "printf(\"\\n\");\n}\n");
                fprintf(arqC, "\nDados PesquisarDados(FILE* fp, int Codigo){\nDados P;\nif ((fp=fopen");
                fprintf(arqC, "(\"%s.dat\",\"ab+\"))==NULL){", pgm.nome);
                fprintf(arqC, "\nprintf(\"Não Abriu o Arquivo!\");\nsystem(\"PAUSE\");\n}\nfseek(fp, 0, SEEK_SET);\nwhile(fread(&P,sizeof(Dados),1,fp)){\nif(Codigo==P.Codigo){\n %s\nprintf(\"\\n\");\n}\n}\nsystem(\"PAUSE\");\nfclose(fp);\n}", complemento);
                fprintf(arqC,"void ListarDados (FILE* fp)\n{\nDados P;\nif ((fp=fopen(\"%s.dat\",\"ab+\"))==NULL)\n{", pgm.nome);
                fprintf(arqC, "\nprintf(\"Não Abriu o Arquivo!\");\nsystem(\"PAUSE\");\n}\nfseek(fp, 0, SEEK_SET);\nwhile(fread(&P,sizeof(Dados),1,fp))\n{");
                fprintf(arqC, "\n%s\nprintf(\"\\n\");\n}\n", complemento);
                fprintf(arqC, "system(\"PAUSE\");\nfclose(fp);\n}\n");
                fprintf(arqC, "\nvoid InserirDadosOrdenado (FILE* fp, Dados P){\nDados aux;\nP=DigitarDados();\nif ((fp=fopen(\"%s.dat\",\"ab+\"))==NULL){\nprintf(\"Não Abriu o Arquivo!\");\nsystem(\"PAUSE\");\n}", pgm.nome);

            finalizar_arquivosHC(arqH, arqC);
            system("PAUSE");
            system("CLS");
            return;
        }
        if (confirm==110 || confirm==78){
            saida=sair();
                if (saida==1) {
                    printf("\n\t\tProjeto Descartado!\n\n");
                    fclose(arqC); fclose(arqH);
                sprintf(remov,"\"del .\\Programas\\%s.c\"",pgm.nome);
                system(remov);
                sprintf(remov,"\"del .\\Programas\\%s.h\"",pgm.nome);
                system(remov);
                    system("PAUSE");
                    system("CLS");
                    exit (1);
                    }
        }
        system("CLS");
    }
//else printf("Menu");
    return 0;
}
