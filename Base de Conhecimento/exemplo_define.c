#include <stdio.h>
#include <stdlib.h>

//Se o sistema for Windows, a limpeza utiliza a funcao cls
#ifdef WIN32
  #define LIMPA_TELA system("cls");
 
//Se for Linux, utiliza a funcao clear par alimpeza da tela
#else
  #define LIMPA_TELA system("/usr/bin/clear");
#endif

int main() {
	int valor = 0;
	printf("Digite um valor: ");
	scanf("%d", &valor);
	
	LIMPA_TELA;
	
	printf("O valor digitado foi: %d", valor);
	
	return 0;
}
