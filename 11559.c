#include <stdio.h>
int main(void) {
    short int N, H, W, p, a, trocou, i;
    long int B, menor, temp;
    
    while(scanf("%hd %ld %hd %hd", &N, &B, &H, &W) == 4){
    	menor = 5000000;
    	trocou = 0;
    	
	    while(H--) {
	        scanf("%hd", &p);
	        for(i = 0; i < W; i++) {
	            scanf("%hd", &a);
	            if (a < N) continue;
	            temp = p*N;
	            if (temp > B) continue;
	            if (temp < menor) {
	                menor = temp;
	                trocou = 1;
	            }
	        }
	    }
	    
	    if (trocou) printf("%ld\n", menor);
	    else printf("stay home\n");
    }
    return 0;
}
