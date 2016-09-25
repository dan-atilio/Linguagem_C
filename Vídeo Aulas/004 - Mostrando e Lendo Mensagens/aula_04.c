#include <stdio.h>

//https://en.wikipedia.org/wiki/Scanf_format_string

main(){
  int auxiliar  = 0;
  
  //Mostrando mensagem ao usuário (\n pula linha)
  printf("\n--> Insira o valor desejado: ");
  
  //Lendo o que o usuário digitou no formato decimal e inserindo na variável auxiliar
  scanf("%d", &auxiliar);
  
  //Mostrando os tipos de saída da variável
  printf("\nDecimal:  %d", auxiliar);
  printf("\nOctal:    %o", auxiliar);
  printf("\nHexa:     %x", auxiliar);
  printf("\nCaracter: %c", auxiliar);
  printf("\n\n");
}