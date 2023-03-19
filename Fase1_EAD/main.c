#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "meio.h"
#include "gestor.h"
#include "cliente.h"


void main() {

	Meio* meio = NULL;
	Cliente* cliente = NULL;
	Gestor* gestor = NULL;

	meio = lerDadosMeios();
	cliente = lerDadosClientes();
	gestor = lerDadosGestores();

	int codigo, idade, telemovel, nif, bateria, geocodigo, alugado;
	float saldo, autonomia, custo;
	char nome[60], morada[60], tipo[60];


	int escolha1, escolha2;


	do {
	system("cls");
	escolha1 = menuPerfil();


		switch (escolha1)
		{
		case 1:
			do {
			system("cls");
			escolha2 = menuGestor();

								switch (escolha2)
								{
								case 1:
									system("cls");

									listarClientes(cliente);

									printf("\n\n\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 2:
									system("cls");

									listarGestores(gestor);

									printf("\n\n\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 3:
									system("cls");

									listarMeios(meio);

									printf("\n\n\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 4:
									system("cls");

									printf("\t\t| Codigo: ");
									scanf("%d", &codigo);
									printf("\t\t| Nome: ");
									scanf("%s", nome);
									printf("\t\t| Idade: ");
									scanf("%d", &idade);
									printf("\t\t| Telemovel: ");
									scanf("%d", &telemovel);
									printf("\t\t| Morada: ");
									scanf("%s", morada);
									printf("\t\t| NIF: ");
									scanf("%d", &nif);
									printf("\t\t| Saldo: ");
									scanf("%f", &saldo);
									printf("\n\t\tCliente introduzido com sucesso!\n\n");

									cliente = inserirCliente(cliente, codigo, nome, idade, telemovel, morada, nif, saldo);

									printf("\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 5:
									system("cls");

									printf("\t\t| Codigo: ");
									scanf("%d", &codigo);
									printf("\t\t| Nome: ");
									scanf("%s", nome);
									printf("\t\t| Idade: ");
									scanf("%d", &idade);
									printf("\t\t| Telemovel: ");
									scanf("%d", &telemovel);
									printf("\t\t| Morada: ");
									scanf("%s", morada);
									printf("\n\t\tGestor introduzido com sucesso!\n\n");

									gestor = inserirGestor(gestor, codigo, nome, idade, telemovel, morada);

									printf("\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 6:
									system("cls");

									printf("\t\t| Codigo: ");

									scanf("%d", &codigo);

									printf("\t\t| Tipo: ");
									scanf("%s", tipo);
									printf("\t\t| Bateria: ");
									scanf("%d", &bateria);
									printf("\t\t| Autonomia: ");
									scanf("%f", &autonomia);
									printf("\t\t| Custo: ");
									scanf("%f", &custo);
									printf("\t\t| Geocodigo:");
									scanf("%d", &geocodigo);
									printf("\n\t\tMeio introduzido com sucesso!\n\n");

									meio = inserirMeio(meio, codigo, tipo, bateria, autonomia, custo, geocodigo, 0);

									printf("\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 7:
									system("cls");

									printf("\t\tInsira o codigo do cliente a remover: ");
									scanf("%d", &codigo);
									cliente = removerCliente(cliente, codigo);
									printf("\n\t\tCliente removido com sucesso!\n\n");

									printf("\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 8:
									system("cls");

									printf("\t\tInsira o codigo do gestor a remover: ");
									scanf("%d", &codigo);
									gestor = removerGestor(gestor, codigo);
									printf("\n\t\tGestor removido com sucesso!\n\n");

									printf("\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 9:
									system("cls");

									printf("\t\tInsira o codigo do meio a remover: ");
									scanf("%d", &codigo);
									meio = removerMeio(meio, codigo);
									printf("\n\t\tMeio removido com sucesso!\n\n");

									printf("\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 10:
									system("cls");

									alterarCliente(cliente);
									
									printf("\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 11:
									system("cls");

									alterarGestor(gestor);
							
									printf("\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 12:
									system("cls");

									alterarMeio(meio);
									
									printf("\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 13:
									system("cls");

									guardarMeios(meio); 
									guardarClientes(cliente); 
									guardarGestores(gestor); 

									exit(0);
									break;
								default:
									system("cls");
									printf("\n\t\tEscolha inexistente!\n");
									printf("\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								}
			} while (escolha1 != 13);
			break;
		case 2:
			do {
			system("cls");
			escolha2 = menuCliente();

								switch (escolha2)
								{
								case 1:
									system("cls");

									printf("\t|Insira o seu codigo:");
									scanf("%d", &codigo);

									verificarCliente(cliente, codigo);

									printf("\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
								break;
								case 2:
									system("cls");

									printf("\t|Insira o seu codigo:");
									scanf("%d", &codigo);

									verificarSaldo(cliente, codigo);

									printf("\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 3:
									system("cls");


									printf("\t|Insira o seu codigo:");
									scanf("%d", &codigo);

									adicionarSaldo(cliente, codigo); 


									printf("\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 4:
									system("cls");

									aluguerMeio(meio); 

									printf("\n\n\n\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 5:
									system("cls");

									listarMeios(meio); 

									printf("\n\n\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 6:
									system("cls");

									printf("\n\t| Insira o geocodigo da localizacao: ");
									scanf("%d", &geocodigo);

									localizarMeios(meio, geocodigo);


									printf("\n\n\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
									break;
								case 7:
									system("cls");

									guardarMeios(meio); 
									guardarClientes(cliente); 
									guardarGestores(gestor); 

									exit(0);
								default:
									system("cls");
									printf("\n\t\tEscolha inexistente!\n");
									printf("\t\tPressione qualquer tecla para regressar ao menu...");
									getch();
								break;
								}
			} while (escolha1 != 7);
			break;
		case 3:
			system("cls");
			exit(0);
			break;
		default:
			system("cls");
			printf("\n\t\tEscolha inexistente!\n");
			printf("\t\tPressione qualquer tecla para regressar ao menu...");
			getch();
			break;
		}

	} while (escolha1 != 3);

}
