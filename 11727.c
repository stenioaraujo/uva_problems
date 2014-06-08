#include <stdio.h>
int main(void) {
    short t, i, a, b, c;
    
    scanf("%hd", &t);
    
    for(i = 1; i <= t; i++) {
        scanf("%hd %hd %hd", &a, &b, &c);
        
        if(a>b && a<c || a<b && a>c) printf("Case %hd: %hd\n", i, a);
        else if(b>a && b<c || b<a && b>c) printf("Case %hd: %hd\n", i, b);
        else printf("Case %hd: %hd\n", i, c);
    }
    
}
