/*
	www.terminaldeinformacao.com
*/

//Bibliotecas utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
//Se o sistema for Windows adiciona determinada biblioteca, e definindo comandos de limpar e esperar
#ifdef WIN32
    #include <windows.h>
    #define LIMPA_TELA system("cls")
//Senão for Windows (ex.: Linux)
#else
    #include <unistd.h>
    #define LIMPA_TELA system("/usr/bin/clear")
#endif
 
//Máximo de bytes para uma String
#define BUFFER 64
 
//Espera 3 segundos
#define ESPERA sleep(3)
 
//Estrutura da lista que será criada
typedef struct lista {
    char *nome;
    int idade;
    struct lista *proximo;
} Dados;
 
//Funções para manusear os dados (irão retornar dados)
Dados *inicia_dados  (char *nome, int idade);
Dados *insere_dados  (Dados *dados, char *nome, int idade);
Dados *delbusca_dados(Dados *dados, char *chave);
Dados *deleta_dados  (Dados *dados, int nTipo);
int   checa_vazio    (Dados *dados);
 
//Funções para mostrar dados
void  exibe_dados    (Dados *dados);
void  exibe_tamanho  (Dados *nova);
void  busca_dados    (Dados *dados, char *chave);
 
//Funções do Menu
void criavazia(void);    //1
void insereinicio(void); //2
void inserefim(void);    //3
void listavazia(void);   //4
void prielemento(void);  //5
void ultelemento(void);  //6
void exibe(void);        //7
void exibetam(void);     //8
void deletapri(void);    //9
void deleta(void);       //a
void delbusca(void);     //b
void busca(void);        //c
 
//Inicializando os dados da lista
Dados *principal = NULL;
 
//---------------------------------
//     Opção '1'
//---------------------------------
 
//Criando uma lista vazia
void criavazia(void){
    char *nome;
    int idade;
    //Alocando dados para uma String
    nome = (char *)malloc(BUFFER);
    //Lendo String Nome
    fprintf(stdout, "\n\nDigite o Nome: \n----> ");
    scanf("%s", nome);
    fprintf(stdout, "\n");
    //Lendo int Idade
    fprintf(stdout, "Digite a Idade: \n----> ");
    scanf("%d", &idade);
    fprintf(stdout, "\n");
    //Lançando os dados lidos na lista Principal
    free(principal);
    principal = inicia_dados(nome, idade);
}
 
//Iniciando os dados da lista vazia
Dados *inicia_dados(char *nome, int idade) {
    Dados *novo;
    //Alocando memória para a posição atual da lista
    novo = (Dados *)malloc(sizeof(Dados));
    //Lançando os dados lidos
    novo->nome = (char *)malloc(strlen(nome)+1);
    strncpy(novo->nome, nome, strlen(nome)+1);
    novo->idade = idade;
    //Apontando para a próxima posição da lista
    novo->proximo = NULL;
    return novo;
}
 
//---------------------------------
//     Opção '2'
//---------------------------------
 
//Inserindo no início da lista
void insereinicio(void){
    char *nome;
    int idade;
    //Reservando espaço para String
    nome = (char *)malloc(BUFFER);
    //Armazenando String Nome
    fprintf(stdout, "\n\nDigite o Nome: \n----> ");
    scanf("%s", nome);
    fprintf(stdout, "\n");
    //Armazenando int Idade
    fprintf(stdout, "Digite a Idade: \n----> ");
    scanf("%d", &idade);
    fprintf(stdout, "\n");
    //Lançando dados no ínicio da lista
    principal = insere_dados(principal, nome, idade);
}
 
//Inserindo dados recebidos
Dados *insere_dados(Dados *dados, char *nome, int idade) {
    Dados *inicio;
    //Alocando memória para a posição atual
    inicio = (Dados *)malloc(sizeof(Dados));
    //Lançando os dados lidos
    inicio->nome = (char *)malloc(strlen(nome)+1);
    strncpy(inicio->nome, nome, strlen(nome)+1);
    inicio->idade = idade;
    //O próximo valor aponta para a lista já existente
    inicio->proximo = dados;
    return inicio;
}
 
//---------------------------------
//     Opção '3'
//---------------------------------
 
