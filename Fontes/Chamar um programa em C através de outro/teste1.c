/*
	www.terminaldeinformacao.com
*/

#include <stdio.h>
#include "teste2.c"
 
int main(){
    //Chamando a função para pegar o valor
    int aux = teste2();
 
    //Demonstrando valor lido e esperando usuário apertar o -Enter-
    printf("\n-->%d", aux);
    getch();
 
    //Finalizando a rotina
    return 0;
}