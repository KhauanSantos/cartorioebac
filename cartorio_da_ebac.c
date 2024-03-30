#include <stdio.h> //biblioteca de comunicação de usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //funcão responsável por cadastrar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	//início da criação de varíaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//final da criação de varíaveis/string
	
	printf("Cadastre o seu CPF: "); // coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores da string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //abre o arquivo e o "w" significa escrever
	fprintf(file,"CPF: ");
	fprintf(file,cpf); //salva o valor da varíavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar
	fprintf(file,", Nome: ");
	fclose(file); // fecha o arquivo
	
	printf("Digite o seu nome: "); //coletando informação do usuário
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar
	fprintf(file,nome); //salva o valor da varíavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar
	fprintf(file,", Sobrenome: ");
	fclose(file); //fecha o arquivo
	
	printf("Digite o seu sobrenome: "); //coletando informação do usuário
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar
	fprintf(file,sobrenome); //salva o valor da varíavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar
	fprintf(file,", Cargo: ");
	fclose(file); //fecha o arquivo
	
	printf("Digite o seu cargo: "); //coletando informação do usuário
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar
	fprintf(file,cargo); //salva o valor da varíavel
	fclose(file); //fecha o arquivo
	
	system("pause"); //comando para pausar a tela e aparecer a mensagem
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	//início da criação de varíaveis/string
	char cpf[40];
	char conteudo[200];
	//fim da criação de varíaveis/string
	
	printf("Digite o CPF a ser consultado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file;
	file = fopen(cpf, "r"); //abre o arquivo e o "r" significa read, ou em português "ler"
	
	if(file == NULL) // definindo validação caso o CPF não esteja cadastrado	
	{
		printf("Não foi possível localizar o CPF.\n"); // mensagem que irá aparecer ao usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL) // definindo validação caso o CPF esteja cadastrado 
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //comando para pausar a tela e aparecer a mensagem
	
}

int deletar()
{
	//início da criação de varíaveis/string
	char cpf[40];
	//fim da criação de varíaveis/string
	
	printf("Digite o CPF do usuário a ser deletado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file;
	file = fopen(cpf, "r"); //abre o arquivo e o "r" significa read, ou em português "ler"
	fclose(file); //fecha o arquivo
	
	if(file == NULL) // definindo validação caso o CPF não esteja cadastrado
	{
		printf("Não foi possível localizar o CPF do usuário!. \n"); // mensagem que irá aparecer ao usuário
		system("pause"); //comando para pausar a tela e aparecer a mensagem
	}
	
	else //definindo validação caso o CPF esteja cadastrado para ser deletado
	{
		if(remove(cpf) == 0) //definindo validação caso o CPF esteja cadastrado para ser deletado
		{
			printf("\nO CPF do usuário foi deletado!\n\n"); // mensagem que irá aparecer ao usuário
			system("pause"); //comando para pausar a tela e aparecer a mensagem
		}

	}
	
}


int main()
{
    int opcao=0; //definindo variáveis
    int x=1;

    for(x=1;x=1;)
    {  
	   system("cls");
       
	   setlocale(LC_ALL, "Portuguese"); //definindo linguagem

	   printf("### Cartório da EBAC ###\n\n"); //inicio do menu
	   printf("Escolha a opção desejada do menu:\n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n\n");
	   printf("Opcão: "); //fim do menu 
	
	   scanf("%d", &opcao); //armazenando a escolha do usuário
	
	   system("cls"); //responsável por limpar a tela 
	   
	   // inicio da seleção do menu
	   switch(opcao) 
	   { 
	      case 1:
	      registro(); //chamada de funções
		  break;
		  
		  case 2:
		  consultar(); //chamada de funções
		  break;
		  
		  case 3:	
		  deletar(); //chamada de funções
		  break;
		  
		  default:
		  printf("Essa opção não está disponível!\n"); 
		  system("pause"); //comando para pausar a tela e aparecer a mensagem
		  break; //fim da seleção
	   }	
	}
}
