#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Struct para guardar informa��o sobre os meios
typedef struct meio {
    int codigo;
    char tipo[50];
    int bateria;
    float autonomia;
    float custo;
    int geocodigo;
    int alugado;
    struct meio* seguinte;
} Meio;


//Fun��o que permite ler os dados no ficheiro "DadosMeios"
Meio* lerDadosMeios();

//Fun��o que permite listar todos os meios
void listarMeios(Meio* meio);

//Fun��o que permite inserir um meio
Meio* inserirMeio(Meio* inicioM, int codigo, char tipo[], int bateria, float autonomia, float custo, int geocodigo, int alugado);

//Fun��o para verificar se existe um meio
int existeMeio(Meio* inicioM, int codigo);

//Fun��o que permite remover um meio
Meio* removerMeio(Meio* meio, int cod);

//Fun��o que permite alterar os dados de um meio existente
void alterarMeio(Meio* meio);

//Fun��o que permite alugar um meio
Meio* aluguerMeio(Meio* meio);

//Fun��o que permite lista todos os meios disponiveis em determinada localiza��o
void localizarMeios(Meio* meio, int geocodigo);

//Fun��o que guarda os dados dos meios no ficheiro "DadosMeios"
void guardarMeios(Meio* meio);