//Inserção de dados no final de uma lista
void inserefim(void) {
    char *nome;
    int idade;
    //Alocação de espaço para String Nome
    nome = (char *)malloc(BUFFER);
    //Armazenando String Nome
    fprintf(stdout, "\n\nDigite o Nome: \n----> ");
    scanf("%s", nome);
    fprintf(stdout, "\n");
    //Armazenando Int Idade
    fprintf(stdout, "Digite a Idade: \n----> ");
    scanf("%d", &idade);
    fprintf(stdout, "\n");
    //Criando listas auxiliares        
    Dados *final,*aux;
    //Alocando dados para a posição final da lista
    final = (Dados *)malloc(sizeof(Dados));
    //Setando os valores Nome e Idade
    final->nome = (char *)malloc(strlen(nome)+1);
    strncpy(final->nome, nome, strlen(nome)+1);
    final->idade = idade;
    //A pŕoxima posição será Nulo
    final->proximo=NULL;
    //A lista auxiliar será igual a Principal
    aux=principal;
    //Enquanto o próximo de auxiliar não for Nulo
    while(aux->proximo!=NULL){
        aux=aux->proximo;
    }
    //O último valor, será Nulo, e depois apontando para
    //o Final
    aux->proximo=NULL;
    aux->proximo=final;
}
 
//---------------------------------
//     Opção '4'
//---------------------------------
 
//Função que testa se a lista está vazia
void listavazia(void){
    if (principal == NULL) 
        fprintf(stdout, "\n\nLista esta Vazia!\n\n ");
    else
        fprintf(stdout, "\n\nLista nao esta Vazia!\n\n ");
    getchar();
}
 
//---------------------------------
//     Opção '5'
//---------------------------------
 
//Mostrar o primeiro elemento da lista
void prielemento(void){
    fprintf(stdout, "------------------------\n");  
    fprintf(stdout, "Nome: %s\n", principal->nome);
    fprintf(stdout, "Idade: %d\n", principal->idade);
    fprintf(stdout, "------------------------\n");
    getchar();
}
 
//---------------------------------
//     Opção '6'
//---------------------------------
 
//Mostrando o último elemento da lista
void ultelemento(void){
    Dados *aux=principal;
    //Enquanto o próximo elemento não for NULL
    //Avance uma posição
    while(aux->proximo!=NULL){
        aux=aux->proximo;
    }
    fprintf(stdout, "------------------------\n");  
    fprintf(stdout, "Nome: %s\n", aux->nome);
    fprintf(stdout, "Idade: %d\n", aux->idade);
    fprintf(stdout, "------------------------\n");
    getchar();
}
 
//---------------------------------
//     Opção '7'
//---------------------------------
 
//Exibindo dados da lista
void exibe(void) {
    //Se não estiver vazio, exibe os dados
    if (!checa_vazio(principal))
        exibe_dados(principal);
}
 
//Exibindo todos os dados do menu
void exibe_dados(Dados *dados) {
    fprintf(stdout, "Cadastro:\n\n");
    fprintf(stdout, "------------------------\n");
    //Exibindo todos os valores da lista
    for (; dados != NULL; dados = dados->proximo) {
        fprintf(stdout, "Nome: %s\n", dados->nome);
        fprintf(stdout, "Idade: %d\n", dados->idade);
        fprintf(stdout, "------------------------\n");
    }
    getchar();
}
 
//---------------------------------
//     Opção '8'
//---------------------------------
 
//Exibindo o tamanho da lista
void exibetam(void){
    //Se não estiver vazio, exibe os dados
    if (!checa_vazio(principal))
        exibe_tamanho(principal);
}
 
//Exibindo o tamanho total (bytes) e quantidade
void exibe_tamanho(Dados *nova){
  int aux=0, tamanho=0;
  fprintf(stdout, "\n------------------------\n");
  //Correndo todos os valores da Lista
  for (; nova != NULL; nova = nova->proximo) {
    aux++;
    tamanho+=sizeof(nova);
  }
  fprintf(stdout, "Total de Elementos: %d\nTamanho Total: %d bytes\n",aux,tamanho);
  fprintf(stdout, "------------------------\n");
  getchar();
}
 
//---------------------------------
//     Opção '9' e 'a'
//---------------------------------
 
//Deleta o Primeiro valor
void deletapri(void) {
    //Se não estiver vazio, deleta os dados
    if (!checa_vazio(principal))
        principal = deleta_dados(principal,1);
}
 
