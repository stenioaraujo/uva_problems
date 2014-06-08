//////////////////////////////////
// Algoritimo Avancado
// Lista 3 basico
// P2 - 441 - Lotto
//
// Autor: Stenio Elson
// stenio.araujo@ccc.ufcg.edu.br
//////////////////////////////////
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> possib, numeros;
void combinations(int tam, int ini) {
    if (tam > 0) {
		for (int i = ini; i <= (int)numeros.size() - tam; i++) {
			possib.push_back(numeros[i]);
			combinations(tam-1, i+1);
			possib.pop_back();
		}
	} else {
		for (int i = 0; i < (int)possib.size(); i++) {
			if (i > 0) printf(" ");
			printf("%d", possib[i]);
		}
		printf("\n");
	}
}

int casos = 0;
int main(void) {
    int n, num;
    
    while (1) {
        scanf("%d", &n);
        if (n==0) break;
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &num);
            numeros.push_back(num);
        }
        
        if (casos++) printf("\n");
        
        combinations(6, 0);
        numeros.clear();
        possib.clear();
    }
    
    return 0;
}