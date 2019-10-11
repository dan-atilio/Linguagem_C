#include <stdio.h>
#include <time.h>

int main () {
	//Cria a variavel de tempo e a struct de informacoes
	time_t segundos;
	struct tm *info;
	
	/*
	 * Posições da struct tm:
     * tm_sec   - segundos, de 0 a 59
     * tm_min   - minutos, de 0 a 59
     * tm_hour  - horas, de 0 a 23
     * tm_mday  - dia do mês, de 1 a 31
     * tm_mon   - mês, de 0 a 11
     * tm_year  - Ano, desde 1900
     * tm_wday  - dia da semana, de 0 a 6
     * tm_yday  - dia do ano, de 0 a 365
     * tm_isdst - horário de verão (0 = não)
	 */
	
	//Atualiza o tempo atual
	time( &segundos );
	
	//Atualiza a hora local
	info = localtime( &segundos );
	
	//Mostrando a data e hora corrente
	printf("Data e hora corrente: %s\n", asctime(info));
	
	//Mostrando todos os atributos da estrutura
	printf("Horas:             %d \n", info->tm_hour);
	printf("Minutos:           %d \n", info->tm_min);
	printf("Segundos:          %d \n", info->tm_sec);
	printf("Horario de Verao:  %d \n", info->tm_isdst);
	printf("Dia do Mes:        %d \n", info->tm_mday);
	printf("Dia da Semana:     %d \n", info->tm_wday + 1);
	printf("Dia do Ano:        %d \n", info->tm_yday);
	printf("Mes:               %d \n", info->tm_mon + 1);
	printf("Ano:               %d \n", info->tm_year + 1900);
	
	return 0;
}
