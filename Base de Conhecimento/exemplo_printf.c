#include <stdio.h>

int main() {
	//Mostrando mensagem simples
	printf("Ola Mundo\n\n");
	
	//Mostrando mensagem com argumentos
	int variavel = 10;
	printf("A variavel tem o valor de - %d \n\n", variavel);
	
	//Usando caracteres especiais
	printf("Caracteres especiais:\n");
	printf("1. Teste A\n (Nova Linha)\n");
	printf("2. Teste B\t (Tab)\n");
	printf("3. Teste C\b (Backspace)\n");
	printf("4. Teste D\r (Return)\n\n");
	
	//Imprimindo valores numericos
	printf("Numero comum (int): %d\n", 12345);
	printf("Numero comum com zeros a esquerda (int): %04d\n", 25);
	printf("Numero com virgula (float): %3.2f\n", 3.14159);
	printf("Hexadecimal: %x\n", 255);
	printf("Octal: %o\n", 255);
	printf("Porcentagem: %d %%\n\n", 10);
	
	//Imprimindo variaveis String
	printf("String completa:                     |%s|\n",       "Terminal de Informacao");
	printf("10 Caracteres:                       |%.10s|\n",    "Terminal de Informacao");
	printf("15 Caracteres:                       |%.15s|\n",    "Terminal de Informacao");
	printf("10 Caracteres com espaco a esquerda: |%15.10s|\n",  "Terminal de Informacao");
	printf("10 Caracteres com espaco a direita:  |%-15.10s|\n", "Terminal de Informacao");
	
	return 0;
}
