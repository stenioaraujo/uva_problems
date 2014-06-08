//////////////////////////////////
// Algoritimo Avancado
// Lista 2 basico
// P3 - 612 - DNA Sorting
//
// Autor: Stenio Elson
// stenio.araujo@ccc.ufcg.edu.br
//////////////////////////////////
#include <map>
#include <queue>
#include <iostream>
#include <string.h>
using namespace std;

int main(void) {
    int qnt;
    short M, n, m, size;
    unsigned short i, j;
    string dna;
    char letra;
    map <int, queue<string> > ordem;
    
    cin >> M;
    while (M--) {
        cin >> n >> m;
        while (m--) {
            cin >> dna;
            qnt = 0;
            for (i = 0; i < dna.size(); i++)
                for (j = i+1; j < dna.size(); j++)
                    if (dna[i] > dna[j])
                        qnt++;
            
            if (ordem.count(qnt) == 0) {
                queue<string> dnas;
                ordem[qnt] = dnas;
            }
            ordem[qnt].push(dna);
        
        }
		
	    for (map<int, queue<string> >::iterator it = ordem.begin(); it != ordem.end(); ++it) {
	    	size = it -> second.size();
	        for (i = 0; i < size; i++) {
	            cout << it -> second.front() << endl;
	            it -> second.pop();
	        }
	    }
	    
	    if (M > 0) {
	    	cout << endl;
	    }
	    
	    ordem.clear();
    }
    return 0;
}
