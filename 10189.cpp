#include <stdio.h>
int main(void) {
    char c[2];
    short m,n,i,j,k,f=1;
    short camp[104][104];
    short x[] = {1,1,0,-1,-1,-1,0,1};
    short y[] = {0,1,1,1,0,-1,-1,-1};
    
    do {
        scanf("%hd %hd", &m, &n);
        if (m == 0 && n == 0) break;
        
        for (i=0; i<=m+1; i++)
            for (j=0; j<=n+1; j++)
                camp[i][j] = 0;
        
        for (i = 1; i<=m; i++) {
            for (j = 1; j<=n; j++) {
                scanf("%1s", &c);
                if (c[0] == '*') {
                   camp[i][j] = -1;
                   for(k=0; k<8; k++)
                       if (camp[i+x[k]][j+y[k]] != -1)
                          camp[i+x[k]][j+y[k]] = camp[i+x[k]][j+y[k]] + 1;
                }
            }
        }
        
        if (f>1) printf("\n");
        printf("Field #%hd:\n", f++);
        for (i=1; i<=m; i++) {
            for (j=1; j<=n; j++) {
                if(camp[i][j]==-1)
                    printf("*");
                else
                    printf("%hd", camp[i][j]);
            }
            printf("\n");
        }
    } while(1);
    
    return 0;
}
