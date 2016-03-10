/*
	www.terminaldeinformacao.com
*/

#include <stdio.h>
#include <stdlib.h>

#define Tamanho_Nome 100

#ifdef WIN32  //se for windows
  #define Limpa_Tela system("cls")
#else //senão, ex.: linux
  #define Limpa_Tela system("/usr/bin/clear") //limpa tela
#endif

void str_trim(char *trim_origem, char *trim_destino);

void main()
{
    //declarando variáveis que serão utilizadas
    char conteudo, auxiliar[100], nome_arq_origem[100], nome_arq_destino[100];
    int linhas = 0, linha_atual = 0;
    FILE *origem, *destino;

    Limpa_Tela;
    
    //Arquivo de Origem
    printf("Nome do arquivo de Origem:\n> ");
    fgets(auxiliar, Tamanho_Nome, stdin);

    //Abre o arquivo de origem
    str_trim(auxiliar, nome_arq_origem);
    origem = fopen(nome_arq_origem, "r");
 
    //Se o conteúdo for nulo
    if (origem == NULL)
    {
        printf("Arquivo de origem nao existe...\n");
        exit(EXIT_FAILURE);
    }
 
    //Arquivo de Destino
    printf("Nome do arquivo de Destino:\n> ");
    fgets(nome_arq_destino, Tamanho_Nome, stdin);
 
    //Abre o arquivo de destino
    destino = fopen(nome_arq_destino, "w");
 
    //Se não foi possível abrir, retorna erro
    if (destino == NULL)
    {
        fclose(origem);
        printf("Não foi possível gerar o arquivo destino...\n");
        exit(EXIT_FAILURE);
    }
    
    //Enquanto tiver conteudo na origem, aumenta o número de linhas
    while ((conteudo = fgetc(origem)) != EOF) {
        linhas++;
    }
    
    //Voltando o arquivo ao topo
    rewind(origem);
 
    //Enquanto tiver conteudo na origem, inputa esse conteudo no arquivo destino
    while ((conteudo = fgetc(origem)) != EOF) {
        fputc(conteudo, destino);
        
        //Mostra a porcentagem da cópia
        Limpa_Tela;
        linha_atual++;
        printf("Copiando %d%\n", (linha_atual * 100 / linhas));
    }
 
    //Mostrando mensagem de término
    printf("\nArquivo copiado com sucesso\n\n");
 
    //Fechando os ponteiros da origem e destino
    fclose(origem);
    fclose(destino);
}

//Retira os espaços de uma string
void str_trim(char *trim_origem, char *trim_destino) {
    int flag = 0;

    //Da esquerda para a direita
    while(*trim_origem) {
        //Se não tiver espaço em branco, define onde será a origem
        if(!isspace((unsigned char) *trim_origem) && flag == 0) {
            *trim_destino++ = *trim_origem;
            flag = 1;
        }
        
        //Setando o começo do destino
        trim_origem++;
        if(flag == 1) {
            *trim_destino++ = *trim_origem;
        }
    }

    //Da direita para a esquerda
    while(1) {
        //Diminuindo o destino
        trim_destino--;
        
        //Se não tiver espaço em branco, finaliza o laço
        if(!isspace((unsigned char) *trim_destino) && flag == 0) {
            break;
        }
        
        //Seta a flag, e altera o caracter para definir o fim de uma string
        flag = 0;
        *trim_destino = '\0';
    }
}

//Referências:
//http://www.programmingsimplified.com/c-program-copy-file
//http://codereview.stackexchange.com/questions/20897/trim-function-in-c