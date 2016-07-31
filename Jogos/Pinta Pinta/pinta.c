/*================================================*
 * Jogo   - Pinta Pinta                           |
 * Versao - 1.2                                   |
 * Autor  - Daniel Atilio                         |
 *================================================*/

//Biblioteca
#include <stdio.h>


//Se o sistema for Windows, utiliza a conio e a limpeza é via cls
#ifdef WIN32
  #include <conio.h>
  #include <windows.h>
  #define LIMPA_TELA system("cls");
  int ENTER         = 13;
  int SETA_CIMA     = 72;
  int SETA_BAIXO    = 80;
  int SETA_DIREITA  = 77;
  int SETA_ESQUERDA = 75;
  
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
  int ENTER         = 10;
  int SETA_CIMA     = 65;
  int SETA_BAIXO    = 66;
  int SETA_DIREITA  = 67;
  int SETA_ESQUERDA = 68;
#endif

//Espera 2 segundos
#define ESPERA sleep(2);

//Funções utilizadas
void pintaQuadro();      //função que desenha o quadro utilizado no programa
void titulo();           //função que desenha a tela de título
void traduz(char cChar); //função que traduz um caracter conforme tabela asciii
void limpar();           //função para limpar a tela
void ee();               //Easter Egg

//Variáveis utilizadas no fonte inteiro
int nLinFin = 23;
int nColFin = 43;
char sTexto[50] = "[Espaco]=(Des)Pinta     [Enter]=Finalizar\0";

//programa principal
main(){
  char cOpc = ' ';
  char cCarac = '#';
  char cCar1 = ' ', cCar2 = ' ', cCar3 = ' ', cCar4 = ' ', cCar5 = ' ', cCar6 = ' ';
  int nLinAtu = 5;
  int nColAtu = 5;

  //montagem da tela de título
  limpar();
  titulo();
  pintaQuadro();
  gotoxy(2,nLinFin-1);
  printf("     Pressione [ENTER] para iniciar...");
  
  //Aguardando o usuário apertar o [Enter]
  cOpc = getch();
  while (cOpc != ENTER) {
    cOpc = getch();
  }
  
  //Criação do quadro e posicionamento para começar o jogo
  limpar();
  cOpc = ' ';
  pintaQuadro();
  gotoxy(2, nLinFin-1);
  printf("%s", sTexto);
  gotoxy(nColAtu, nLinAtu);
  
  //Enquanto não for pressionado [Enter]
  while (cOpc != ENTER) {
    //Pega a tecla digitada
    cOpc = getch();
    
    //Se for a tecla espaço, inverte o caracter, ou sustenido ou espaço em branco
    if (cOpc == 32){
      if (cCarac == '#')
        cCarac = ' ';
      else
	cCarac = '#';
    }
      
    //Se for seta pra direita, aumenta a posição da coluna
    if (cOpc == SETA_DIREITA)
      nColAtu++;
    
    //Se for seta para esquerda, diminui a posição da coluna
    if (cOpc == SETA_ESQUERDA)
      nColAtu--;
    
    //Se for seta para cima, aumenta a posição da linha
    if (cOpc == SETA_BAIXO)
      nLinAtu++;
    
    //Se for seta para baixo, diminui a posição da linha
    if (cOpc == SETA_CIMA)
      nLinAtu--;
    
    //Se tiver na última coluna, não prossegue (para não estourar a tela)
    if (nColAtu == nColFin)
      nColAtu--;
    
    //Se tiver na primeira coluna, não prossegue (para não estourar a tela)
    if (nColAtu == 1)
      nColAtu++;
    
    //Se tiver na última linha, não prossegue (para não estourar a tela)
    if (nLinAtu == nLinFin-3)
      nLinAtu--;
    
    //Se tiver na primeira linha, não prossegue (para não estourar a tela)
    if (nLinAtu == 1)
      nLinAtu++;
    
    //Posicionando no fim da tela, e imprimindo a tecla apertada e a tradução conforme a tabela ASCII
    gotoxy(3,nLinFin-2);
    printf("[%4d] ",cOpc);
    traduz(cOpc);
    
    //Posicionando na linha atual e coluna atual e imprimindo o caracter (ou sustenido ou espaço em branco)
    gotoxy(nColAtu, nLinAtu);
    printf("%c",cCarac);
    gotoxy(nColAtu, nLinAtu);
    
    //Atualizando caracteres extras
    cCar1 = cCar2;
    cCar2 = cCar3;
    cCar3 = cCar4;
    cCar4 = cCar5;
    cCar5 = cCar6;
    cCar6 = cOpc;
    
    //Se os caracteres formarem a palavra atilio, mostra um Easter Egg ao usuário
    if (cCar1 == 'a' && cCar2 == 't' && cCar3 == 'i' && cCar4 == 'l' && cCar5 == 'i' && cCar6 == 'o'){
      limpar();
      cOpc = ' ';
      cCar1 = ' ';
      cCar2 = ' ';
      cCar3 = ' ';
      cCar4 = ' ';
      cCar5 = ' ';
      cCar6 = ' ';
      pintaQuadro();
      ee();
      gotoxy(2,nLinFin-1);
      printf("%s",sTexto);
      gotoxy(nColAtu, nLinAtu);
    }
  }
  
  //Limpando a tela, desenhando o quadro e imprimindo dados do projeto e espera o tempo pré estipulado
  limpar();
  pintaQuadro();
  gotoxy(2,4);
  printf("           ------------------");
  gotoxy(2,6);
  printf(" Desenvolvedor  .........  Daniel Atilio");
  gotoxy(2,nLinFin-6);
  printf("           Pinta Pinta v1.2");
  gotoxy(2,nLinFin-5);
  printf("               18/07/2016");
  gotoxy(2,nLinFin-1);
  printf("      Apertou o [Enter] ne safadao!\n\n");
  ESPERA;
}

