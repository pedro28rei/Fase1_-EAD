#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct para guardar a informa��o sobre um gestor
typedef struct gestor {
    int codigo;
    char nome[60];
    int idade;
    int telemovel;
    char morada[60];
    struct gestor* seguinte;
} Gestor;


//Fun��o que permite ler a informa��o do ficheiro "DadosGestores"
Gestor* lerDadosGestores();

//Fun��o que permite listar todos os gestores
void listarGestores(Gestor* gestor);

//Fun��o que permite inserir um gestor
Gestor* inserirGestor(Gestor* inicioG, int codigo, char nome[], int idade, float telemovel, char morada[]);

//Fun��o para verificar se existe um gestor
int existeGestor(Gestor* inicioG, int codigo);

//Fun��o que permite remover um gestor
Gestor* removerGestor(Gestor* gestor, int cod);

//Fun��o que permite alterar os dados de um gestor existente
void alterarGestor(Gestor* gestor);

//Fun��o que guarda os dados dos gestores no ficheiro "DadosGestores"
void guardarGestores(Gestor* gestor);
