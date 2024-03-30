#include <stdio.h> //biblioteca de comunica��o de usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //func�o respons�vel por cadastrar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	//in�cio da cria��o de var�aveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//final da cria��o de var�aveis/string
	
	printf("Cadastre o seu CPF: "); // coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores da string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //abre o arquivo e o "w" significa escrever
	fprintf(file,"CPF: ");
	fprintf(file,cpf); //salva o valor da var�avel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar
	fprintf(file,", Nome: ");
	fclose(file); // fecha o arquivo
	
	printf("Digite o seu nome: "); //coletando informa��o do usu�rio
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar
	fprintf(file,nome); //salva o valor da var�avel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar
	fprintf(file,", Sobrenome: ");
	fclose(file); //fecha o arquivo
	
	printf("Digite o seu sobrenome: "); //coletando informa��o do usu�rio
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar
	fprintf(file,sobrenome); //salva o valor da var�avel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar
	fprintf(file,", Cargo: ");
	fclose(file); //fecha o arquivo
	
	printf("Digite o seu cargo: "); //coletando informa��o do usu�rio
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar
	fprintf(file,cargo); //salva o valor da var�avel
	fclose(file); //fecha o arquivo
	
	system("pause"); //comando para pausar a tela e aparecer a mensagem
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	//in�cio da cria��o de var�aveis/string
	char cpf[40];
	char conteudo[200];
	//fim da cria��o de var�aveis/string
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file;
	file = fopen(cpf, "r"); //abre o arquivo e o "r" significa read, ou em portugu�s "ler"
	
	if(file == NULL) // definindo valida��o caso o CPF n�o esteja cadastrado	
	{
		printf("N�o foi poss�vel localizar o CPF.\n"); // mensagem que ir� aparecer ao usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL) // definindo valida��o caso o CPF esteja cadastrado 
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //comando para pausar a tela e aparecer a mensagem
	
}

int deletar()
{
	//in�cio da cria��o de var�aveis/string
	char cpf[40];
	//fim da cria��o de var�aveis/string
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file;
	file = fopen(cpf, "r"); //abre o arquivo e o "r" significa read, ou em portugu�s "ler"
	fclose(file); //fecha o arquivo
	
	if(file == NULL) // definindo valida��o caso o CPF n�o esteja cadastrado
	{
		printf("N�o foi poss�vel localizar o CPF do usu�rio!. \n"); // mensagem que ir� aparecer ao usu�rio
		system("pause"); //comando para pausar a tela e aparecer a mensagem
	}
	
	else //definindo valida��o caso o CPF esteja cadastrado para ser deletado
	{
		if(remove(cpf) == 0) //definindo valida��o caso o CPF esteja cadastrado para ser deletado
		{
			printf("\nO CPF do usu�rio foi deletado!\n\n"); // mensagem que ir� aparecer ao usu�rio
			system("pause"); //comando para pausar a tela e aparecer a mensagem
		}

	}
	
}


int main()
{
    int opcao=0; //definindo vari�veis
    int x=1;

    for(x=1;x=1;)
    {  
	   system("cls");
       
	   setlocale(LC_ALL, "Portuguese"); //definindo linguagem

	   printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
	   printf("Escolha a op��o desejada do menu:\n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n\n");
	   printf("Opc�o: "); //fim do menu 
	
	   scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
	   system("cls"); //respons�vel por limpar a tela 
	   
	   // inicio da sele��o do menu
	   switch(opcao) 
	   { 
	      case 1:
	      registro(); //chamada de fun��es
		  break;
		  
		  case 2:
		  consultar(); //chamada de fun��es
		  break;
		  
		  case 3:	
		  deletar(); //chamada de fun��es
		  break;
		  
		  default:
		  printf("Essa op��o n�o est� dispon�vel!\n"); 
		  system("pause"); //comando para pausar a tela e aparecer a mensagem
		  break; //fim da sele��o
	   }	
	}
}
