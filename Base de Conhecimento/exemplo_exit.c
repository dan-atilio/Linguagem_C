#include <stdio.h>
#include <stdlib.h>

int main() {
	
	char opcao = ' ';
	while (1 == 1) {
		printf("\nMenu:\n");
		printf("-----\n");
		printf("0: Sair\n");
		printf("Resposta: ");
		scanf("%c", &opcao);
		getchar();
		
		if (opcao == '0')
			exit(0);
	}
	
	//Note que não será mostrada essa mensagem, quando é executado a instrução exit, ele encerra o programa
	printf("Continuação do programa...");
	
	return 0;
}
