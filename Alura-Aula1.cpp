// Alura-Aula1.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
// Romulo

//#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <locale>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"


using namespace std;

//setlocale(LC_ALL, "pt_BR.UTF-8");
// variaveis globais
char palavrasecreta[20];
char chutes[26];
int churtesdados = 0;

void abertura() {
	setlocale(LC_ALL, "pt_BR.UTF-8");
	printf("/****************/\n");
	printf("/ Jogo de Forca */\n");
	printf("/****************/\n\n");
}

void chuta()
{
	setlocale(LC_ALL, "pt_BR.UTF-8");
	char chute;
	printf("Qual letra? \n");
	scanf_s(" %c", &chute);

	chutes[churtesdados] = chute;
	churtesdados++;
}


int jachutou(char letra) {
	setlocale(LC_ALL, "pt_BR.UTF-8");
	int achou = 0;
	for (int j = 0; j < churtesdados; j++) 
	{
		if (chutes[j] == letra) 
		{
			achou = 1;
			break;
		}
	}

	return achou;
}

 
void desenhaforca() {
	setlocale(LC_ALL, "pt_BR.UTF-8");
	printf("Você já deu %d chutes\n", churtesdados);

	for (int i = 0; i < strlen(palavrasecreta); i++)
	{

		int achou = jachutou(palavrasecreta[i]);
			if (achou)
		{
			printf_s("%c ", palavrasecreta[i]);
		}
		else
		{
			printf_s("_ ");
		}

	}
	printf("\n");
}

//void adicionapalavra() {
//	char quer;
//
//	printf("Você deseja adicionar uma nova palavra no jogo (S/N)?");
//	scanf(" %c", &quer);
//
//	if (quer == 'S') {
//		char novapalavra[20];
//
//		printf("Digite a nova palavra, em letras maiúsculas: ");
//		scanf("%s", novapalavra);
//
//		FILE* f;
//
//		f = fopen("palavras.txt", "r+");
//		if (f == 0) {
//			printf("Banco de dados de palavras não disponível\n\n");
//			exit(1);
//		}
//
//		int qtd;
//		fscanf(f, "%d", &qtd);
//		qtd++;
//		fseek(f, 0, SEEK_SET);
//		fprintf(f, "%d", qtd);
//
//		fseek(f, 0, SEEK_END);
//		fprintf(f, "\n%s", novapalavra);
//
//		fclose(f);
//
//	}
//
//}
// void escolhepalavra() {
//	//sprintf_s(palavrasecreta, "MELANCIA");
//	 FILE* f; // = fopen("palavras.txt", "r");
//	 
//	  f = fopen("palavras.txt", "r");
//
//	 if (f==0)
//	 {
//		 printf_s("Desculpe, lista de palavras nao disponiveis");
//		 exit(1);
//	 }
//
//	 int qtdepalavras=0;
//	 fscanf_s(f, "%d", qtdepalavras);
//
//	 srand(time(0));
//	 int randomico = rand() % qtdepalavras;
//
//	 for (int i = 0; i <= randomico; i++)
//	 {
//		 fscanf_s(f, "%s", palavrasecreta);
//	 }
//		 fclose(f); 
//}

 int ganhou()
 {
	 for (int i = 0; i < strlen(palavrasecreta); i++)
	 {
		 if (!jachutou(palavrasecreta[i]))
		 {
			 return 0;
		 }
	 }
	 return 1;
 }
 int enforcou() {
	 int erros=0;

	 for (int i = 0; i < churtesdados; i++)
	 {
		 int existe = 0;
		 for (int j = 0; j < strlen(palavrasecreta); j++)
		 {
			 if (chutes[i] ==palavrasecreta[i])
			 {
				 existe = 1;
					 break;
			 }
		 }
		 if (!existe) erros++;
	 }
	 return erros >= 5;
 }

int main() 
{
	setlocale(LC_ALL, "pt_BR.UTF-8");

	//int acertou = 0;
	//int enforcou = 0;

		escolhepalavra();
		abertura();

	do {
		//imprime a palavra secreta		
		//printf("Você já deu %d chutes\n", tentativas);

		desenhaforca();
		chuta();
	

		} while (!ganhou() && !enforcou());

}