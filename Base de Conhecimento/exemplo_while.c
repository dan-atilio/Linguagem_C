#include <stdio.h>

int main() {
	
	//Exemplo 1, enquanto um valor for menor ou igual o outro
	int ini = 1;
	int fim = 10;
	printf("\nValor menor ou igual a outro:\n");
	while (ini <= fim) {
		printf("Atual: [%d], Final: [%d]\n", ini, fim);
		ini++;
	}
	
	//Exemplo 2, enquanto o valor digitado não for "0"
	char opcao = ' ';
	while (opcao != '0') {
		printf("\nMenu:\n");
		printf("-----\n");
		printf("0: Sair\n");
		printf("1: Somar\n");
		printf("2: Subtrair\n");
		printf("3: Dividir\n");
		printf("4: Multiplicar\n");
		printf("Resposta: ");
		scanf("%c", &opcao);
		getchar();
	}
	
	return 0;
}
