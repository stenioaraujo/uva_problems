//////////////////////////////////
// Algoritimo Avancado
// Lista 4 basico
// 729 - The Hamming Distance Problem
//
// Autor: Stenio Elson
// stenio.araujo@ccc.ufcg.edu.br
//////////////////////////////////

#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void) {
    char uns[100];
    int sets, N, H;
    
    scanf("%d", &sets);
	for (int i = 0; i < sets; i++) {
		scanf("%d %d", &N, &H);
		fill(uns, uns + (N-H), '0');
		fill(uns+(N-H), uns+N, '1');
        uns[N] = '\0';
		
		if (i > 0) printf("\n");
		
		do {
			printf("%s\n", uns);
		} while(next_permutation(uns, uns+N));
	}
	
	return 0;
}


/* TENTANDO usar backtracking, a resposta da time limit exceded
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace std;

typedef unsigned int ui;

string digits, solucao;
set<string> solucoes;

ui sets, tam, uns, gerados = 0;

void back(ui pos) {
	if (solucao.size() == tam) {
		if (solucoes.count(solucao) == 0) {
			solucoes.insert(solucao);
			cout << solucao << endl;
		}
		return;
	}
	for (ui i = 0; i < tam - pos; i++) {
		solucao.push_back(digits[i]); digits.erase(digits.begin() + i);
		back(pos+1);
		digits.insert(digits.begin() + i, solucao[solucao.size()-1]); solucao.erase(solucao.end() - 1);
	}
}

int main(void) {

	scanf("%u", &sets);
	while(sets--) {
		scanf("%u %u", &tam, &uns);
		digits.clear();
		
		for (ui i = 0; i < tam-uns; i++) digits.push_back('0');
		for (ui i = 0; i < uns; i++) digits.push_back('1');
		
		solucoes.clear();
		back(0);
		
		if (sets > 0) printf("\n");
	}

	return 0;
}
*/