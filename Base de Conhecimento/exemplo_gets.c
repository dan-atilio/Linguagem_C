#include <stdio.h>

int main() {
	
	char nome[20];
	printf("Digite um nome: ");
	gets(nome);
	printf("Nome digitado: %s", nome);
	
	return 0;
}
