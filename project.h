#ifndef PROJECT_H_INCLUDED
#define PROJECT_H_INCLUDED

struct programa{
    char nome[30];
    char titulo[30];
};
typedef struct programa Progm;

int menu();
int sair(); //RETORNA 1 PARA SAIR
Progm digitar_nomes();
FILE* criar_arquivoC(char* nome, char* titulo);
FILE* criar_arquivoH(char* nome);
Progm conteudo_arquivo(Progm b, int c, FILE* d, FILE* e, char* comp);
void finalizar_arquivosHC(FILE* h, FILE* c);


#endif // PROJECT_H_INCLUDED
