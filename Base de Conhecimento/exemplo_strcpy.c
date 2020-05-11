#include <stdio.h>
#include <string.h>

int main () {
	char string[50];

	//Popula a string
	strcpy(string,  "Terminal de Informacao");
	
	//Mostra o resultado ao usuário
	printf("String: \" %s \" ", string);

	return 0;
}
