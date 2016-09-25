//Bibliotecas

//Definições do Programa (Constantes e Funções Secundárias)

//Declaração de Função
  //Declaração de Variáveis
  
  //Processamento
//Encerramento da Função

#include <stdio.h>

main(){
  int valor     = 5;
  int resultado = 1;
  
  while(valor>1){
    resultado = valor * resultado;
    valor--;
  }
  
  printf("Fatorial de 5 = %d\n\n", resultado);
}