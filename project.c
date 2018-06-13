#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "project.h"
#define FIM 1

void finalizar_arquivosHC(FILE* arqH, FILE* arqC){
    fprintf(arqH, "\nint Codigo;\nint Proximo;\n}\;\ntypedef struct dados Dados;\n\nDados DigitarDados(); \nvoid ImprimirDados(Dados P); \nvoid ListareDados (FILE* fp); \n\nvoid inserirDadosOrdenado(FILE* fp, Dados P); \nDados PesquisarDados(FILE* fp, int Codigo);");
    fprintf(arqH, "\n\n\n#endif // // PROJECT_H_INCLUDED");
    //fprintf(arqC, "\nreturn P;\nfclose(fp);\n}\n");
    fprintf(arqC, "fseek(fp, 0, SEEK_END);\nfseek(fp, -sizeof(Dados), SEEK_CUR);\nwhile(ftell(fp)>0){\nfread(&aux, sizeof(Dados), 1, fp);\nif(aux.Codigo>P.Codigo){\nfwrite(&aux, sizeof(Dados), 1, fp);\nfseek(fp, -sizeof(Dados)*3, SEEK_CUR);\n}\nelse break;\n}\nfseek(fp, 0, SEEK_CUR);\nfwrite(&P, sizeof(Dados), 1, fp);\nfclose(fp);\n}\n");
}

Progm conteudo_arquivo(Progm b, int c, FILE* aC, FILE* aH, char* comp){
    Progm aux=b;
    char campo[30], tipo[30], conf, var[3], vr[3], temp[800];
    FILE *arqNome;
    int a=0, e, i, tamanho=0;
    //fflush(temp);
    system("CLS");
    printf("\t\tInformacoes");
    { //DIGITAR STRUCT
    while (a != FIM ){//CAMPO
        printf("\n\nCampo: ");
        for (i=0; i<30 ; i++ ){
            campo[i]=getche();
            if (campo[i]==8) i=i-2;
            if (campo[i]==27) {
                e=sair();
                if (e==1) {
                    a=1;
                    printf("\n\t\tSaindo!\n\tPrograma descartado\n");
                    system("PAUSE");
                    system("CLS");
                    exit(1); //Descartar arquivos
                    }
                else {
                    i=0;
                    printf("\n");
                    break;
                    }
                campo[i]=getche();
                break;
                }
            if ((campo[i]==13) && i>0) {
                a=1;
                campo[i]='\0';
                break;
            }
            if (campo[i]==0)break;
        }
    }
    system("CLS");
    a=i=0;
    while (a != FIM ){//TIPO
        printf("\t\tInformacoes\n\nCampo: %s\nTipo: ", campo);
        for (i=0; i<30 ; i++ ){
            tipo[i]=getche();
            if (campo[i]==8) i=i-2;
            if (tipo[i]==27) {
                e=sair();
                if (e==1) {
                    a=1;
                    printf("\n\t\tSaindo!\n\tPrograma descartado\n");
                    system("PAUSE");
                    system("CLS");
                    exit(1); //Descartar arquivos
                    }
                else {
                    i=0;
                    printf("\n");
                    break;
                    }
                tipo[i]=getche();
                break;
                }
            if ((tipo[i]==13) && i>0) {
                a=1;
                tipo[i]='\0';
                break;
            }
            if (tipo[i]==0)break;
        }
        if ((strcmp(tipo, "char")!=0) && (strcmp(tipo, "int")!=0) && (strcmp(tipo, "float")!=0)){
            system("CLS");
            a=i=0;
        }

        if (strcmp(tipo, "char")==0){
          system("CLS");
            while(1){//TAMANHO
            system("CLS");
            printf("\t\tInformacoes\n\nCampo: %s\nTipo: %s\nTamanho (bits) ", campo, tipo);
            scanf("%d", &tamanho);
            if (tamanho==0){
                system("CLS");
                printf("\n\tTamanho invalido, entre com um valor maior que zero!\n\n");
                system("PAUSE");
            }
            else break;
            }
        }
    }

                {
                if (strcmp(tipo, "char")==0){
                    strcpy(var,"%s");
                    strcpy(vr, "%s");
                }
                if (strcmp(tipo, "int")==0){
                    strcpy(var, "%d");
                    strcpy(vr, "%d");
                }
                if (strcmp(tipo, "float")==0){
                    strcpy(var, "%f");
                    strcpy(vr, "%.2f");
                }
                    //system("PAUSE");
                    //printf("\n%s\n", var);
                    //system("PAUSE");
                }

    a=0;
    while(a==0){
    printf("\nConfirmar informacoes?");
    conf=getch();
        if(conf==78 || conf==110){//DESCARTADOS
            printf("\n\tOs dados digitados foram descartados!");
            a=1;
        }
        if (conf==13 || conf==83 || conf==115){
                fprintf(aH, "\n%s %s", tipo, campo);
                if (strcmp(tipo, "char")==0) fprintf(aH, "[%d];", tamanho);
                else fprintf(aH, ";");
                fprintf(aC,"printf (\"\\nDigite %s: \");\nscanf(\"", campo);
                if (strcmp(tipo,"char")==0) {
                        fprintf(aC,"%s\", P.%s);\n", var, campo);
                        //sprintf(temp, "printf(\"\\n%s: %s\",P.%s);", campo, vr, campo);
                        //strcat(conf, temp);
                }
                if (strcmp(tipo, "float")==0) fprintf(aC, "%%f\", &P.%s);\n", campo);
                //else {
                if (strcmp(tipo, "int")==0){
                    fprintf(aC,"%s\", &P.%s);\n", var, campo);
                    //sprintf(temp, "printf(\"\\n%s: %s\",P.%s);", campo, vr, campo);
                    //strcat(conf, temp);
                }
                sprintf(temp, "printf(\"\\n%s: %s\",P.%s);", campo, vr, campo);
                strcat(comp, temp);
                //printf("\n%s\n", comp);
                //printf("\n%s\n", temp);
                printf("\n\tDados armazenados!\n");
                system("PAUSE");
                a=1;
            }
            //return aux;
        }
    }
}

