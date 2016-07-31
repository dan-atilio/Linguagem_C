/*================================================*
 * Jogo   - Jogo da veia                          |
 * Versao - 1.2                                   |
 * Autor  - Daniel Atilio                         |
 *================================================*/

//Biblioteca
#include <stdio.h>
#include <time.h>

//Se o sistema for Windows, utiliza a conio e a limpeza é via cls
#ifdef WIN32
  #include <conio.h>
  #include <windows.h>
  #define LIMPA_TELA system("cls");
  int ENTER      = 13;
  int SETA_CIMA  = 72;
  int SETA_BAIXO = 80;
  
  void gotoxy(int x, int y)
  {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
  }

//Se for Linux, utiliza a gconio e a limpeza fica o usr/bin/clear
#else
  #include <gconio.h>
  #define LIMPA_TELA system("/usr/bin/clear");
  int ENTER      = 10;
  int SETA_CIMA  = 65;
  int SETA_BAIXO = 66;
#endif

//Espera 2 segundos
#define ESPERA sleep(2);

//Funções utilizadas
void pintaQuadro();      //função que desenha o quadro utilizado no programa
void titulo();           //função que desenha a tela de título
void limpar();           //função para limpar a tela
void pintaPlacar();      //função para desenhar o placar acima
void pintaPrincipal();  //função que desenha o 'sustenido' principal
void pintaOpcao(char cPos);
int  retDispon(char cJogada);

//Variáveis utilizadas no fonte inteiro
int nLinFin = 25;
int nColFin = 50;
char cEscolha = 'X';
char cMaquina = 'O';
char cUsados[9] = "         ";
int nColunas[9] = {16,23,30,16,23,30,16,23,30};
int nLinhas[9] = {7,7,7,11,11,11,15,15,15};
int nPlacarMaq = 0;
int nPlacarJog = 0;

//programa principal
main(){
  char cOpc = ' ';
  char cCarac = '#';

  //montagem da tela de título
  limpar();
  titulo();
  pintaQuadro();
  gotoxy((nColFin/2)-16,nLinFin-1);
  printf("Pressione [ENTER] para iniciar...");
  
  //Aguardando o usuário apertar o [Enter]
  cOpc = getch();
  while (cOpc != ENTER) {
    cOpc = getch();
  }
  
  //Criação do quadro e posicionamento para começar o jogo
  limpar();
  cOpc = ' ';
  pintaQuadro();
  gotoxy((nColFin/2)-10, 3);
  printf("Selecione uma opcao:");
  gotoxy((nColFin/2)-6, 5);
  printf("[ ] - Opcao X");
  gotoxy((nColFin/2)-6, 7);
  printf("[ ] - Opcao O");
  gotoxy((nColFin/2)-16,nLinFin-1);
  printf("Pressione [ENTER] para confirmar");
  gotoxy((nColFin/2)-5,5);
  cEscolha = 'X';
  cMaquina = 'O';
  
  //Aguardando o usuário apertar o [Enter], para escolher entre X ou O
  while (cOpc != ENTER) {
    cOpc = getch();
	
    //seta para cima, opção X
    if (cOpc == SETA_CIMA){
      gotoxy((nColFin/2)-5,5);
      cEscolha = 'X';
      cMaquina = 'O';
    }
    
    //seta para baixo, opção O
    if (cOpc == SETA_BAIXO){
      gotoxy((nColFin/2)-5,7);
      cEscolha = 'O';
      cMaquina = 'X';
    }
  }
  
  //Criação do quadro e posicionamento para começar o jogo
  limpar();
  cOpc = ' ';
  pintaQuadro();
  pintaPlacar();
  pintaPrincipal();
  gotoxy(25, 3);
  
  //Enquanto não for pressionado [Enter]
  while (cOpc != ENTER) {
    //Pega a tecla digitada
    cOpc = getch();
    
    //49 = 1 até 57 = 9
    if (cOpc >= 49 && cOpc <= 57){
      pintaOpcao(cOpc);
    }
    
    //32 = espaco
    if (cOpc == 32) {
      pintaPrincipal();
    }
    
    //Posicionando no fim da tela, e imprimindo a tecla apertada
    //gotoxy(nColFin-6,nLinFin-1);
    //printf("[%4d]",cOpc);
        
    gotoxy(25, 3);
  }
  
  //Limpando a tela, desenhando o quadro e imprimindo dados do projeto e espera o tempo pré estipulado
  limpar();
  pintaQuadro();
  gotoxy((nColFin/2)-9,4);
  printf("------------------");
  gotoxy((nColFin/2)-19,6);
  printf("Desenvolvedor  .........  Daniel Atilio");
  gotoxy((nColFin/2)-9,nLinFin-5);
  printf("Jogo da Veia v1.2");
  gotoxy((nColFin/2)-5,nLinFin-4);
  printf("18/07/2016");
  gotoxy((nColFin/2)-7,nLinFin-1);
  printf("Volte Sempre...\n");
  ESPERA;
  printf("\n");
}

