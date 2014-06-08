//////////////////////////////////
// Algoritimo Avancado
// Lista 4 basico
// 524 - Prime Ring Problem
//
// Autor: Stenio Elson
// stenio.araujo@ccc.ufcg.edu.br
//////////////////////////////////
#include <stdio.h>
#include <vector>
using namespace std;

typedef unsigned int ui;

vector<int> resp, vec;
ui tam;

int prime(int i) {
    for (int j = 2; j <= i/2; j++) {
		if (i % j == 0) return 0;
	}
	
	return 1;
}

int valido(int i) {
	for (ui j = 0; j < resp.size(); j++) {
		if (i == resp[j]) {
			return 0;
		}
	}
	
	return prime(i + resp.back());
}

void perm() {
	if (resp.size() == tam && prime(resp.back() + resp.front())) {
		for (ui j = 0; j < resp.size(); j++) {
			if (j > 0) printf(" ");
			printf("%d", resp[j]);
		} printf("\n");
	}
	
	for (ui i = 2; i <= tam; i++) {
		if (valido(i)) {
			resp.push_back(i);
			perm();
			resp.pop_back();
		}
	}
}

int main(void) {
	resp.push_back(1);
	
	int caso = 1;
	while (scanf("%d", &tam) != EOF) {
		
		if (caso > 1) printf ("\n");
		printf("Case %d:\n", caso);
		
		perm(); caso++;
	}
	
	return 0;
}