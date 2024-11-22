#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> // biblioteca de alocacao de espaco na memoria
#include <locale.h> // biblioteca de alocacao de texto por regiao
#include <string.h> // biblioteca responsavel por cuidar das strings

int registro()// funcao responsavel por cadastrar os usuarios
{
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];

		printf("Digite o CPF a ser Cadastrado");
		scanf("%s", cpf);// armazenando as strings

		strcpy(arquivo,cpf); // responsavel por copiar os valores das strings

		FILE *file; // cria o arquivo	
		file = fopen(arquivo, "w");// cria o arquivo
		fprintf(file,cpf);//salva o valor da variavel
		fclose(file);//fecha o arquivo

		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);

		printf("Digite o nome a ser cadastrado: ");
		scanf("%s",nome);

		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);

		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);

		printf("Digite o sobrenome a ser Cadastrado: ");
		scanf("%s",sobrenome);

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
	}





int consulta()
{
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

		char cpf[40];
		char conteudo[200];

		printf("Digite o cpf a ser consultado: ");
		scanf("%s",cpf);

		FILE *file;
		file = fopen(cpf, "r");

		if(file == NULL)
		{
			printf("Arquivo nao localizado!");
		}

		while(fgets(conteudo, 200, file) !=NULL)
		{
			printf("/nEssas sao as informações do usuário");
			printf("%s", conteudo);
			printf("/n/n ");

		}

			system("pause");
		
}

int deletar()
{
		char cpf[40];

		printf("Digite o cpf a ser deletado: ");
		scanf("%s", cpf);

		remove(cpf);

		FILE *file;
		file = fopen(cpf, "r");
		if(file == NULL)
		{
			printf("O usuário nao se encontra no sistema!.\n");
			system("pause");

		}
		
}

int main ()
{

	int opcao=0; // definindo as variaveis
	int laco=1;

	for(laco=1;laco=1;)

	{

	system("cls");

	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

	printf("###Cartório de Thales###\n\n");//inicio do menu
	printf("Escolha a Opçâo desejada no menu:\n\n");
	printf("\t1 - Registrar Nomes\n");
	printf("\t2 - Consultar Nomes\n");
	printf("\t3 - Excluir Nomes\n\n");
	printf("\t4 - Sair do sistema\n\n:");//fim do menu

	scanf("%d", &opcao);//armazenando a escolha do usu�rio

	system("cls");



	switch(opcao)

	{
		case 1:
		registro();
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
		printf("esta opcao nao está disponivel\n");
		system("pause");
		break;

	}
}
}

