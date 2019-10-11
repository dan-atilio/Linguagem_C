#include <stdio.h>

int main() {
	
	char opcao = ' ';
	printf("\nMenu:\n");
	printf("-----\n");
	printf("1: Somar\n");
	printf("2: Subtrair\n");
	printf("3: Dividir\n");
	printf("4: Multiplicar\n");
	printf("Resposta: ");
	scanf("%c", &opcao);
	
	switch (opcao)
	{
	   case '1':
		 printf("Foi escolhido a opcao 1 (Somar)");
	   break;

	   case '2':
		 printf("Foi escolhido a opcao 2 (Subtrair)");
	   break;
	   
	   case '3':
		 printf("Foi escolhido a opcao 3 (Dividir)");
	   break;
	   
	   case '4':
		 printf("Foi escolhido a opcao 4 (Multiplicar)");
	   break;

	   default:
		 printf("Opcao desconhecida...");
	}
	
	return 0;
}