void pintaQuadro(){
  int nAtu;
  
  //percorrendo as colunas e imprimindo na tela
  for (nAtu = 2; nAtu <= nColFin; nAtu++){
    gotoxy(nAtu, 1);
    printf("=");
    gotoxy(nAtu, nLinFin);
    printf("=");
  }
  
  //percorrendo as linhas e imprimindo na tela
  for (nAtu = 2; nAtu <= nLinFin; nAtu++){
    gotoxy(1, nAtu);
    printf("|");
    gotoxy(nColFin, nAtu);
    printf("|");
  }
  
  //imprimindo os asteriscos
  gotoxy(1,1);
  printf("*");
  gotoxy(nColFin, 1);
  printf("*");
  gotoxy(1, nLinFin);
  printf("*");
  gotoxy(nColFin, nLinFin);
  printf("*");
}

void titulo(){
  //posicionando no começo do quadro e imprimindo
  gotoxy(0,2);
  printf("     *-------*   *----*    *-----*   *----* \n");
  printf("     |__. .__|  |      |  |  .__.|  |      |\n");
  printf("        | |     | *--* |  | |       | *--* |\n");
  printf("        | |     | |  | |  | |  *-*  | |  | |\n");
  printf("     *--* |     | *--* |  | |  | |  | *--* |\n");
  printf("     |    |     |      |  | *--* |  |      |\n");
  printf("     *----*      *----*    *----*    *----*\n");
  printf("                    -> DA <-\n");
  printf("                       *-*\n");
  printf("                      / /\n");
  printf("                     *-*\n");
  printf("       *--* *--*  *------*  *---*      *    \n");
  printf("       |  | |  |  |  ____|  |   |     / \\   \n");
  printf("       *  * *  *  | |__.    |   |    /   \\  \n");
  printf("        \\  *  /   |  __|    |   |   /  *  \\  \n");
  printf("         \\   /    | |____.  |   |  *  * *  *\n");
  printf("          \\ /     |      |  |   |  |  | |  |\n");
  printf("           *      *------*  *---*  *--* *--*\n");
  gotoxy((nColFin/2)-7,nLinFin-4);
  printf("Jogo da Veia v1");
}

void limpar(){
  int nLinha = 0, nColuna = 0;
  
  //limpando a tela pelo comando do sistema
  LIMPA_TELA;
  
  //por precaução, percorre as linhas e colunas e imprime um espaço em branco, para não ficar nenhuma sujeira na tela
  for (nLinha = 1; nLinha <= nLinFin; nLinha++){
    for (nColuna = 1; nColuna <= nColFin; nColuna++){
      gotoxy(nColuna,nLinha);
      printf(" ");
    }
  }
}

void pintaPlacar(){
  int nAtu;
  //percorrendo as colunas e imprimindo na tela
  for (nAtu = 2; nAtu <= nColFin-1; nAtu++){
    gotoxy(nAtu, 5);
    printf("-");
  }
  
  //quadro você
  gotoxy(3, 2);
  printf("*----* Voce");
  gotoxy(3, 3);
  printf("| ;P |");
  gotoxy(3, 4);
  printf("*----* x %4d", nPlacarJog);
  
  //quadro máquina
  gotoxy(nColFin-1-21, 2);
  printf("       Maquina *----*");
  gotoxy(nColFin-1-21, 3);
  printf("               | XD |");
  gotoxy(nColFin-1-21, 4);
  printf("        x %4d *----*", nPlacarMaq);
  
  //separação
  gotoxy(25,2);
  printf("|");
  gotoxy(25,3);
  printf("x");
  gotoxy(25,4);
  printf("|");
}

