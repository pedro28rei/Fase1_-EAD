#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "meio.h"
#include "gestor.h"
#include "cliente.h"


//Função que permite listar todos os meios
void listarMeios(Meio* meio)
{
	printf("\n|Meios:\n\n");
	while (meio != NULL)
	{
		printf("\t|Codigo: %d  |Tipo: %s  |Bateria: %d  |Autonomia: %.1f km  |Custo: %.2f $  |Geocodigo: %d  |Alugado: %d                   \n", meio->codigo, meio->tipo, meio->bateria, meio->autonomia, meio->custo, meio->geocodigo, meio->alugado);
		meio = meio->seguinte;
	}
}

//Função que permite ler os dados no ficheiro "DadosMeios"
Meio* lerDadosMeios() {

	FILE* fp;

	int codigo, bateria, geocodigo, alugado;
	float autonomia, custo;
	char tipo[50];

	Meio* aux = NULL;


	fp = fopen("DadosMeios.txt", "r");

	if (fp != NULL) {

		while (!feof(fp)) {

			fscanf(fp, "%d;%[^;];%d;%f;%f;%d;%d", &codigo, tipo, &bateria, &autonomia, &custo, &geocodigo, &alugado);
			aux = inserirMeio(aux, codigo, tipo, bateria, autonomia, custo, geocodigo, alugado);
		}

		fclose(fp);
	}
	else printf("\t\tErro ao abrir o ficheiro DadosMeios!\n");

	return(aux);
}

//Função para inserir um meio
Meio* inserirMeio(Meio* meio, int codigo, char tipo[], int bateria, float autonomia, float custo, int geocodigo, int alugado) {

	if (!existeMeio(meio, codigo))
	{
		Meio* novo = malloc(sizeof(Meio));
		if (novo != NULL)
		{
			novo->codigo = codigo;
			strcpy(novo->tipo, tipo);
			novo->bateria = bateria;
			novo->autonomia = autonomia;
			novo->custo = custo;
			novo->geocodigo = geocodigo;
			novo->alugado = alugado;
			novo->seguinte = meio;
			return(novo);
		}
	}
	else return(meio);

}

//Função para verificar se existe um meio
int existeMeio(Meio* meio, int codigo)
{
	while (meio != NULL)
	{
		if (meio->codigo == codigo) return(1);
		meio = meio->seguinte;
	}
	return(0);
}

////Função que permite remover um meio
Meio* removerMeio(Meio* meio, int cod) {
	Meio* anterior = meio, * atual = meio, * aux;

	if (atual == NULL) return(NULL);
	else if (atual->codigo == cod) 
	{
		aux = atual->seguinte;
		free(atual);
		return(aux);
	}
	else
	{
		while ((atual != NULL) && (atual->codigo != cod))
		{
			anterior = atual;
			atual = atual->seguinte;
		}
		if (atual == NULL) return(meio);
		else
		{
			anterior->seguinte = atual->seguinte;
			free(atual);
			return(meio);
		}
	}
}

//Função que permite alterar os dados de um meio existente
void alterarMeio(Meio* meio) {

	int encontrado = 0;
	int codigo1, codigo2, op, bateria, geocodigo, alugado;
	float autonomia, custo;
	char tipo[50];

	printf("\tInsira o codigo do meio: ");
	scanf("%d", &codigo1);

	while (meio != NULL) {

		if (meio->codigo == codigo1) {

			printf("\n\n\t|Escolha o que pretende alterar:");
			printf("\n\n\t\t1.Codigo\n");
			printf("\t\t2.Tipo\n");
			printf("\t\t3.Bateria\n");
			printf("\t\t4.Autonomia\n");
			printf("\t\t5.Custo\n");
			printf("\t\t6.Geocodigo\n");
			printf("\t\t7.Alugado\n\n");
			printf("\t| Escolha:");
			scanf("%d", &op);

			switch (op) {
			case 1:
				printf("\n\n\t|Insira o novo codigo: ");
				scanf("%d", &codigo2);
				meio->codigo = codigo2;
				break;
			case 2:
				printf("\n\n\tInsira o novo tipo: ");
				scanf("%s", tipo);
				strcpy(meio->tipo, tipo);
				break;
			case 3:
				printf("\n\n\tInsira a nova bateria: ");
				scanf("%d", &bateria);
				meio->bateria = bateria;
				break;
			case 4:
				printf("\n\n\tInsira a nova autonomia: ");
				scanf("%f", &autonomia);
				meio->autonomia = autonomia;
				break;
			case 5:
				printf("\n\n\tInsira o novo custo: ");
				scanf("%f", &custo);
				meio->custo = custo;
				break;

			case 6:
				printf("\n\n\tInsira o novo geocodigo: ");
				scanf("%d", &geocodigo);
				meio->geocodigo = geocodigo;
				break;

			case 7:
				printf("\n\n\tInsira o novo alugado(1/0): ");
				scanf("%d", &alugado);
				meio->alugado = alugado;
				break;
			default:
				printf("\n\n\t\tEscolha inexistente!");
			}

			printf("\n\n\t\tAlteracao efetuada com sucesso!\n\n");
			encontrado = 1;
			break;
		}

		meio = meio->seguinte;
	}

	if (!encontrado) {
		printf("\n\t\tCodigo inexistente!");
		return;
	}
}

//Função que permite alugar um meio
Meio* aluguerMeio(Meio* meio) {

	listarMeios(meio);


	int codigo, encontrado;
	encontrado = 0;

	printf("\n\n| Os meios disponiveis apresentam em Alugado o valor 0 ");
	printf("\n\n\n\t|Insira o codigo do meio que quer alugar:");
	scanf("%d", &codigo);

	while (meio != NULL) {

		if (meio->codigo == codigo) {
			meio->alugado = 1;
			printf("\n\n| Alugou %s com sucesso!\n", meio->tipo);
			printf("| Foi levantado do seu saldo %.2f $", meio->custo);
			encontrado = 1;
		}
		meio = meio->seguinte;
	}

	if (!encontrado) {
		printf("\n\n\tCodigo inexistente!\n");
	}
}

//Função que permite lista todos os meios disponiveis em determinada localização
void localizarMeios(Meio* meio, int geocodigo) {

	int encontrado = 0;

	while (meio != NULL) {

		if (meio->geocodigo == geocodigo) {
			printf("\n\t\t|Codigo: %d  |Tipo: %s  |Bateria: %d  |Autonomia: %.1f km  |Custo: %.2f $  |Geocodigo: %d  |Alugado: %d     ", meio->codigo, meio->tipo, meio->bateria, meio->autonomia, meio->custo, meio->geocodigo, meio->alugado);
			encontrado = 1;
		}
		meio = meio->seguinte;
	}

	if (!encontrado) {
		printf("\n\n\t\tNenhum meio encontrado nesta localizacao!\n", geocodigo);
	}
}

//Função que guarda os dados dos meios no ficheiro "DadosMeios"
void guardarMeios(Meio* meio) {

	FILE* fp;
	fp = fopen("DadosMeios.txt", "w");

	if (fp != NULL) {


		while (meio != NULL)
		{
			fprintf(fp, "%d;%s;%d;%.1f;%.2f;%d;%d\n", meio->codigo, meio->tipo, meio->bateria, meio->autonomia, meio->custo, meio->geocodigo, meio->alugado);
			meio = meio->seguinte;
		}
		fclose(fp);
	}
	else printf("\tErro ao guardar dados!");
}
