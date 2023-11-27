#include <stdio.h >  	//biblioteca de comunicação com o usuario
#include <stdlib.h > 	//biblioteca de alocação de espaço de memória
#include <locale.h > 	// biblioteca de alocação de texto por região
#include <string.h > 	// biblioteca responsavle por cuidar das string

int registro()	// Função responsável por cadastrar os usuários no sistema

{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de string/variaveis

	printf("Digite o CPF a ser cadastrado:");
	scanf("%s", cpf);	//%s refere-se a string

	strcpy(arquivo, cpf);	// Responsavel por copiar os valores das string

	FILE * file;	//cria arquivo
	file = fopen(arquivo, "w");	// Cria o arqivo e o "w" significa escrever 
	fprintf(file, cpf);	// Salvo o valor da variavel
	fclose(file);	// fecha arquivo

	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);

	printf("Digite o nome a ser cadastrado:");
	scanf("%s", nome);

	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);

	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s", sobrenome);

	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);

	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);

	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);

	system("pause");

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");	// Definindo a linguagem

	char cpf[40];
	char conteudo[200];

	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);

	FILE * file;
	file = fopen(cpf, "r");

	if (file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}

	while (fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	system("pause");
}

int deletar()
{
	char cpf[40];

	printf("Você escolheu deletar nomes: \n");
	scanf("%s", cpf);

	remove(cpf);

	FILE * file;
	file = fopen(cpf, "r");

	if (file == NULL)
	{
		printf("O usuario não se encontra no sistema. \n");
		system("pause");
	}
}

int main()
{
	int opcao = 0;	// definindo variaveis
	int laco = 1;

	for (laco = 1; laco = 1;)
	{
		system("cls");	// responsavel por limpar a tela

		setlocale(LC_ALL, "Portuguese");	// Definindo a linguagem

		printf("### Cartório da EBAC ###\n\n");	// inicio do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t 1 - Registar nomes\n");
		printf("\t 2 - Consultar nomes\n");
		printf("\t 3 - Deletar nomes\n");
		printf("\t 4 - Sair do sistema\n");
		printf("Opção:");	// fim do menu

		scanf("%d", &opcao);	// armazenando a escolha do usuário

		system("cls");

		switch (opcao)	// inicio de menu
		{
			case 1:
				registro();	// chamada de funções
				break;

			case 2:
				consulta();
				break;

			case 3:
				deletar();
				break;
				
				
				
			case 4:
			printf("Obrigado por utilizar o sistema!\n");	
			return 0;
			break;	

			default:
				printf("Essa opção não está disponivel!\n");
				system("pause");
				break;
		}
	}
}	// fim da seleção
            
 
  