//Deleta o Último valor
void deleta(void) {
    //Se não estiver vazio, deleta os dados
    if (!checa_vazio(principal))
        principal = deleta_dados(principal,2);
}
 
//Deleta registros da lista, Tipo 1 = Inicio, Tipo 2 = Fim
Dados *deleta_dados(Dados *dados, int nTipo) {
    if(nTipo==1){
        //Apontando para a próxima posição
        Dados *novo;
        novo = dados->proximo;
        //Limpando os dados
        free(dados->nome);
        free(dados);
        fprintf(stdout, "O primeiro registro foi deletado  com sucesso.\n");
        getchar();
        return novo;
    }
    if(nTipo==2){
        Dados *novo=dados, *aux=dados;
        //Se a lista estiver no fim, exclui o que restou
        if(novo->proximo==NULL){
            free(novo);
            aux=NULL;
        }
        else{
            //Laço de repetição para chegar no fim da lista
            while(novo->proximo!=NULL){
                novo=novo->proximo;
            }
            //Preenchendo os dados da lista auxiliar
            while(aux->proximo!=novo){
                aux=aux->proximo;
            }
            //Limpando os dados e apontando para nulo
            free(novo);
            aux->proximo=NULL;
        }
        fprintf(stdout, "O ultimo registro foi deletado com sucesso.\n");
        getchar();
        return aux;
    }
}
 
//---------------------------------
//     Opção 'b'
//---------------------------------
 
//Deletando valor buscado
void delbusca(void) {
    char *chave;
    //Se não estiver vazio
    if (!checa_vazio(principal)) {
        chave = (char *)malloc(BUFFER);
        //Armazenando o valor digitado
        fprintf(stdout, "Digite o nome para buscar: \n--> ");
        scanf("%s", chave);
        //Deletando a chave buscada
        principal = delbusca_dados(principal, chave);
    }
}
 
//Deletando os valores buscados
Dados *delbusca_dados(Dados *dados, char *chave) {
    int achou=0,cont=0;
    Dados *juntou, *aux, *nova=dados;        
 
    //Correndo a lista e verificando se encontrou a string buscada, se sim, aumenta o contador e seta a variável de busca
    for (; nova != NULL; nova = nova->proximo) {
        if (strcmp(chave, nova->nome) == 0) {
            achou=1;
            cont++;
        }
    }
 
    //Se encontrou a busca
    if(achou==1){
        int ind=0;
        //Correndo a lista
        for(ind=0;ind<cont;ind++){
            //Se encontrou na primeira casa apaga a primeira casa
            if(strcmp(chave,dados->nome)==0){
                aux=dados;
                dados=dados->proximo;
                free(aux);
            }
            //Senão, procura até encontrar
            else{
                aux=dados;
                //Posiciona na frente do encontro para exclusão
                while(strcmp(chave,aux->nome)!=0){
                    aux=aux->proximo;
                }
 
                juntou=dados;
                //Enquanto o auxiliar juntou for diferente do posicionado para exclusão
                while(juntou->proximo!=aux){
                    juntou=juntou->proximo;
                }
                //Aponta para o próximo valor válido
                juntou->proximo=aux->proximo;
 
                free(aux);
            }
        }
        fprintf(stdout, "Excluido.\n");
    }
    else
        fprintf(stdout, "Nenhum resultado encontrado.\n");
 
    getchar();
    return dados;
}
 
//---------------------------------
//     Opção 'c'
//---------------------------------
 
//Função que busca os dados
void busca(void) {
    char *chave;
    //Senão estiver vazio a lista
    if (!checa_vazio(principal)) {
        chave = (char *)malloc(BUFFER);
        //Lendo o nome que será buscado
        fprintf(stdout, "Digite o nome para buscar: \n--> ");
        scanf("%s", chave);
        //chamando a função que irá procurar o nome
        busca_dados(principal, chave);
    }
}
 