void pintaPrincipal(){
  int nAtual;
  gotoxy((nColFin/2)-11,6);
  printf("       *      *       ");
  gotoxy((nColFin/2)-11,7);
  printf("       |      |       ");
  gotoxy((nColFin/2)-11,8);
  printf("       |      |       ");
  gotoxy((nColFin/2)-11,9);
  printf("       |      |       ");
  gotoxy((nColFin/2)-11,10);
  printf("*------*------*------*");
  gotoxy((nColFin/2)-11,11);
  printf("       |      |       ");
  gotoxy((nColFin/2)-11,12);
  printf("       |      |       ");
  gotoxy((nColFin/2)-11,13);
  printf("       |      |       ");
  gotoxy((nColFin/2)-11,14);
  printf("*------*------*------*");
  gotoxy((nColFin/2)-11,15);
  printf("       |      |       ");
  gotoxy((nColFin/2)-11,16);
  printf("       |      |       ");
  gotoxy((nColFin/2)-11,17);
  printf("       |      |       ");
  gotoxy((nColFin/2)-11,18);
  printf("       *      *       ");
  
  gotoxy(2,nLinFin-5);
  printf("[1][2][3] => Posicao");
  gotoxy(2,nLinFin-4);
  printf("[4][5][6] => Posicao");
  gotoxy(2,nLinFin-3);
  printf("[7][8][9] => Posicao");
  gotoxy(2,nLinFin-2);
  printf("[Espaco]  => Iniciar novo jogo");
  gotoxy(2,nLinFin-1);
  printf("[Enter]   => Finalizar");
  
  gotoxy((nColFin/2)-16,nLinFin-6);
  printf("                               ");
  
  for (nAtual = 0; nAtual <= 8; nAtual++)
    cUsados[nAtual] = ' ';
}