FILE* criar_arquivoC(char *nome, char* titulo){
    FILE *arqC;
    char strC[100], strD[100];
    sprintf(strC,".\\Programas\\%s.c",nome);
    arqC=fopen(strC,"r");
    if (arqC!=NULL){
        fclose(arqC);
        return NULL;
    }
    if (arqC==NULL){
        arqC=fopen(strC,"a");
        if (arqC==NULL) return arqC;
        else {
        fprintf(arqC, "#include <stdio.h>\n#include <stdlib.h>\n#include <conio.h>\n#include <string.h>\n#include \"%s.h\"\n\nint main(){\nDados P;\nFILE *fp;\nint codigo, opcao;", nome);
        //fprintf(arqC,"\nif((arq=fopen(\"%s.dat\",\"wb\"))==NULL){\nprintf(\"Nao abriu o arquivo!\");\nexit(1);\n}", nome);
        fprintf(arqC,"\nwhile(1){\nsystem(\"CLS\");\nprintf(\"\\t\\tPrograma Cadastro de %s\\n\");\n", titulo);
        fprintf(arqC,"\nprintf(\"\\n 1 - Inserir\\n 2 - Pesquisar por codigo\\n 3 - Listar os Dados\\n\\n 0 - Sair\\n\\nOpcao: \"); \nscanf (\"%%d\", &opcao); \nsystem(\"CLS\");");
        fprintf(arqC,"\nswitch (opcao){\ncase 1:\nInserirDadosOrdenado();\nbreak;\ncase 2:\nprintf(\"Digite o codigo: \");\nscanf(\"%%d\",&codigo);\nPesquisarDados(fp,codigo);\nbreak;\ncase 3:\nListarDados(fp);\nbreak;\ncase 0:\nexit(0);\ndefault: printf (\"\\n OPC%%cO INVALIDA\\n\\n\\n\",142);\nsystem(\"PAUSE\");\nsystem(\"CLS\");\n}\n}\n}\n\n");
        fprintf(arqC,"\nDados DigitarDados(){\nDados P;\nDados aux;\nFILE* fp;\naux.Codigo=0;");
        fprintf(arqC,"\nif ((fp=fopen(\"%s.dat\",\"ab+\"))==NULL){", nome);
        fprintf(arqC,"\nprintf(\"Não Abriu o Arquivo!\");\nsystem(\"PAUSE\");\n}\nfseek(fp, 0, SEEK_END);\nfseek(fp, -sizeof(Dados), SEEK_CUR);\nwhile(ftell(fp)>0){\nfread(&aux, sizeof(Dados), 1, fp);\nif(aux.Codigo>P.Codigo){\nfwrite(&aux, sizeof(Dados), 1, fp);\nfseek(fp, -sizeof(Dados)*3, SEEK_CUR);\n}\nelse break;\n}\n");
        fprintf(arqC, "printf(\"Codigo do %s:%%d \",aux.Codigo+1);\nP.Codigo=aux.Codigo+1;", nome);
        return arqC;
        }
    }
}

