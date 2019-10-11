/*
 * Links de apoio:
 * 
 * https://www.programiz.com/c-programming/examples/binary-decimal-convert
 * https://codeforwin.org/2015/09/c-program-to-convert-hexadecimal-to-decimal-number-system.html
 * https://www.programiz.com/c-programming/examples/octal-decimal-convert
 * 
 */

//Bibliotecas
#include <stdio.h>
#include <math.h>
#include <string.h>

//Chamadas das funções
int converterBin2Dec(long long valor_binario);
long long converterDec2Bin(int valor_decimal);
int converterDec2Oct(int valor_decimal);
long long converterOct2Dec(int valor_octal);

int main()
{
	
	//Variáveis usadas
	char opc = ' ';
	int valor_octal;
	long long valor_binario;
	int valor_decimal, cociente;
	int sequencial, valor_temp, tamanho_string;
	char valor_hexa[100];
	
	//Enquanto não for a opção 0 (Sair)
	while (opc != '0') {
		
		//Mostra o menu principal
		printf("\n----------------------\n");
		printf("Digite a Opcao\n");
		printf("1 - Binario para Decimal\n");
		printf("2 - Binario para Octal\n");
		printf("3 - Decimal para Binario\n");
		printf("4 - Decimal para Octal\n");
		printf("5 - Decimal para Hexa\n");
		printf("6 - Octal para Decimal\n");
		printf("7 - Hexa para Decimal\n");
		printf("0 - Sair\n");
		printf("Resposta: ");
		scanf("%c", &opc);
		getchar();
		
		//Opção 1 - Binário -> Decimal
		if (opc == '1') {
			printf("Digite numero binario: ");
			scanf("%lld", &valor_binario);
			printf("[%lld] em binario = [%d] em decimal\n", valor_binario, converterBin2Dec(valor_binario));
		}
		
		//Opção 2 - Binário -> Octal
		else if (opc == '2') {
			printf("Digite numero binario: ");
			scanf("%lld", &valor_binario);
			valor_decimal = converterBin2Dec(valor_binario);
			valor_octal   = converterDec2Oct(valor_decimal);
			printf("[%lld] em binario = [%d] em octal\n", valor_binario, valor_octal);
		}
		
		//Opção 3 - Decimal -> Binário
		else if (opc == '3') {
			printf("Digite o numero decimal: ");
			scanf("%d", &valor_decimal);
			printf("[%d] em decimal = [%lld] em binario\n", valor_decimal, converterDec2Bin(valor_decimal));
		}
		
		//Opção 4 - Decimal -> Octal
		else if (opc == '4') {
			printf("Digite o numero decimal: ");
			scanf("%d", &valor_decimal);
			printf("[%d] em decimal = [%d] em octal\n", valor_decimal, converterDec2Oct(valor_decimal));
		}
		
		//Opção 5 - Decimal -> Hexadecimal
		else if (opc == '5') {
			printf("Digite o numero decimal: ");
			scanf("%d", &valor_decimal);
			
			//Zerando variáveis
			sequencial = 0;
			cociente = valor_decimal;
			
			//Enquanto tiver cociente
			while (cociente != 0) {
				//Pega o resto da divisão por 16
				valor_temp = cociente % 16;
				
				//Se for menor que 10, soma com 48 (tabela ascii - parte de números)
				if( valor_temp < 10)
					valor_temp = valor_temp + 48;
					
				//Senão, soma com 55 (tabela ascii - parte de letras)
				else
					valor_temp = valor_temp + 55;
				
				//Joga o caracter na sequência da string
				valor_hexa[sequencial++] = valor_temp;
				
				//Divide o resto por 16
				cociente = cociente / 16;
			}
			//Encerra a string e mostra a mensagem
			valor_hexa[sequencial++] = '\0';
			printf("[%d] em decimal = [%s] em hexa", valor_decimal, valor_hexa);
		}
		
		//Opção 6 - Octal -> Decimal
		else if (opc == '6') {
			printf("Digite o numero octal: ");
			scanf("%d", &valor_octal);
			printf("[%d] em octal = [%lld] em decimal\n", valor_octal, converterOct2Dec(valor_octal));
		}
		
		//Opção 7 - Hexa -> Decimal
		else if (opc == '7') {
			//Zera a variável de valor Decimal
			valor_decimal = 0;
			
			//Mostra mensagem para inserir valor hexa
			printf("Insira o valor hexa: ");
			gets(valor_hexa);

			//Pega o tamanho da string
			tamanho_string = strlen(valor_hexa);
			tamanho_string--;
			
			//Percorre todas as posições da string
			for(sequencial=0; valor_hexa[sequencial]!='\0'; sequencial++)
			{
				//Se for maior ou igual a 0 e menor ou igual a 9, será o valor retirando 48 (tabela ascii)
				if(valor_hexa[sequencial]>='0' && valor_hexa[sequencial]<='9')
				{
					valor_temp = valor_hexa[sequencial] - 48;
				}
				
				//Se for maior ou igual a a e menor ou igual a f, será o valor retirando 97 (tabela ascii) + 10 (0 a 9)
				else if(valor_hexa[sequencial]>='a' && valor_hexa[sequencial]<='f')
				{
					valor_temp = valor_hexa[sequencial] - 97 + 10;
				}
				
				//Se for maior ou igual a A e menor ou igual a F, será o valor retirando 65 (tabela ascii) + 10 (0 a 9)
				else if(valor_hexa[sequencial]>='A' && valor_hexa[sequencial]<='F')
				{
					valor_temp = valor_hexa[sequencial] - 65 + 10;
				}
				
				//Incrementa o valor decimal multiplicando o valor por 16 elevado à potência
				valor_decimal += valor_temp * pow(16, tamanho_string);
				tamanho_string--;
			}
			printf("[%s] em hexa = [%d] em decimal", valor_hexa, valor_decimal);
		}
		
		//Opção desconhecida
		else {
			printf("Opcao desconhecida [%c]\n", opc);
		}
	}
	
	return 0;
}

