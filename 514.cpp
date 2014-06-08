//////////////////////////////////
// Algoritimo Avancado
// Lista 2 basico
// P5 - 514 - Rails
//
// Autor: Stenio Elson
// stenio.araujo@ccc.ufcg.edu.br
//////////////////////////////////
#include <stdio.h>
#include <stack>
using namespace std;

int main(void) {
    stack<int> p1;
    stack<int> p2;
    int n, i, temp;    
    
    do {
        if(scanf("%d", &n),n==0) break;
        while(1) {
            temp = n;
            while (1) {
                  if(p1.size())
                      p1.pop();
                  else if(p2.size())
                      p2.pop();
                  else
                      break;
            }
            while(temp--) {
                scanf("%d", &i);
                if(p1.push(i),i==0) break;
            }
            temp = n;
            if (p1.top() == 0){
                printf("\n");
                break;
            }
            while (p1.size()) {
                while(p1.size() && (p2.empty() || p2.top() != temp)) {
                    p2.push(p1.top());
                    p1.pop();
                }
                while(p2.size() && p2.top() == temp) {
                    p2.pop();
                    temp--;
                }
            }
            if (p1.empty() && p2.empty()) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    } while(1);
    
    return 0;
}
