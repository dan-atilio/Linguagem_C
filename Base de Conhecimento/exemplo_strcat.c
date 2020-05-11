#include <stdio.h>
#include <string.h>

int main () {
	char nova[50], destino[50];

	//Popula as duas strings
	strcpy(nova,    "Um novo conteudo!");
	strcpy(destino, "Que tal appendar?");

	//Coloca a string nova, no fim da destino
	strcat(destino, nova);

	//Mostra o resultado ao usuário
	printf("Resultado \" %s \" ", destino);

	return 0;
}