//Função para converter Binário para Decimal
int converterBin2Dec(long long valor_binario)
{
    int valor_decimal = 0, sequencial = 0, resto;
    
    //Enquanto existir valor no binário
    while (valor_binario != 0)
    {
		//Pega o resto da divisão do valor binário por 10
        resto = valor_binario % 10;
        
        //Divide o valor binário por 10
        valor_binario /= 10;
        
        //Incrementa o valor decimal com o resto da divisão multiplicado por 2 elevado ao sequencial
        valor_decimal += resto * pow(2, sequencial);
        
        //Incrementa a sequencial
        ++sequencial;
    }
    
    return valor_decimal;
}

//Função para converter Decimal para Binário
long long converterDec2Bin(int valor_decimal)
{
    long long valor_binario = 0;
    int resto, sequencial = 1;

	//Enquanto o valor decimal for diferente de zero
    while (valor_decimal != 0)
    {
		//Pega o resto da divisão
        resto = valor_decimal % 2;
        
        //Divide o valor decimal por 2
        valor_decimal /= 2;
        
        //Incrementa o valor binário, multiplicando o resto da divisão pelo sequencial
        valor_binario += resto * sequencial;
        
        //Multiplica o sequencial por 10
        sequencial *= 10;
    }
    
    return valor_binario;
}

//Função para converter Decimal para Octal
int converterDec2Oct(int valor_decimal)
{
    int valor_octal = 0, sequencia = 1;
	
	//Enquanto o valor decimal for diferente de zero
    while (valor_decimal != 0)
    {
		//Incrementa o valor octal com o resto da divisão do decimal por 8 multiplicado pelo sequencial
        valor_octal += (valor_decimal % 8) * sequencia;
        
        //O valor decimal será dividido por 8
        valor_decimal /= 8;
        
        //O sequencial sera multiplicado por 10
        sequencia *= 10;
    }

    return valor_octal;
}

//Função para converter Octal para Decimal
long long converterOct2Dec(int valor_octal)
{
    int valor_decimal = 0, sequencia = 0;

	//Enquanto o valor octal for diferente de zero
    while(valor_octal != 0)
    {
		//Incrementa o valor decimal com o resto da divisão do valor octal por 10 multiplicado por 8 elevado pelo sequencial
        valor_decimal += (valor_octal % 10) * pow(8, sequencia);
        
        //Incrementa o sequencial
        ++sequencia;
        
        //Divide o valor octal por 10
        valor_octal /= 10;
    }

    return valor_decimal;
}