void pintaOpcao(char cPos){
  int nPosAtu = ("%d", cPos) - 48;
  int nColOpc = nColunas[nPosAtu-1];
  int nLinOpc = nLinhas[nPosAtu-1];
  int nColMaq = 0;
  int nLinMaq = 0;
  int nGanhou = 0; //0=empate;1=ganhou;2=perdeu;4=deu veia
  int nDispon = -1;
  int nAtual  = 0;
  int nPosMaq = 0;
  int nOk     = 0; //Quantas casas disponíveis
  int nTrava  = 0;
  int nRand   = -1;
  time_t tTempo;
   
  //caso já esteja preenchido
  if (cUsados[nPosAtu-1] != ' '){
    gotoxy((nColFin/2)-15,nLinFin-6);
    printf("Escolha uma posicao em branco!");
  }
  //caso tenha posição para preencher
  else {
    gotoxy((nColFin/2)-15,nLinFin-6);
    printf("                              ");
    cUsados[nPosAtu-1] = cEscolha;
    //pintando
    gotoxy(nColOpc,nLinOpc);
    //pinta X
    if(cEscolha == 'X'){
      printf("+  +");
      gotoxy(nColOpc,nLinOpc+1);
      printf(" ++ ");
      gotoxy(nColOpc,nLinOpc+2);
      printf("+  +");
    }
    //senão, pinta O
    else {
      printf(" -- ");
      gotoxy(nColOpc,nLinOpc+1);
      printf("-  -");
      gotoxy(nColOpc,nLinOpc+2);
      printf(" -- ");
    }
    
    //primeira linha
    if (cUsados[0] == cEscolha && cUsados[1] == cEscolha && cUsados[2] == cEscolha){
      gotoxy((nColFin/2)-6,nLinFin-6);
      printf("Voce Ganhou!");
      nGanhou = 1;
    }
    
    //segunda linha
    if (cUsados[3] == cEscolha && cUsados[4] == cEscolha && cUsados[5] == cEscolha){
      gotoxy((nColFin/2)-6,nLinFin-6);
      printf("Voce Ganhou!");
      nGanhou = 1;
    }
    
    //terceira linha
    if (cUsados[6] == cEscolha && cUsados[7] == cEscolha && cUsados[8] == cEscolha){
      gotoxy((nColFin/2)-6,nLinFin-6);
      printf("Voce Ganhou!");
      nGanhou = 1;
    }
    
    //primeira coluna
    if (cUsados[0] == cEscolha && cUsados[3] == cEscolha && cUsados[6] == cEscolha){
      gotoxy((nColFin/2)-6,nLinFin-6);
      printf("Voce Ganhou!");
      nGanhou = 1;
    }
    
    //segunda coluna
    if (cUsados[1] == cEscolha && cUsados[4] == cEscolha && cUsados[7] == cEscolha){
      gotoxy((nColFin/2)-6,nLinFin-6);
      printf("Voce Ganhou!");
      nGanhou = 1;
    }
    
    //terceira coluna
    if (cUsados[2] == cEscolha && cUsados[5] == cEscolha && cUsados[8] == cEscolha){
      gotoxy((nColFin/2)-6,nLinFin-6);
      printf("Voce Ganhou!");
      nGanhou = 1;
    }
    
    //diagonal
    if (cUsados[0] == cEscolha && cUsados[4] == cEscolha && cUsados[8] == cEscolha){
      gotoxy((nColFin/2)-6,nLinFin-6);
      printf("Voce Ganhou!");
      nGanhou = 1;
    }
    
    //diagonal /
    if (cUsados[2] == cEscolha && cUsados[4] == cEscolha && cUsados[6] == cEscolha){
      gotoxy((nColFin/2)-6,nLinFin-6);
      printf("Voce Ganhou!");
      nGanhou = 1;
    }
    
    //Percorrendo as posições, para ver se deu veia
    nOk = 0;
    for (nAtual = 0; nAtual <= 8; nAtual++){
      if (cUsados[nAtual] == ' ')
	nOk++;
    }
    //se não tiver nenhuma opção disponível, deu veia
    if (nOk == 0){
      nGanhou = 4;
      gotoxy((nColFin/2)-5,nLinFin-6);
      printf("Deu Veia!");
    }
    
    //Se o usuário não ganhou ainda
    if (nGanhou != 1 && nGanhou != 4){
      //verifica se tem duas posições preenchidas da máquina
      nDispon = retDispon(cMaquina);
      if (nDispon != -1){
	nColMaq = nColunas[nDispon];
	nLinMaq = nLinhas[nDispon];
	cUsados[nDispon] = cMaquina;
	//pintando
	gotoxy(nColMaq,nLinMaq);
	//pinta X
	if(cMaquina == 'X'){
	  printf("+  +");
	  gotoxy(nColMaq,nLinMaq+1);
	  printf(" ++ ");
	  gotoxy(nColMaq,nLinMaq+2);
	  printf("+  +");
	}
	//senão, pinta O
	else {
	  printf(" -- ");
	  gotoxy(nColMaq,nLinMaq+1);
	  printf("-  -");
	  gotoxy(nColMaq,nLinMaq+2);
	  printf(" -- ");
	}
      }
      else {
	//verifica se tem duas posições preenchidas do oponente
	nDispon = retDispon(cEscolha);
	if (nDispon != -1){  
	  nColMaq = nColunas[nDispon];
	  nLinMaq = nLinhas[nDispon];
	  cUsados[nDispon] = cMaquina;
	  //pintando
	  gotoxy(nColMaq,nLinMaq);
	  //pinta X
	  if(cMaquina == 'X'){
	    printf("+  +");
	    gotoxy(nColMaq,nLinMaq+1);
	    printf(" ++ ");
	    gotoxy(nColMaq,nLinMaq+2);
	    printf("+  +");
	  }
	  //senão, pinta O
	  else {
	    printf(" -- ");
	    gotoxy(nColMaq,nLinMaq+1);
	    printf("-  -");
	    gotoxy(nColMaq,nLinMaq+2);
	    printf(" -- ");
	  }
	}
	else{
	  //senão encontrar nenhuma, verifica se o meio está disponível
	  if (cUsados[4] == ' '){
	    nPosMaq = 4;
	  }
	  //Se o meio não estiver, utiliza um random, até conseguir algum canto
	  else {
	    //inicializa o random
	    srand((unsigned) time(&tTempo));
	    
	    while (nTrava == 0){
	      //Gera um valor randomico entre 0 e 8
	      nRand = rand() % 9;
	      
	      //Se o número tiver disponível, altera a trava
	      if (cUsados[nRand] == ' '){
		nPosMaq = nRand;
	        nTrava = 1;
	      }
	    }
	  }
	  
	  nColMaq = nColunas[nPosMaq];
	  nLinMaq = nLinhas[nPosMaq];
	  cUsados[nPosMaq] = cMaquina;
	  //pintando
	  gotoxy(nColMaq,nLinMaq);
	  //pinta X
	  if(cMaquina == 'X'){
	    printf("+  +");
	    gotoxy(nColMaq,nLinMaq+1);
	    printf(" ++ ");
	    gotoxy(nColMaq,nLinMaq+2);
	    printf("+  +");
	  }
	  //senão, pinta O
	  else {
	    printf(" -- ");
	    gotoxy(nColMaq,nLinMaq+1);
	    printf("-  -");
	    gotoxy(nColMaq,nLinMaq+2);
	    printf(" -- ");
	  }
	}
      }
    } //Se o usuário não ganhou ainda
    
    //primeira linha
    if (cUsados[0] == cMaquina && cUsados[1] == cMaquina && cUsados[2] == cMaquina){
      gotoxy((nColFin/2)-9,nLinFin-6);
      printf("Maquina Ganhou!");
      nGanhou = 2;
    }
    
    //segunda linha
    if (cUsados[3] == cMaquina && cUsados[4] == cMaquina && cUsados[5] == cMaquina){
      gotoxy((nColFin/2)-9,nLinFin-6);
      printf("Maquina Ganhou!");
      nGanhou = 2;
    }
    
    //terceira linha
    if (cUsados[6] == cMaquina && cUsados[7] == cMaquina && cUsados[8] == cMaquina){
      gotoxy((nColFin/2)-9,nLinFin-6);
      printf("Maquina Ganhou!");
      nGanhou = 2;
    }
    
    //primeira coluna
    if (cUsados[0] == cMaquina && cUsados[3] == cMaquina && cUsados[6] == cMaquina){
      gotoxy((nColFin/2)-9,nLinFin-6);
      printf("Maquina Ganhou!");
      nGanhou = 2;
    }
    
    //segunda coluna
    if (cUsados[1] == cMaquina && cUsados[4] == cMaquina && cUsados[7] == cMaquina){
      gotoxy((nColFin/2)-9,nLinFin-6);
      printf("Maquina Ganhou!");
      nGanhou = 2;
    }
    
    //terceira coluna
    if (cUsados[2] == cMaquina && cUsados[5] == cMaquina && cUsados[8] == cMaquina){
      gotoxy((nColFin/2)-9,nLinFin-6);
      printf("Maquina Ganhou!");
      nGanhou = 2;
    }
    
    //diagonal
    if (cUsados[0] == cMaquina && cUsados[4] == cMaquina && cUsados[8] == cMaquina){
      gotoxy((nColFin/2)-9,nLinFin-6);
      printf("Maquina Ganhou!");
      nGanhou = 2;
    }
    
    //diagonal /
    if (cUsados[2] == cMaquina && cUsados[4] == cMaquina && cUsados[6] == cMaquina){
      gotoxy((nColFin/2)-9,nLinFin-6);
      printf("Maquina Ganhou!");
      nGanhou = 2;
    }
    
  }
  
  //Se jogador ganhou, aumenta o placar
  if (nGanhou == 1){
    nPlacarJog++;
  }
  //Se máquina ganhou, aumenta o placar
  else if (nGanhou == 2){
    nPlacarMaq++;
  }
  pintaPlacar();
  
  //Se alguém ganhou, pinta as posições vazias
  if (nGanhou != 0){
    for (nAtual = 0; nAtual <= 8; nAtual++)
      if (cUsados[nAtual] == ' ')
        cUsados[nAtual] = 'Z';
  }
  
  //Verificando posições
  /*for (nAtual = 0; nAtual <= 8; nAtual++){
    gotoxy(nColFin-1-nAtual,nLinFin-5);
    printf("%c",cUsados[nAtual]);
  }*/
}

