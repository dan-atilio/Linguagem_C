/*
	www.terminaldeinformacao.com
*/

//Bibliotecas utilizadas
#include <stdio.h>
#include <stdlib.h>
 
//Se o sistema for Windows adiciona determinada biblioteca, e definindo comandos de limpar e esperar
#ifdef WIN32
    #include <windows.h>
    #define LIMPA_TELA system("cls")
//Senão for Windows (se for Linux)
#else
    #include <unistd.h>
    #define LIMPA_TELA system("/usr/bin/clear")
#endif
 
//Espera 3 segundos
#define ESPERA sleep(3)
 
//Estrutura da lista que será criada
typedef struct Fila {
    int valor;
    struct Fila *proximo;
} Dados;
 
void insere();
void exclui();
void mostra();
void mostra_erro();
 
//Inicializando os dados da lista
Dados *principal = NULL;
Dados *final = NULL;
 
main(){
    char escolha;
    //Laço que irá mostrar o menu esperando uma opção (char)
    do {
        //Limpando a tela, e mostrando o menu
        LIMPA_TELA;
        printf("\nMétodo Fila\n\n");
        printf("Escolha uma opção: \n");
        printf("\t1 - Inserir valor na Fila\n");
        printf("\t2 - Remover valor da Fila\n");
        printf("\t3 - Mostrar valores da Fila\n");
        printf("\t9 - Sair\n\n");
        printf("Resposta: ");
        scanf("%c", &escolha);
        switch(escolha) {
            //Inserindo
            case '1':
                insere(); 
                break;
            //Excluindo
            case '2':
                if(principal!=NULL){
                    exclui();
                }
                else{
                    printf("\nA Fila está vazia!\n");
                    getchar();
                }
                break;                
            //Mostrando
            case '3':
                if(principal!=NULL){
                    mostra();
                }
                else{
                    printf("\nA Fila está vazia!\n");
                    getchar();
                }
                break;                
            case '9':
                printf("\nObrigado por utilizar esse programa!\n");
                printf("------>Terminal de Informação<------\n\n");
                ESPERA;
                exit(0);
                break;
            //Se foi algum valor inválido
            default:
                mostra_erro();
                break;
        }
        //Impedindo sujeira na gravação da escolha
        getchar();
    }
    while (escolha > 0); //Loop Infinito
}
 
//Inserção
void insere(){
    int val;
    LIMPA_TELA;
    printf("\nInserção: \n");
    printf("--------------------------------------\n");
    printf("Insira o valor a ser inserido: ");
    scanf("%d",&val);
    Dados *atual = (Dados*)malloc(sizeof(Dados));
    atual -> valor = val;
    atual -> proximo = NULL;
 
    //se o principal estiver vazio, será o atual
    if(principal == NULL){
        principal = final = atual;
    }
    //senão, o próximo valor que será o atual
    else{
        final->proximo=atual;
        final=atual;
    }
 
    printf("\nValor inserido!\n");
    printf("--------------------------------------");
    getchar();
}
 
//Exclusão
void exclui(){
    Dados *auxiliar;
    printf("\nExclusão: \n");
    printf("--------------------------------------\n");
    //o auxiliar será o próximo da principal
    auxiliar=principal->proximo;
    //limpando a principal
    free(principal);
    //a principal será a auxiliar
    principal=auxiliar;
    printf("\nValor excluido!\n");
    printf("--------------------------------------");
    getchar();
}
 
//Mostrando
void mostra(){
    int posicao=0;
    Dados *nova=principal;
    LIMPA_TELA;
    printf("\nMostrando valores: \n");
    printf("--------------------------------------\n");
    //laço de repetição para mostrar os valores
    for (; nova != NULL; nova = nova->proximo) {
        posicao++;
        printf("Posição %d, contém o valor %d\n", posicao, nova->valor);
    }
    printf("--------------------------------------");
    getchar();
}
 
//Mostrando erro de digitação
void mostra_erro(){
    LIMPA_TELA;
    printf("\nErro de Digitação: \n");
    printf("--------------------------------------\n");
    printf("\nDigite uma opção válida (pressione -Enter- p/ continuar)!\n\n");
    printf("--------------------------------------");
    getchar();
}