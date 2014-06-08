#include <stdio.h>

int main(void) {
    
    short linhas;
    long int primeiro, segundo;
    
    scanf("%hd", &linhas);
    
    while (linhas--) {
          scanf("%ld", &primeiro);
          scanf("%ld", &segundo);
          
          printf((primeiro<segundo?"<":(primeiro==segundo?"=":">")));
          printf("\n");

    }
    
    return 0;
}