int retDispon(char cJogada){
  int nPosicao = -1;
  
  //Linha 1: [Z][Z][ ]
  if ((cUsados[0] == cJogada) && (cUsados[1] == cJogada) && (cUsados[2] == ' '))
    return 2;
  //Linha 1: [Z][ ][Z]
  if ((cUsados[0] == cJogada) && (cUsados[1] == ' ') && (cUsados[2] == cJogada))
    return 1;
  //Linha 1: [ ][Z][Z]
  if ((cUsados[0] == ' ') && (cUsados[1] == cJogada) && (cUsados[2] == cJogada))
    return 0;
  
//*****************************************//
  
  //Linha 2: [Z][Z][ ]
  if ((cUsados[3] == cJogada) && (cUsados[4] == cJogada) && (cUsados[5] == ' '))
    return 5;
  //Linha 2: [Z][ ][Z]
  if ((cUsados[3] == cJogada) && (cUsados[4] == ' ') && (cUsados[5] == cJogada))
    return 4;
  //Linha 2: [ ][Z][Z]
  if ((cUsados[3] == ' ') && (cUsados[4] == cJogada) && (cUsados[5] == cJogada))
    return 3;

//*****************************************//
  
  //Linha 3: [Z][Z][ ]
  if ((cUsados[6] == cJogada) && (cUsados[7] == cJogada) && (cUsados[8] == ' '))
    return 8;
  //Linha 3: [Z][ ][Z]
  if ((cUsados[6] == cJogada) && (cUsados[7] == ' ') && (cUsados[8] == cJogada))
    return 7;
  //Linha 3: [ ][Z][Z]
  if ((cUsados[6] == ' ') && (cUsados[7] == cJogada) && (cUsados[8] == cJogada))
    return 6;
  
//*****************************************//
  
  /*Coluna 1:
   [Z]
   [Z]
   [ ]
  */
  if ((cUsados[0] == cJogada) && (cUsados[3] == cJogada) && (cUsados[6] == ' '))
    return 6;
  /*Coluna 1:
   [Z]
   [ ]
   [Z]
  */
  if ((cUsados[0] == cJogada) && (cUsados[3] == ' ') && (cUsados[6] == cJogada))
    return 3;
  /*Coluna 1:
   [ ]
   [Z]
   [Z]
  */
  if ((cUsados[0] == ' ') && (cUsados[3] == cJogada) && (cUsados[6] == cJogada))
    return 0;
  
//*****************************************//
  
  /*Coluna 2:
   [Z]
   [Z]
   [ ]
  */
  if ((cUsados[1] == cJogada) && (cUsados[4] == cJogada) && (cUsados[7] == ' '))
    return 7;
  /*Coluna 2:
   [Z]
   [ ]
   [Z]
  */
  if ((cUsados[1] == cJogada) && (cUsados[4] == ' ') && (cUsados[7] == cJogada))
    return 4;
  /*Coluna 2:
   [ ]
   [Z]
   [Z]
  */
  if ((cUsados[1] == ' ') && (cUsados[4] == cJogada) && (cUsados[7] == cJogada))
    return 1;
  
//*****************************************//
  
  /*Coluna 3:
   [Z]
   [Z]
   [ ]
  */
  if ((cUsados[2] == cJogada) && (cUsados[5] == cJogada) && (cUsados[8] == ' '))
    return 8;
  /*Coluna 3:
   [Z]
   [ ]
   [Z]
  */
  if ((cUsados[2] == cJogada) && (cUsados[5] == ' ') && (cUsados[8] == cJogada))
    return 5;
  /*Coluna 3:
   [ ]
   [Z]
   [Z]
  */
  if ((cUsados[2] == ' ') && (cUsados[5] == cJogada) && (cUsados[8] == cJogada))
    return 2;
  
//*****************************************//
  
  /*Diagonal Esquerda
    [Z]
       [Z]
          [ ]
  */
  if ((cUsados[0] == cJogada) && (cUsados[4] == cJogada) && (cUsados[8] == ' '))
    return 8;
  
  /*Diagonal Esquerda
    [Z]
       [ ]
          [Z]
  */
  if ((cUsados[0] == cJogada) && (cUsados[4] == ' ') && (cUsados[8] == cJogada))
    return 4;
  
  /*Diagonal Esquerda
    [ ]
       [Z]
          [Z]
  */
  if ((cUsados[0] == ' ') && (cUsados[4] == cJogada) && (cUsados[8] == cJogada))
    return 0;
  
//*****************************************//
  
  /*Diagonal Direita
          [Z]
       [Z]
    [ ]
  */
  if ((cUsados[2] == cJogada) && (cUsados[4] == cJogada) && (cUsados[6] == ' '))
    return 6;
  
  /*Diagonal Direita
          [Z]
       [ ]
    [Z]
  */
  if ((cUsados[2] == cJogada) && (cUsados[4] == ' ') && (cUsados[6] == cJogada))
    return 4;
  
  /*Diagonal Direita
          [ ]
       [Z]
    [Z]
  */
  if ((cUsados[2] == ' ') && (cUsados[4] == cJogada) && (cUsados[6] == cJogada))
    return 2;
  
  return nPosicao;
}