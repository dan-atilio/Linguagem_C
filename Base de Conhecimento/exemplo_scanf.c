#include <stdio.h>

int main() {
	
	int valor1;
	printf("\nDigite um valor int: ");
	scanf("%d", &valor1);
	printf("O valor digitado foi [%d]\n", valor1);
	
	float valor2;
	printf("\nDigite um valor float: ");
	scanf("%f", &valor2);
	printf("O valor digitado foi [%f]\n", valor2);
	
	char valor3;
	getchar();
	printf("\nDigite um valor char: ");
	scanf("%c", &valor3);
	printf("O valor digitado foi [%c]\n", valor3);
	
	return 0;
}
