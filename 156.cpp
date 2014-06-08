#include <iostream>
#include <string>
#include <map>
#include <ctype.h>

using namespace std;

string lower(string palavra) {
       for (int i = 0; i < palavra.size(); i++) {
           palavra[i] = tolower(palavra[i]);
       }
       
       return palavra;
}

map<char, int> letras(string palavra) {
       map<char, int> letras;
       for (int i = 0; i < palavra.size(); i++) {
           if (letras.count(tolower(palavra[i])) == 0)
              letras[tolower(palavra[i])] = 0;
           
           letras[tolower(palavra[i])]++;
       }
       
       return letras;
}

int main(void) {
    map<string, map<char, int> > palavras;
    string palavra;
    do{
       cin >> palavra;
       if (palavra.compare("#") == 0) break;
       
       palavras[palavra] = letras(palavra);
       
    } while(1);
    
    for (map<string, map<char, int> >::iterator it = palavras.begin(); it != palavras.end(); ++it){
        short n = 1;
        for (map<string, map<char, int> >::iterator it2 = palavras.begin(); it2 != palavras.end(); ++it2){
            if (lower(it -> first) != lower(it2 -> first))
               if (it -> second == it2 -> second)
                  n = 0;
        }
        if (n)
           cout << it -> first << endl;
    }
    
    return 0;
}
