//////////////////////////////////
// Algoritimo Avancado
// Lista 2 basico
// P6 - 673 - Parentheses Balance
//
// Autor: Stenio Elson
// stenio.araujo@ccc.ufcg.edu.br
//////////////////////////////////
#include <stdio.h>
char p[134];
int size = 0;

void insert(char c) {
     p[size++] = c;
}

char pop() {
     if (size == 0) return 'e';
     return p[--size];
}

int main(void) {
    int v, correto = 1;
    char c, t;
    
    scanf("%d", &v);
    scanf("%*c");
    while(v--){
        do {
           scanf("%c", &c);
           if (c == '\n') break;
           if (c == ')' || c == ']') {
              t = pop();
              if (t == 'e' || t=='[' && c==')' || t=='(' && c==']') {
                 correto = 0;
              }
           } else {
             insert(c);
           }
        } while(1);
        
        if (size) correto = 0;
        
        if (correto) printf("Yes\n");
        else printf("No\n");
        
        correto = 1;        
        size = 0;
    }
    
    return 0;
}
