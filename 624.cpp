//////////////////////////////////
// Algoritimo Avancado
// Lista 4 basico
// 624 - CD
//
// Autor: Stenio Elson
// stenio.araujo@ccc.ufcg.edu.br
//////////////////////////////////

#include <stdio.h>
#include <vector>
using namespace std;

vector<int> tracks, resultado, temp;
int maior = 0, sum = 0, N, qntTracks, track;

bool aceita() {
    if (sum <= N and sum > maior || sum == maior and temp.size() > resultado.size()) {
		return true;
	}
	
	return false;
}

void back(int i, int k) {
    
    if ((int)temp.size() == k) {    	
        if (aceita()) {
            maior = sum;
            resultado.clear();
            for (int m = 0; m < k; m++) {
                resultado.push_back(temp[m]);
            }
        }
        
        return;
    }
    
    for (; i < (int)tracks.size(); i++) {
        temp.push_back(tracks[i]); sum += temp.back();
        back(i + 1, k);
        sum -= temp.back(); temp.pop_back();
    }
}

int main(void) {
    
    while(scanf(" %d", &N) != EOF) {
        scanf("%d", &qntTracks);
        for (int i = 0; i < qntTracks; i++) {
            scanf("%d", &track);
            tracks.push_back(track);
        }
        
        for (int i = 1; i <= qntTracks; i++) {
        	temp.clear();
            back(0, i);
        }
        
        for (int i = 0; i < (int)resultado.size(); i++) {
        	printf("%d ", resultado[i]);
        }
        printf("sum:%d\n", maior);
        
        sum = 0;
        maior = 0;
        tracks.clear();
    }
    
    return 0;
}