//Percorre cada ponta da lista verificando busca
void busca_dados(Dados *dados, char *chave) {
    int achou = 0;
    fprintf(stdout, "Cadastro:\n\n");
    //Percorrendo todas as posições
    for (; dados != NULL; dados = dados->proximo) {
        //Se encontrou, mostra os dados
        if (strcmp(chave, dados->nome) == 0) {
            fprintf(stdout, "------------------------\n");
            fprintf(stdout, "Nome: %s\n", dados->nome);
            fprintf(stdout, "Idade: %d\n", dados->idade);
            fprintf(stdout, "------------------------\n");
            achou++;
        }
    }
 
    //Mostrando o resultado da busca
    if (achou == 0)
        fprintf(stdout, "Nenhum resultado encontrado.\n");
    else
        fprintf(stdout, "Foram encontrado(s) %d registro(s).\n", achou);
 
    getchar();
}
 
//---------------------------------
//     Função Auxiliar
//---------------------------------
 
//Função que testa se a lista esta vazia
int checa_vazio(Dados *dados) {
    //Se a lista estiver vazia
    if (dados == NULL) {
            fprintf(stdout, "Lista vazia!\n");
            getchar();
            return 1;
    } else
            return 0;
}
 
//---------------------------------
//     Função Principal
//---------------------------------
 
int main(void) {
    char escolha;
    int chave=0;
    //Laço que irá mostrar o menu esperando uma opção (char)
    do {
        //Limpando a tela, e mostrando o menu lembrando que primeiramente, os itens estão bloqueados até que seja criada uma lista vazia
        LIMPA_TELA;
        fprintf(stdout, "\n\t\tCadastro de Pessoas\n\n");
        fprintf(stdout, "Escolha uma opcao: \n");
        fprintf(stdout, "1 - Criar lista vazia\n");
        if(chave==1){
            fprintf(stdout, "2 - Inserir no Inicio de uma lista\n");
            fprintf(stdout, "3 - Inserir no Fim de uma lista\n");
        }
        fprintf(stdout, "4 - Lista Vazia...\n");
        if(chave==1){
            fprintf(stdout, "5 - Exibir dados do primeiro elemento\n");
            fprintf(stdout, "6 - Exibir dados do ultimo elemento\n");
            fprintf(stdout, "7 - Exibir todos os valores da Lista\n");
            fprintf(stdout, "8 - Exibir o tamanho da Lista\n");
            fprintf(stdout, "9 - Eliminar primeiro elemento\n");
            fprintf(stdout, "a - Eliminar último elemento\n");
            fprintf(stdout, "b - Eliminar elemento buscado\n");
            fprintf(stdout, "c - Busca Dados\n");
        }
        fprintf(stdout, "d - Sair\n\n");
        fprintf(stdout, "Resposta: ");
        scanf("%c", &escolha);
        //Se a chave for diferente de zero, porém a escolha for diferente de 1, 4 e d, a escolha será z (opção inválida)
        if((chave==0)&&((escolha!='1')&&(escolha!='d')&&(escolha!='4')))
            escolha='z';
 
        switch(escolha) {
            //Criando lista vazia
            case '1':
                chave=1;
                criavazia(); 
                break;
            //Inserindo no início
            case '2':
                insereinicio();
                break;                
            //Inserindo no final
            case '3':
                //Se a lista não estiver vazia
                if(principal!=NULL){
                    inserefim();
                }
                //senão inclui no inicio
                else{
                    insereinicio();
                }
                break;
            //Checando se a lista está vazia
            case '4':
                listavazia();
                break;
            //Mostrando Primeiro elemento
            case '5':
                prielemento();
                break;
            //Mostrando Último elemento
            case '6':
                ultelemento();
                break;
            //Exibindo todos elementos
            case '7':
                exibe();
                break;
            //Exibindo tamanho da lista
            case '8':
                exibetam();
                break;
            //Deleta primeiro elementos
            case '9':
                deletapri();
                break;                
            //Deleta último elemento
            case 'a':
                deleta();
                break;
            //Deleta elemento buscado
            case 'b':
                delbusca();
                break;                
            //Buscando elementos
            case 'c':
                busca();
                break;
            //Saindo e finalizando o programa
            case 'd':
                fprintf(stderr,"Obrigado por utilizar esse programa!\n");
                fprintf(stderr,"------>Terminal de Informação<------\n\n");
                ESPERA;
                exit(0);
                break;
            //Se foi algum valor inválido
            default:
                fprintf(stderr,"Digite uma opcao valida (pressione -Enter- p/ continuar)!\n");
                getchar();
                break;
        }
        //Impedindo sujeira na gravação da escolha
        getchar();
    }
    while (escolha > 0); //Loop Infinito
    return 0;
}