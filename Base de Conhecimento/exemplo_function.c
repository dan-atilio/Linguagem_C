#include <stdio.h>

//Declaracao das funcoes secundarias
void functionA();
int functionB();
int functionC(int val1, int val2);

int main() {
	
	functionA();
	
	int valAux = functionB();
	printf("\nA Funcao B, retornou: %d\n", valAux);
	
	int soma = functionC(5, 4);
	printf("\nA Funcao C, retornou: %d\n", soma);
	
	return 0;
}

void functionA() {
	printf("\nEstou na Funcao A\n");
}

int functionB() {
	return 7;
}

int functionC(int val1, int val2) {
	int total = val1 + val2;
	return total;
}
