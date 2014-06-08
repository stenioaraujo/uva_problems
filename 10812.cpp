#include <stdio.h>
int main(void){
    int n, s, d, a, b;
    
    scanf("%d", &n);
    while(n--) {
               scanf("%d %d", &s, &d);
               
               b = (s - d) / 2;
               a = s - b;
               
               if (s<d || a+b!=s || a-b!=d) {
                        printf("impossible\n");
                        continue;
               }
               
               printf("%d %d\n", a, b);
    }
    
    return 0;
}
