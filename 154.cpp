//////////////////////////////////
// Algoritimo Avancado
// Lista 3 basico
// P2 - 154 - Recycling
//
// Autor: Stenio Elson
// stenio.araujo@ccc.ufcg.edu.br
//////////////////////////////////
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#define BLOCK 19
using namespace std;

int main(void) {
    map<char,char> blocks[110];
    int i = 0, soma, somaMin, min;
    string block;
    
    while (1) {
        getline(cin, block);
        if (block[0] == '#') break;
    	if (block[0] != 'e') {
    		for (int j = 0; j < BLOCK; j += 4) {
    			blocks[i][block[j+2]] = block[j];
    		}
    		i++;
    		continue;
    	}
    	if (i==0) continue;
		min = 0;
		somaMin = 1000;
		for (int j = 0; j < i; j++) {
			soma = 0;
			for (int k = 0; k < i; k++)
				for (map<char, char>::iterator it = blocks[j].begin(); it != blocks[j].end(); it++)
					if (j != k && blocks[j][it->first] != blocks[k][it->first])
						soma++;
			if (soma < somaMin) {
				min = j;
				somaMin = soma;
			}
		}
		printf("%d\n", min + 1);
		i = 0;
    }
    
    return 0;
}