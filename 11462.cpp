//////////////////////////////////
// Algoritimo Avancado
// Lista 2 basico
// P4 - 11462 - Age Sort
//
// Autor: Stenio Elson
// stenio.araujo@ccc.ufcg.edu.br
//////////////////////////////////
#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

int main(void){
    
    long int x, i;
    map<int,int> idades;
    
    do {
       scanf("%ld", &x);
       if (x == 0) break;
       while (x--) {
             scanf("%ld", &i);
             if(idades.count(i) == 0) {
                 idades[i] = 0;
             }
             idades[i]++;
       }
       
       map<int,int>::iterator it = idades.begin();
       printf("%ld", it -> first);
       it -> second--;
       
       while (it != idades.end()) {
           while(it -> second--) {
               printf(" %ld", it -> first);
           }
           ++it;
       }
       
       idades.clear();
       printf("\n");
    } while(1);
    
    return 0;
}
