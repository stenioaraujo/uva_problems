#include <stdio.h>
int main(void) {
    short T, N, velo, maximo, caso = 1;
    
    scanf("%hd", &T);
    while(T--){
    		   maximo = 1;
               scanf("%hd", &N);
               while(N--){
                          scanf("%hd", &velo);
                          if (velo > maximo) maximo = velo;
               }
               printf("Case %hd: %hd\n", caso++, maximo);
    }
    
    return 0;
}
