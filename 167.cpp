//////////////////////////////////
// Algoritimo Avancado
// Lista 4 basico
// 167 - The Sultan's Successors
//
// Autor: Stenio Elson
// stenio.araujo@ccc.ufcg.edu.br
//////////////////////////////////
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int> > chessVal(8, vector<int>(8));
vector<bool> col(8), rDiago(8), lDiago(8);
vector<vector<bool> > chess(8, vector<bool>(8));
int sets, cel, sum = 0, maior = 0;

void backtrack(int i);
void coloca(int i, int j);
void tira(int i, int j);
bool podeColocar(int i, int j);


void backtrack(int i) {
    if (i == 8) {
        if (sum > maior) maior = sum;
        
        return;
    }
    
    for (int j = 0; j < 8; j++) {
        if (podeColocar(i, j)) {
            coloca(i, j);
            backtrack(i+1);
            tira(i, j);
        }
    }
}

void coloca(int i, int j) {
    chess[i][j] = true;
    col[j] = true;
    rDiago[i+j] = true;
    lDiago[7+i-j] = true;
    sum += chessVal[i][j];
}

void tira(int i, int j) {
    chess[i][j] = false;
    col[j] = false;
    rDiago[i+j] = false;
    lDiago[7+i-j] = false;
    sum -= chessVal[i][j];
}

bool podeColocar(int i, int j) {
    if (col[j] || rDiago[i+j] || lDiago[7+i-j]) {
        return false;
    }
    return true;
}

int main(void) {
    
    scanf("%d", &sets);
    while(sets--) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                scanf("%d", &cel);
                chessVal[i][j] = cel;
            }
        }
        
        sum = 0;
        maior = 0;
        backtrack(0);
        printf("%5d\n", maior);
    }
    
    return 0;
}