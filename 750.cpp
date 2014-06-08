//////////////////////////////////
// Algoritimo Avancado
// Lista 4 basico
// 750 - 8 Queens Chess Problem
//
// Autor: Stenio Elson
// stenio.araujo@ccc.ufcg.edu.br
//////////////////////////////////
#include <stdio.h>
#include <vector>
using namespace std;

typedef unsigned u;

vector<int> solucao;
vector<int> col(20), upDiagonal(20), downDiagonal(20);
int linhaDefinida, colunaDefinida, sets, solucoes;

void coloca(int linha, int coluna);
void tira(int linha, int coluna);
int valido(int linha, int coluna);

void back(int linha) {
    if (linha == 9 && solucao[linhaDefinida-1] == colunaDefinida) {
        printf("%2d%7d", ++solucoes, solucao[0]);
        for (u i = 1; i < solucao.size(); i++) {
            printf(" %d", solucao[i]);
        }printf ("\n");
    }
    
    for (int coluna = 1; coluna <= 8; coluna++) {
        if (valido(linha, coluna)) {
            coloca(linha, coluna);
            back(linha+1);
            tira(linha, coluna);
        }
    }
}

int valido(int linha, int coluna) {
    if (col[coluna] || upDiagonal[linha+coluna] || downDiagonal[7+linha-coluna]) {
		return false;
	}
	return true;
}

void coloca(int linha, int coluna) {
    col[coluna] = 1;
    upDiagonal[linha+coluna] = 1;
    downDiagonal[7+linha - coluna] = 1;
    solucao.push_back(coluna);
}

void tira(int linha, int coluna) {
    col[coluna] = 0;
    upDiagonal[linha+coluna] = 0;
    downDiagonal[7+linha - coluna] = 0;
    solucao.pop_back();
}

int main(void) {
	
	scanf("%d", &sets);
	while(sets--) {
		scanf("%d %d", &colunaDefinida, &linhaDefinida);
		
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n");
		printf("\n");
		
		solucoes = 0;
		back(1);
		
		if (sets > 0) printf("\n");
	}
	
    return 0;
}