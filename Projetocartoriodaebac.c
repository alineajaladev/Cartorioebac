#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrir o arquivo que j� est� salvo (atualizar o que j� existe)
	fprintf(file,","); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",nome); //%S refere-se a string
	
	file = fopen(arquivo, "a"); //abrir o arquivo que est� salvo e atualizar
	fprintf(file,nome); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrir o arquivo que j� est� salvo e atualizar
	fprintf(file,","); //salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	printf("Digite o �ltimo sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abrir arquivo que est� salvo e atualizar 
	fprintf(file,sobrenome); //salva o valor da vari�vel
	fclose(file); // fecha o arquivo 
	
	file = fopen(arquivo, "a"); //abrir um arquivo que j� est� salvo e atualizar 
	fprintf(file,","); // salva o valor da vari�vel
	fclose(file); // fechar o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abrir arquivo que j� est� salvo e atualizar
	fprintf(file,cargo); // salva o valor da vari�vel
	fclose(file); //fechar o arquivo
	
	system("pause"); // uma pausa na tela
	
}

int consulta() //Fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	//in�cio da cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��es do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //para ler o arquivo
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
}

int main ()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	char senhadigitada[]="a";
	setlocale(LC_ALL, "Portuguese");
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin"); //est� comparando a string
	
	if(comparacao == 0)
	{
		system ("cls");
		for(laco=1;laco=1;)
		{
		
			system("cls"); // respons�vel por limpar a tela
	
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
			printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o: "); //fim do menu
			scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
			system("cls");
		
		
			switch(opcao) //inicio da sele��o do menu
			{
				case 1:
				registro(); //chamada de fun��es
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
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break; 
			}	//fim de sele��o
			
		}
	
    }
    
    else
    	printf("\nSenha incorreta!");
}
