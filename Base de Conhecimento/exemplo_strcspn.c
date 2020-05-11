#include <stdio.h>
#include <string.h>

int main () {
	int posicao;
	const char string1[] = "1234567890";
	const char string2[] = "468";
	
	//Verifica na string 1, qual caractere da string 2 aparece pela primeira vez
	posicao = strcspn(string1, string2);
	
	//Mostra a mensagem
	printf("posicao encontrada: %d\n", posicao + 1);

	return 0;
}
