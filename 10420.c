#include <iostream>
#include <string>
using namespace std;
int main(void) {
    short n;
    string name;
    
    scanf("%hd", &n);
    while(n--) {
        scanf("%s%*[^\n]", name);
        printf("%s", name);
    }
    
    return 0;
}
