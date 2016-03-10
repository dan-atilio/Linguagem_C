/*
	www.terminaldeinformacao.com
*/

//Bibliotecas utilizadas
#include <stdio.h>
#include <stdlib.h>
  
#ifdef WIN32  //se for windows
  #define limpa_tela system("cls") //limpa tela
  #define espera sleep(500) //tempo de delay
#else //senão, ex.: linux
  #define limpa_tela system("/usr/bin/clear") //limpa tela
  #define espera sleep(1) //tempo de delay
#endif
 
//Função do quicksort, que recebe o limite
void quick_sort (int *nArray, int nLimite) {
  int nAnte, nProx, nMetade, nValAux, nAux;
     
  //Testando o limite e pegando a metade
  if (nLimite < 2)
    return;
  nMetade = nArray[nLimite / 2];
     
  //fazendo um for duplo, diminuindo o próximo e aumentando o anterior
  for (nAnte = 0, nProx = nLimite - 1;; nAnte++, nProx--) {
    //imprimindo os valores
    for(nAux=0;nAux<=nLimite-1;nAux++){
      printf("[%d]",nArray[nAux]);
      espera;
    }
    printf("\n");
         
    //enquanto for menor que a metade
    while (nArray[nAnte] < nMetade)
      nAnte++;
    //enquanto a metade for menor que o próximo
    while (nMetade < nArray[nProx])
      nProx--;
    //se o anterior é maior que o próximo quebra o laço
    if (nAnte >= nProx)
      break;
     
    //fazendo troca de posições
    nValAux = nArray[nAnte];
    nArray[nAnte] = nArray[nProx];
    nArray[nProx] = nValAux;
  }
   
  //Chamando rotina novamente em recursividade
  quick_sort(nArray, nAnte);
  quick_sort(nArray + nAnte, nLimite - nAnte);
}
  
main(){
  //declaração de variáveis
  int nPos=0, nAux=0;
  
  //Quantidade de casas do vetor
  while((nPos<=0)||(nPos>100)){
    printf("\nQuantos numeros tera o vetor? ");
    scanf("%d",&nPos);
  }
  
  //criando o vetor
  int nVetor[nPos], nOrig[nPos], nOpc=-1;
  
  //preenchendo os dados do vetor
  for(nAux=0;nAux<=nPos-1;nAux++){
    printf("\nInsira o numero %d: ",nAux+1);
    scanf("%d",&nVetor[nAux]);
    nOrig[nAux]=nVetor[nAux];
  }
  
  //Limpando a tela e pegando a opção
  limpa_tela;
  while((nOpc<=0)||(nOpc>=3)){
    printf("\n > Menu:");
    printf("\n  1. Shell Sort");
    printf("\n  2. Quick Sort");
    printf("\n > Resposta: ");
    scanf("%d",&nOpc);
  }
  printf("\nOrdenando:\n");
  
  //Se for Shell Sort
  if(nOpc==1){
    int nGap, nValAux, nProx, nAtual;
               
    //Definindo o gap
    while(nGap < (nPos-1)) {
      nGap = 3*nGap+1;
    }
    //Enquanto tiver o Gap
    while ( nGap > 1) {
      nGap /= 3;
      //Percorrendo as posições
      for(nAtual = nGap; nAtual < nPos; nAtual++) {
        //imprimindo os valores
        for(nAux=0;nAux<=nPos-1;nAux++){
          printf("[%d]",nVetor[nAux]);
          espera;
        }
             
        //definindo valor das próximas posições
        nValAux = nVetor[nAtual];
        nProx = nAtual - nGap;
         
        //Enquanto tiver próximo valor e ele seja menor que a próxima casa, faz inversão
        while (nProx >= 0 && nValAux < nVetor[nProx]) {
          nVetor[nProx + nGap] = nVetor[nProx];
          nProx -= nGap;
        }
        nVetor[nProx + nGap] = nValAux;
        printf("\n");
      }
    }
  }
  
  //Senão se for Quick Sort
  else if(nOpc==2){
    quick_sort(nVetor, nPos);
  }
  
  //Resultado - Vetor Original
  printf("\nOriginal: ");
  for(nAux=0;nAux<=nPos-1;nAux++){
    printf("[%d]",nOrig[nAux]);
    espera;
  }
  
  //Resultado - Vetor Ordenado
  printf("\nOrdenada: ");
  for(nAux=0;nAux<=nPos-1;nAux++){
    printf("[%d]",nVetor[nAux]);
    espera;
  }
  
  //limpando os dados e esperando o usuario apertar -Enter-
  getchar();
  printf("\n\nPressione -Enter- para finalizar!\n\n");
  getchar();
}