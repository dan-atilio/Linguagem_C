#include <stdio.h>
#include <string.h>

int main() {
	
	int inicio = 1;
	int final = 5;
	
	printf("\nFor com variavel numerica: \n");
	for (inicio = 1; inicio <= final; inicio++) {
		printf("Posicao [%d] de [%d]\n", inicio, final);
	}
	
	int posicao = 0;
	char nome[60];
	printf("\nDigite um nome (maximo de 60 caracteres): ");
	gets(nome);
	printf("\nFor com variavel texto: \n");
	for (posicao = 0; posicao <= strlen(nome); posicao++) {
		printf("Posicao [%2d] = [%c]\n", posicao, nome[posicao]);
	}
	
	return 0;
}