FILE* criar_arquivoH(char *nome){
    FILE *arqH;
    char strH[100];
    sprintf(strH,".\\Programas\\%s.h",nome);
    arqH=fopen(strH,"r");
    if (arqH!=NULL){
        fclose(arqH);
        return NULL;
    }
    if (arqH==NULL){
        arqH=fopen(strH,"a");
        if (arqH==NULL) return arqH;
        else {
        fprintf(arqH, "#ifndef PROJECT_H_INCLUDED\n#define PROJECT_H_INCLUDED\n\nstruct dados {");
        return arqH;//ARQUIVO CRIADO
        }
    }
}

Progm digitar_nomes(){
    Progm sH;
    int a=0; //SE RECEBER 1 FECHA O WHILE
    int e, i, criar;
    char conf, nome[30], titulo[30];
    Progm p;
    while (a != FIM ) //NOME DO PROGRAMA
    {
        //printf("%s\n%d", nome, a);
        printf("\t\tNovo Programa\n\nNome do Programa: ");
        for (i=0; i<30 ; i++ ){
            nome[i]=getche();
            if (nome[i]==8) i=i-2;
            if (nome[i]==27) {
                e=sair();
                if (e==1) {
                    a=1;
                    printf("\n\t\tSaindo!\n\n");
                    system("PAUSE");
                    system("CLS");
                    menu();
                    }
                else {
                    i=0;
                    printf("\n");
                    break;
                    }
                nome[i]=getche();
                break;
                }
            if ((nome[i]==13) && i>0) {
                a=1;
                nome[i]='\0';
                break;
            }
            if (nome[i]==0)break;
            //nome[i]=caracter_letra(nome[i]);
        }
    system("CLS");
    }
    a=i=0;
    while (a != FIM ) //TITULO DO PROGRAMA
    {
        system("CLS");
        printf("\t\tNovo Programa\n\nNome do Programa: %s\nTitulo: ", nome);
        for (i=0; i<30 ; i++ ){
            titulo[i]=getche();
            if (titulo[i]==8) i=i-2;
            if (titulo[i]==27) {
                e=sair();
                if (e==1) {
                    a=1;
                    printf("\n\t\tSaindo!\n\n");
                    system("PAUSE");
                    system("CLS");
                    menu();
                    }
                else {
                    i=0;
                    printf("\n");
                    break;
                    }
                titulo[i]=getche();
                break;
                }
            if ((titulo[i]==13) && i>0) {
                a=1;
                titulo[i]='\0';
                break;
            }
            if (titulo[i]==0)break;
        }
    system("CLS");
    //printf("%s\n%s", nome, titulo);
    }
    strcpy(p.nome, nome);
    strcpy(p.titulo, titulo);
return p;
}

int sair(){ //SAINDO DO PROGRAMA COM CONFIRMAÇAO (1) confirma sair
    char dig;
            printf("\nSair?");
            while(1)
            {
                dig=getch();
                if (dig==13 || dig==115 || dig==83)
                {
                    system("CLS");
                    printf("\nFinalizando...\n");
                    return 1;
                }
                if (dig==27 || dig==110 || dig==78) return 0;

            }
}

int menu(){
    int a;
    char opcao=0, nome[1];
    while (1){
    printf("\t\tGerador\n\tPrograma de Cadastros\n\n 1  - Novo Programa\nESC - Sair\n");
    opcao=getch();
    system("CLS");
    if (opcao=='1'){
        return 1;
        //digitar_nomes();
    }

    if (opcao==27){ //SAINDO DO PROGRAMA COM CONFIRMAÇAO
        a=sair();
        if (a==1) {
            printf("\n\t\tSaindo. Bye bye!\n\n");
            system("PAUSE");
            exit(1);
        }
        if (a==0) system("CLS");
    }
    }
}
