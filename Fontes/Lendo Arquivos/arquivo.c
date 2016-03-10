/*
	www.terminaldeinformacao.com
*/
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
//Declarando funções auxiliares
char *Tratamento();
 
//Função Principal
main(){
  //Variável para Arquivo original e novo
  FILE *arq_orig, *arq_novo;
  //Variável para linha atual lida (com tamanho máximo de 80 caracteres)
  char lido[80];
  //Variável auxiliar que irá conter o texto
  char *auxiliar;
  //Abrindo os arquivos, r = leitura, w = gravando... orig.txt = arquivo original a ser lido ... novo.txt = arquivo que será gerado
  arq_orig  = fopen("orig.txt","r");
  arq_novo  = fopen("novo.txt","w");
    //Enquanto houver linhas para leitura
    while(fgets(lido,80,arq_orig)!=NULL){
      //Guarda linha lida em uma variável auxiliar
      auxiliar=lido;
      //Grava no arquivo novo, a linha lida
      fputs(auxiliar,arq_novo);
      //Se o último caracter da linha não for
      //\n (pula linha), pular uma linha automaticamente
      if(!(auxiliar[strlen(auxiliar)-1]=='\n'))
        fputs("\n",arq_novo);
      //Chamando a função tratamento que irá salvar
      //um texto no arquivo novo
      fputs(Tratamento(),arq_novo);
    }
  //Fechando os arquivos
  fclose(arq_orig);
  fclose(arq_novo);
}
 
//Função externa para tratamentos
char *Tratamento(){
  //Ponteiro char que irá conter a informação
  //da linha lida
  char *ret;
  ret="\t(Linha lida)\n";
  return ret;
}