//Bibliotecas
#include <stdio.h>
#include <string.h>

//Se o sistema for Windows, a limpeza utiliza a funcao cls
#ifdef WIN32
  #define LIMPA_TELA system("cls");

//Se for Linux, utiliza a funcao clear par alimpeza da tela
#else
  #define LIMPA_TELA system("/usr/bin/clear");
#endif

//Espera 1 segundo
#define ESPERA sleep(1);

main(){
	int tamanho     = 9;
	int voltas      = 2;
	int volta_atual = 0;
	int atual       = 0;
	int auxiliar    = 0;
	int pos_copia   = 0;
	int posicao     = 0;
	int quantidade  = 0;
	int tipo        = 0;
	char palavra[tamanho+2];
	char copia[tamanho+2];
	
	//Zera a string
	for (atual=0;atual<=tamanho;atual++){
		palavra[atual] = ' ';
	}
	
	//Pega a string
	printf("Insira a string (maximo de %d caracteres): \n> ", tamanho+1);
	gets(palavra);
	
	//Pegando o tipo de impressao
	while (tipo != 1 && tipo != 2){
		printf("Deseja mostrar somente o letreiro (1=Sim; 2=Nao)?");
		scanf("%d", &tipo);
	}
	
	//Zera a string onde tiver o \0, deixando somente na última posicao
	for (atual=0;atual<=tamanho;atual++){
		if (palavra[atual] == '\0')
			palavra[atual] = ' ';
	}
	palavra[tamanho+1] = '|';
	palavra[tamanho+2] = '\0';
	
	//Limpando a tela e imprimindo a primeira vez
	LIMPA_TELA;
	if (tipo == 1)
		printf("%s", palavra);
	else
		printf("Original: ...%s...\nLetreiro: ...%s...\nVolta:    %d de %d", palavra, palavra, volta_atual+1, voltas+1);
	ESPERA;
	
	//Zera a copia
	for (atual=0;atual<=tamanho+1;atual++){
		copia[atual] = ' ';
	}
	palavra[tamanho+2] = '\0';
	
	//Percorre as voltas
	for (volta_atual=0; volta_atual<=voltas; volta_atual++){
		//Impressao normal
		for (posicao=0;posicao<tamanho+1;posicao++){
			auxiliar++;
			pos_copia = 0;
			
			//Percorre a string
			for (atual=auxiliar;atual<=tamanho+1;atual++){
				copia[pos_copia] = palavra[atual];
				pos_copia++;
			}
			
			//Seta o restante da copia como espaco em branco
			for (pos_copia=pos_copia;pos_copia<=tamanho+1;pos_copia++){
				copia[pos_copia] = ' ';
			}
			
			//Imprimindo Mensagem
			LIMPA_TELA;
			if (tipo == 1)
				printf("%s", copia);
			else
				printf("Original: ...%s...\nLetreiro: ...%s...\nVolta:    %d de %d", palavra, copia, volta_atual+1, voltas+1);
			ESPERA;
			
			//Se ja tiver atingido o maximo, zera o auxiliar
			if (auxiliar == tamanho+1)
				auxiliar = 0;
		}
		quantidade = 0;
		
		//Agora comeco do fim
		for (atual=0;atual<=tamanho+1;atual++){
			//Armazena o restante da copia excluindo a primeira posicao
			for (pos_copia=0;pos_copia<=tamanho;pos_copia++){
				copia[pos_copia] = copia[pos_copia+1];
			}
			
			//Define agora o caracter que sera copiado
			copia[tamanho+1] = palavra[quantidade];
			
			//Mostrando a mensagem
			LIMPA_TELA;
			if (tipo == 1)
				printf("%s", copia);
			else
				printf("Original: ...%s...\nLetreiro: ...%s...\nVolta:    %d de %d", palavra, copia, volta_atual+1, voltas+1);
			ESPERA;
			
			quantidade++;
		}
		
		//Zera a copia
		for (atual=0;atual<=tamanho+1;atual++){
			copia[atual] = ' ';
		}
		palavra[tamanho+2] = '\0';
	}
	
	printf("\n\nPrograma encerrado...\n\n");
}