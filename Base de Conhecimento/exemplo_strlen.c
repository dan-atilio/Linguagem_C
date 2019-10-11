#include <stdio.h>
#include <string.h>
#include <conio.h>
 
int main()
{
	char nome[100] = "";
	
	printf("Digite um nome: ");
	gets(nome);
	
	printf("Tamanho do nome [%s] = %d", nome, strlen(nome));
	
	getch();
	return 0;
}


