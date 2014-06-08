//////////////////////////////////
// Algoritimo Avancado
// Lista 3 basico
// P1 - 105 - The Skyline Problem
//
// Autor: Stenio Elson
// stenio.araujo@ccc.ufcg.edu.br
//////////////////////////////////
#include <stdio.h>
#include <vector>
#define BASE 10000
#define MAX 10010
using namespace std;

int main(void) {
    vector< vector <int> > plano (MAX, vector<int>(MAX)) ;
    int saida[MAX] = {0};
    int xi, xf, h, x, y, i, anterior;
    
    // Desenha os predios solidos
    while (scanf("%d %d %d", &xi, &h, &xf) != EOF) {
        if (xi==xf) continue;
        for (y = BASE; y >= BASE - h; y--) {
			if (plano[y][xi] == 0 || plano[y][xi] > h) {
	        	plano[y][xi] = h;
	    	}
			if (plano[y][xf] == 0 || plano[y][xf] > h) {
	        	plano[y][xf] = h;
	    	}
        }
        for (x = xi; x <= xf; x++) {
        	if (plano[BASE-h][x] == 0 || plano[BASE-h][x] > h) {
	        	plano[BASE-h][x] = h;
	    	}
        }
    }
    
    y = BASE;
    i = 0;
    anterior = 0;
    for (x = 0; x < MAX; x++) {
    	if (plano[y][x] != 0) {
    		if(y > 0 && anterior < plano[y-1][x]){
    			while (y > 0 && plano[y-1][x] > anterior) {
    				y--;
    			}
    		} else if (anterior > plano[y][x+1]) {
    			while (y < BASE && (plano[y][x] == anterior || x < MAX-1 && plano[y][x+1] == 0)) {
    				y++;
    			}
    		} else {
    			continue;
    		}
			saida[i++] = x;
			saida[i++] = BASE - y;
    	}
    	anterior = plano[y][x];
    }
    
    for (int j = 0; j < i; j++){
    	if (j > 0) printf(" ");
    	printf("%d", saida[j]);
    }
    printf("\n");
    
    return 0;
}
