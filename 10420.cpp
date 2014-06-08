#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void) {
    short n;
    string pais, lixo;
    map <string, int> paises;
    
    cin >> n;
    while (n--) {
        cin >> pais;
        getline(cin, lixo);
        
        if (paises.count(pais) == 0) {
            paises[pais] = 0;
        }
        paises[pais]++;
    }
        
    for(map<string, int>::iterator i = paises.begin(); i != paises.end(); ++i) {
        cout << i -> first << " " << i -> second << endl;
    }
    
    return 0;
}