void pintaQuadro(){
  int nAtu;
  
  //percorrendo as colunas e imprimindo na tela
  for (nAtu = 2; nAtu <= nColFin; nAtu++){
    gotoxy(nAtu, 1);
    printf("=");
    gotoxy(nAtu, nLinFin);
    printf("=");
    gotoxy(nAtu, nLinFin-3);
    printf("-");
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
  gotoxy(1, nLinFin-3);
  printf("*");
  gotoxy(nColFin, nLinFin-3);
  printf("*");
}

void titulo(){
  //posicionando no começo do quadro e imprimindo
  gotoxy(0,2);
  printf("  >>>>    >>>  >>>  >>>  >>>>>>>    >>>\n");
  printf("  >   >   > >  >  > > >  >>   >>   >   >\n");
  printf("  >    >  > >  >   >  >    > >    >     >\n");
  printf("  >   >   > >  > >    >    > >    > >>> >\n");
  printf("  >  >    > >  > >>   >    > >    > > > >\n");
  printf("  > >     > >  > > >  >    > >    > > > >\n");
  printf("  >>>     >>>  >>>  >>>    >>>    >>> >>>\n");
  printf("\n");
  printf("  >>>>    >>>  >>>  >>>  >>>>>>>    >>>\n");
  printf("  >###>   >#>  >##> >#>  >>###>>   >###>\n");
  printf("  >####>  >#>  >###>##>    >#>    >#####>\n");
  printf("  >###>   >#>  >#>####>    >#>    >#>>>#>\n");
  printf("  >##>    >#>  >#>>###>    >#>    >#> >#>\n");
  printf("  >#>     >#>  >#> >##>    >#>    >#> >#>\n");
  printf("  >>>     >>>  >>>  >>>    >>>    >>> >>>\n");
  printf("\n");
  printf("            Pinta Pinta v1.2\n");
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

void traduz(char cChar){
  //imprimindo um texto em branco para limpar a última saída
  gotoxy(10,nLinFin-2);
  printf("                         ");
  
  //imprimindo a descrição do caracter da tabela ASCII
  gotoxy(10,nLinFin-2);
  if (cChar == 0)   printf("Null");
  if (cChar == 1)   printf("Start of Heading");
  if (cChar == 2)   printf("Start of Text");
  if (cChar == 3)   printf("End of Text");
  if (cChar == 4)   printf("End of Transmission");
  if (cChar == 5)   printf("Enquiry");
  if (cChar == 6)   printf("Acknowledge");
  if (cChar == 7)   printf("Bell, rings terminal bell");
  if (cChar == 8)   printf("BackSpace");
  if (cChar == 9)   printf("Horizontal Tab");
  if (cChar == 10)  printf("Line Feed");
  if (cChar == 11)  printf("Vertical Tab");
  if (cChar == 12)  printf("Form Feed");
  if (cChar == 13)  printf("Enter");
  if (cChar == 14)  printf("Shift-Out");
  if (cChar == 15)  printf("Shift-In");
  if (cChar == 16)  printf("Data Link Escape");
  if (cChar == 17)  printf("Device Control 1");
  if (cChar == 18)  printf("Device Control 2");
  if (cChar == 19)  printf("Device Control 3");
  if (cChar == 20)  printf("Device Control 4");
  if (cChar == 21)  printf("Negative Acknowledge");
  if (cChar == 22)  printf("Synchronous idle");
  if (cChar == 23)  printf("End Transmission Block");
  if (cChar == 24)  printf("Cancel line");
  if (cChar == 25)  printf("End of Medium");
  if (cChar == 26)  printf("Substitute");
  if (cChar == 27)  printf("Escape");
  if (cChar == 28)  printf("File Separator");
  if (cChar == 29)  printf("Group Separator");
  if (cChar == 30)  printf("Record Separator");
  if (cChar == 31)  printf("Unit Separator");
  if (cChar == 32)  printf("Space");
  if (cChar == 33)  printf("!");
  if (cChar == 34)  printf("\"");
  if (cChar == 35)  printf("#");
  if (cChar == 36)  printf("$");
  if (cChar == 37)  printf("%");
  if (cChar == 38)  printf("&");
  if (cChar == 39)  printf("'");
  if (cChar == 40)  printf("(");
  if (cChar == 41)  printf(")");
  if (cChar == 42)  printf("*");
  if (cChar == 43)  printf("+");
  if (cChar == 44)  printf(",");
  if (cChar == 45)  printf("-");
  if (cChar == 46)  printf(".");
  if (cChar == 47)  printf("/");
  if (cChar == 48)  printf("0");
  if (cChar == 49)  printf("1");
  if (cChar == 50)  printf("2");
  if (cChar == 51)  printf("3");
  if (cChar == 52)  printf("4");
  if (cChar == 53)  printf("5");
  if (cChar == 54)  printf("6");
  if (cChar == 55)  printf("7");
  if (cChar == 56)  printf("8");
  if (cChar == 57)  printf("9");
  if (cChar == 58)  printf(":");
  if (cChar == 59)  printf(";");
  if (cChar == 60)  printf("<");
  if (cChar == 61)  printf("=");
  if (cChar == 62)  printf(">");
  if (cChar == 63)  printf("?");
  if (cChar == 64)  printf("@");
  if (cChar == 65)  printf("A / Seta para Cima");
  if (cChar == 66)  printf("B / Seta para Baixo");
  if (cChar == 67)  printf("C / Seta para Direita");
  if (cChar == 68)  printf("D / Seta para Esquerda");
  if (cChar == 69)  printf("E");
  if (cChar == 70)  printf("F");
  if (cChar == 71)  printf("G");
  if (cChar == 72)  printf("H");
  if (cChar == 73)  printf("I");
  if (cChar == 74)  printf("J");
  if (cChar == 75)  printf("K");
  if (cChar == 76)  printf("L");
  if (cChar == 77)  printf("M");
  if (cChar == 78)  printf("N");
  if (cChar == 79)  printf("O");
  if (cChar == 80)  printf("P");
  if (cChar == 81)  printf("Q");
  if (cChar == 82)  printf("R");
  if (cChar == 83)  printf("S");
  if (cChar == 84)  printf("T");
  if (cChar == 85)  printf("U");
  if (cChar == 86)  printf("V");
  if (cChar == 87)  printf("W");
  if (cChar == 88)  printf("X");
  if (cChar == 89)  printf("Y");
  if (cChar == 90)  printf("Z");
  if (cChar == 91)  printf("[");
  if (cChar == 92)  printf("\\");
  if (cChar == 93)  printf("]");
  if (cChar == 94)  printf("^");
  if (cChar == 95)  printf("_");
  if (cChar == 96)  printf("`");
  if (cChar == 97)  printf("a");
  if (cChar == 98)  printf("b");
  if (cChar == 99)  printf("c");
  if (cChar == 100) printf("d");
  if (cChar == 101) printf("e");
  if (cChar == 102) printf("f");
  if (cChar == 103) printf("g");
  if (cChar == 104) printf("h");
  if (cChar == 105) printf("i");
  if (cChar == 106) printf("j");
  if (cChar == 107) printf("k");
  if (cChar == 108) printf("l");
  if (cChar == 109) printf("m");
  if (cChar == 110) printf("n");
  if (cChar == 111) printf("o");
  if (cChar == 112) printf("p");
  if (cChar == 113) printf("q");
  if (cChar == 114) printf("r");
  if (cChar == 115) printf("s");
  if (cChar == 116) printf("t");
  if (cChar == 117) printf("u");
  if (cChar == 118) printf("v");
  if (cChar == 119) printf("w");
  if (cChar == 120) printf("x");
  if (cChar == 121) printf("y");
  if (cChar == 122) printf("z");
  if (cChar == 123) printf("{");
  if (cChar == 124) printf("|");
  if (cChar == 125) printf("}");
  if (cChar == 126) printf("~");
  if (cChar == 127) printf("Delete");
  if (cChar == 128) printf("Ç");
  if (cChar == 129) printf("ü");
  if (cChar == 130) printf("é");
  if (cChar == 131) printf("â");
  if (cChar == 132) printf("ä");
  if (cChar == 133) printf("à");
  if (cChar == 134) printf("å");
  if (cChar == 135) printf("ç");
  if (cChar == 136) printf("ê");
  if (cChar == 137) printf("ë");
  if (cChar == 138) printf("è");
  if (cChar == 139) printf("ï");
  if (cChar == 140) printf("î");
  if (cChar == 141) printf("ì");
  if (cChar == 142) printf("Ä");
  if (cChar == 143) printf("Å");
  if (cChar == 144) printf("É");
  if (cChar == 145) printf("æ");
  if (cChar == 146) printf("Æ");
  if (cChar == 147) printf("ô");
  if (cChar == 148) printf("ö");
  if (cChar == 149) printf("ò");
  if (cChar == 150) printf("û");
  if (cChar == 151) printf("ù");
  if (cChar == 152) printf("ÿ");
  if (cChar == 153) printf("Ö");
  if (cChar == 154) printf("Ü");
  if (cChar == 155) printf("ø");
  if (cChar == 156) printf("£");
  if (cChar == 157) printf("Ø");
  if (cChar == 158) printf("×");
  if (cChar == 159) printf("ƒ");
  if (cChar == 160) printf("á");
  if (cChar == 161) printf("ù");
  if (cChar == 162) printf("ó");
  if (cChar == 163) printf("ú");
  if (cChar == 164) printf("ñ");
  if (cChar == 165) printf("Ñ");
  if (cChar == 166) printf("a");
  if (cChar == 167) printf("o");
  if (cChar == 168) printf("¿");
  if (cChar == 169) printf("®");
  if (cChar == 170) printf("¬");
  if (cChar == 171) printf("1⁄2");
  if (cChar == 172) printf("1⁄4");
  if (cChar == 173) printf("¡");
  if (cChar == 174) printf("«");
  if (cChar == 175) printf("»");
  if (cChar == 176) printf("░");
  if (cChar == 177) printf("▒");
  if (cChar == 178) printf("▓");
  if (cChar == 179) printf("│");
  if (cChar == 180) printf("┤");
  if (cChar == 181) printf("Á");
  if (cChar == 182) printf("Â");
  if (cChar == 183) printf("À");
  if (cChar == 184) printf("©");
  if (cChar == 185) printf("╣");
  if (cChar == 186) printf("║");
  if (cChar == 187) printf("╗");
  if (cChar == 188) printf("╝");
  if (cChar == 189) printf("¢");
  if (cChar == 190) printf("¥");
  if (cChar == 191) printf("┐");
  if (cChar == 192) printf("└");
  if (cChar == 193) printf("┴");
  if (cChar == 194) printf("┬");
  if (cChar == 195) printf("├");
  if (cChar == 196) printf("─");
  if (cChar == 197) printf("┼");
  if (cChar == 198) printf("ã");
  if (cChar == 199) printf("Ã");
  if (cChar == 200) printf("╚");
  if (cChar == 201) printf("╔");
  if (cChar == 202) printf("╩");
  if (cChar == 203) printf("╦");
  if (cChar == 204) printf("╠");
  if (cChar == 205) printf("═");
  if (cChar == 206) printf("╬");
  if (cChar == 207) printf("¤");
  if (cChar == 208) printf("ð");
  if (cChar == 209) printf("Ð");
  if (cChar == 210) printf("Ê");
  if (cChar == 211) printf("Ë");
  if (cChar == 212) printf("È");
  if (cChar == 213) printf("ı");
  if (cChar == 214) printf("Í");
  if (cChar == 215) printf("Î");
  if (cChar == 216) printf("Ï");
  if (cChar == 217) printf("┘");
  if (cChar == 218) printf("┌");
  if (cChar == 219) printf("█");
  if (cChar == 220) printf("▄");
  if (cChar == 221) printf("¦");
  if (cChar == 222) printf("Ì");
  if (cChar == 223) printf("▀");
  if (cChar == 224) printf("Ó");
  if (cChar == 225) printf("ß");
  if (cChar == 226) printf("Ô");
  if (cChar == 227) printf("Ò");
  if (cChar == 228) printf("õ");
  if (cChar == 229) printf("Õ");
  if (cChar == 230) printf("μ");
  if (cChar == 231) printf("þ");
  if (cChar == 232) printf("Þ");
  if (cChar == 233) printf("Ú");
  if (cChar == 234) printf("Û");
  if (cChar == 235) printf("Ù");
  if (cChar == 236) printf("ý");
  if (cChar == 237) printf("Ý");
  if (cChar == 238) printf(" ̄");
  if (cChar == 239) printf(" ́");
  if (cChar == 240) printf("");
  if (cChar == 241) printf("±");
  if (cChar == 242) printf(" ̳");
  if (cChar == 243) printf("3⁄4");
  if (cChar == 244) printf("¶");
  if (cChar == 245) printf("§");
  if (cChar == 246) printf("÷");
  if (cChar == 247) printf(" ̧");
  if (cChar == 248) printf("°");
  if (cChar == 249) printf(" ̈");
  if (cChar == 250) printf("·");
  if (cChar == 251) printf("1");
  if (cChar == 252) printf("3");
  if (cChar == 253) printf("2");
  if (cChar == 254) printf("■");
  if (cChar == 255) printf("");
}

void ee(){
  int nLin = 8;
  //imprimindo 'joinha' e mensagem
  gotoxy(12,nLin);
  printf("      ###           ");
  gotoxy(12,nLin+1);
  printf("      # ##  ####    ");
  gotoxy(12,nLin+2);
  printf("  #####   ###  #    ");
  gotoxy(12,nLin+3);
  printf("   ##       #  #    ");
  gotoxy(12,nLin+4);
  printf("    ##     ##  #    ");
  gotoxy(12,nLin+5);
  printf("     ###### ####    ");
  gotoxy(15,nLinFin-2);
  printf("Dani approves...",sTexto);
}