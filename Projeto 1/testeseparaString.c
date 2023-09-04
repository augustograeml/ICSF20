#include <string.h>
#include <stdio.h>

int main () {
   char str[80] = "Augusto,108064056";
   const char s[2] = ",";
   char *token;
   char* nome;
   char* rg;

   /* get the first token */
   token = strtok(str, s);
    nome = token;
   /* walk through other tokens */
   while( token != NULL ) {
      rg = token;

      token = strtok(NULL, s);
   }

   printf("%s\t %s",nome, rg);

   return(0);
}
