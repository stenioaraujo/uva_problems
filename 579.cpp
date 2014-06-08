#include <stdio.h>
float grau(float g) {
    if (g>=180)
       return 360-g;
    return g;
}
int main(void) {
    short h,m;
    float gh, gm;
    do {
        scanf("%hd:%hd", &h,&m);
        if(h == 0 && m == 0) break;
        
        gm = 6*m;
        gh = 30*h + 0.5*m;
        
        printf("%0.3f\n", grau(gm-gh<0?-1*(gm-gh):-1*(gh-gm)));
    } while(1);
    return 0;
}

