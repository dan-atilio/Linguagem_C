#include <stdio.h>
#include <ctype.h>

int main () {
	char var1 = '\n';
	char var2 = 'A';
	char var3 = ' ';
	
	if ( isspace(var1) )
		printf("Variavel 1 tem apenas espaco em branco (white-space character)!\n");
		
	if ( isspace(var2) )
		printf("Variavel 2 tem apenas espaco em branco (white-space character)!\n");
		
	if ( isspace(var3) )
		printf("Variavel 3 tem apenas espaco em branco (white-space character)!\n");
	
   return(0);
}
