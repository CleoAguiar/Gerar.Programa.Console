#ifndef PROJECT_H_INCLUDED
#define PROJECT_H_INCLUDED

struct dados {
char nome[4];
int placa;
float valor;
int Codigo;
int Proximo;
};
typedef struct dados Dados;

Dados DigitarDados(); 
void ImprimirDados(Dados P); 
void ListareDados (FILE* fp); 

void inserirDadosOrdenado(FILE* fp, Dados P); 
Dados PesquisarDados(FILE* fp, int Codigo);


#endif // // PROJECT_H_INCLUDED