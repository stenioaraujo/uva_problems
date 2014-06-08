#include <stdio.h>
int main(void) {
    short k, n, m, x, y;
    
    do {
       scanf("%hd", &k);
       if (k == 0) break;
       
       scanf("%hd %hd", &n, &m);
       
       while (k--) {
             scanf("%hd %hd", &x, &y);
             if(x<n && y>m) printf("NO\n");
             else if(x<n && y<m) printf("SO\n");
             else if(x>n && y<m) printf("SE\n");
             else if(x>n && y>m) printf("NE\n");
             else printf("divisa\n");
       }
    } while (1);
    
    return 0;
}
