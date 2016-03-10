/* Nome:      cmpfnc.h v0.1
 * Autor:     Daniel Atilio
 * Site:      terminaldeinformacao.wordpress.com
 * Descrição: Biblioteca de CoMPlemento de FuNÇões
 * Funções:   c_itoa   (converte um valor inteiro em uma string)
 *            c_mvsubs (função que substitui uma substring por outra)
 *            c_rmsubs (função retira o resto de uma string, deixando apenas a substring)
 *            c_substr (retorna uma substring)
 *            c_trim   (retira espaços em branco da string original)
 * Obs.:      Todas as funções começam com c_, pois é a abreviação
 *            de "complementodefuncao_"
 */

#ifndef __CMPFNC_H
#define __CMPFNC_H

#include <stdio.h>
#include <string.h>

/************** Definições **************/
//#define variavel 20

#ifdef __cplusplus
extern "C" {
#endif /* c++ */


/************** Chamadas ***************/
char *c_itoa(int numero, char* destino, int radix);
char *c_mvsubs(char *string, char *substring, char *nova);
char *c_rmsubs(char *string, char *substring);
char *c_substr(char* texto, int inicio, int quant);
char *c_trim(char *str);

/************** Variáveis Globais ******/
//int variavel=0;


/************** Funções ****************/
//função que converte um número inteiro em string
char *c_itoa(int numero, char* destino, int radix) {
    static char dig[] =
        "0123456789"
        "abcdefghijklmnopqrstuvwxyz";
    int n = 0, neg = 0;
    unsigned int v;
    char* p, *q;
    char c;

    //se o número estiver negativo, altera a chave
    if (radix == 10 && numero < 0) {
        numero = -numero;
        neg = 1;
    }
    v = numero;
    //adicionando os números na string
    do {
        destino[n++] = dig[v%radix];
        v /= radix;
    } while (v);
    if (neg)
        destino[n++] = '-';
    //encerrando a string
    destino[n] = '\0';

    for (p = destino, q = p + (n-1); p < q; ++p, --q)
        c = *p, *p = *q, *q = c;
    return destino;
}

//função que substitui uma substring por outra
char *c_mvsubs(char *string, char *substring, char *nova)
  {
    char *extrai;
    int tamanho1,tamanho2,contador;

    tamanho1 = strlen(substring);
    tamanho2 = strlen(nova);

    //se o tamanho das strings for incompatível, retorna em branco
    //senão cria um for e pega a substring e coloca na posição indicada
    if((tamanho1 > tamanho2) || (tamanho2 > tamanho1))
      return(" ");
    else
      {
        extrai = strstr(string,substring);

        if(extrai)
          {
            for(contador = 0;contador < tamanho1; contador++)
              string[(extrai - string) + contador] = nova[contador];
            return(string);
          }
        else
         return(" ");
       }
  }


//função retira o resto de uma string, deixando apenas a substring
char *c_rmsubs(char *string, char *substring)
  {
    char *extrai;
    int tamanho,contador;

    tamanho = strlen(substring);
    extrai = strstr(string,substring);

    //retira os espaços da substring
    if(extrai)
      {
        for(contador = 0;contador < tamanho; contador++)
          extrai[contador] = string[(extrai - string) + contador];
        extrai[contador] = NULL;
        return(extrai);
      }
    else
      return(" ");
  }

//função que pega uma substring pegando a posição inicial e a quantidade
char *c_substr(char *texto, int ini, int quant)
{
  char *retorno = strdup(texto);
  int aux=0;
  int tam=strlen(texto);
  
  //se a posição inicial for maior que a string em si, o inicio será 0
  if(ini < 0 || ini > tam )
    ini = 0;
  
  //se a quantidade for maior que o inicio + string, a quantidade vai ser a diferença do tamanho da string e do inicio
  if(quant > (tam-ini))
    quant = tam-ini;
  
  //percorre a string guardando os caracteres desejados
  for (aux=ini;aux<quant+ini;aux++)
    retorno[aux-ini] = texto[aux];
  
  retorno[aux-ini] = '\0';
  return retorno;
} 

//função que retira os espaços em branco das laterais
char *c_trim(char *str){
  char *nova;
  int i=0, ini, fim;
  //teste - enquanto vai achando espaço em branco para pegar a posição inicial
  while(i<=strlen(str)){
    if (str[i]!=' '){
      ini=i;
      i=strlen(str);
    }
    i++;
  }
  
  //teste - enquanto vai achando espaço em branco para pegar a posição final
  fim=strlen(str)-1;
  while(1){
    if(str[fim]==' ')
      fim--;
    else
      break;
  }
  fim++;
  
  //pegando a string sem os espaços em branco
  nova=c_substr(str,ini,fim);
  return nova;
}
  
#ifdef __cplusplus
}
#endif /* c++ */

#endif /* __CMPFNC_H */