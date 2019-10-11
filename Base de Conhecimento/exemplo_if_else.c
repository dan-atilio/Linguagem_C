#include <stdio.h>

int main() {
	
	//Exemplo 1: Teste de condição simples
	char opcao = ' ';
	printf("Digite um numero de 0 a 9 (if simples): ");
	scanf("%c", &opcao);
	
	if (opcao == '0') {
		printf("Opcao digitada foi ZERO!\n");
	}
	
	//Exemplo 2: Teste de duas condições com E / AND (todos testes tem que ser verdadeiro)
	getchar();
	char opcao2 = ' ';
	printf("Digite um numero de 0 a 9 (if com E): ");
	scanf("%c", &opcao2);
	
	if ((opcao2 != '0') && (opcao2 != '1')) {
		printf("Opcao digitada diferente de ZERO e UM!\n");
	}
	
	//Exemplo 3: Teste de duas condições com OU / OR (um dos testes tem que ser verdadeiro)
	getchar();
	char opcao3 = ' ';
	printf("Digite um numero de 0 a 9 (if com OU): ");
	scanf("%c", &opcao3);
	
	if ((opcao3 == '0') || (opcao3 == '9')) {
		printf("Opcao digitada igual a ZERO ou igual a NOVE!\n");
	}
	
	//Exemplo 4: Teste com opção de else
	getchar();
	char opcao4 = ' ';
	printf("Digite um numero de 0 a 9 (if com else): ");
	scanf("%c", &opcao4);
	
	if (opcao4 == '0') {
		printf("Opcao digitada igual a ZERO!\n");
	}
	else {
		printf("Opcao digitada diferente de ZERO!\n");
	}
	
	//Exemplo 5: Teste com opção de else com outro teste
	getchar();
	char opcao5 = ' ';
	printf("Digite um numero de 0 a 9 (if com else if): ");
	scanf("%c", &opcao5);
	
	if (opcao5 == '0') {
		printf("Opcao digitada igual a ZERO!\n");
	}
	else if (opcao5 == '1') {
		printf("Opcao digitada igual a UM!\n");
	}
	else {
		printf("Opcao digitada diferente de ZERO e UM!\n");
	}
	
	return 0;
}
