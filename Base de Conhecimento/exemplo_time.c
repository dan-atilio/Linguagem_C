#include <stdio.h>
#include <time.h>

int main () {
   time_t seconds;

   seconds = time(NULL);
   printf("Horas desde 1 de Janeiro de 1970 = %ld\n", seconds/3600);
   printf("Dias desde 1 de Janeiro de 1970 = %ld\n", (seconds/3600) / 24);
   printf("Anos desde 1 de Janeiro de 1970 = %ld\n", ((seconds/3600) / 24) / 365);
  
   return(0);
}
