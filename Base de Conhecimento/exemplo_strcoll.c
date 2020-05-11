#include <stdio.h>
#include <string.h>

int main () {
	char string1[15];
	char string2[15];
	int resultado;
	
	//Define as duas strings
	strcpy(string1, "xpto");
	strcpy(string2, "XPTO");
	
	//Compara as duas strings (dependendo da LC_COLLATE)
	resultado = strcoll(string1, string2);
	
	//Se o resultado for zero, as strings são iguais
	if (resultado == 0) {
		printf("As duas strings sao iguais!");
	}
	else {
		printf("As duas strings sao diferentes!");
	}

	return 0;
}
