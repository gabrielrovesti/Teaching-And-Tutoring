#include <stdio.h>

/*
    Determinare se un anno è bisestile. 
 */
int main() {
   int x = 1200;
   if((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0)) {
       printf("L'anno %d è bisestile\n", x);
   } else {
       printf("L'anno %d non è bisestile\n", x);
   }
   return 0;
}
