//////////////////////////////////
// Algoritimo Avancado
// Lista 2 basico
// P2 - 146 - ID Codes
//
// Autor: Stenio Elson
// stenio.araujo@ccc.ufcg.edu.br
//////////////////////////////////
#include <stdio.h>
#include <algorithm>
using namespace std;
int i, t;
char s[60], c;

int isDes(char s[], int limit) {
    for (i = 1; i < limit; i++) {
        if (s[i] > s[i-1]) return 0;
    }
    return 1;
}

int main(void) {
    
    while(1) {
        t = 0;
        while (scanf("%c", &c), c != '\n') {
              if (c == '#') return 0;
              s[t++] = c;
        }
        if(isDes(s, t)) {
            printf("No Successor\n");
            continue;
        }
        next_permutation(s, s+t);
        s[t] = '\0';
        printf("%s\n", s);
    }
    
    return 0;
}
