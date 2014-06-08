//////////////////////////////////
// Algoritimo Avancado
// Lista 4 basico
// 10344 - 23 out of 5
//
// Autor: Stenio Elson
// stenio.araujo@ccc.ufcg.edu.br
//////////////////////////////////

#include <stdio.h>
#include <vector>
using namespace std;
typedef long long int lli;

char ops[] = {'+', '-', '*'};
int temSolucao;
vector<char> os;
vector<lli> num;
vector<lli> tentativa;

lli o(lli num1, char op, lli num2) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
    }
}

void back() {
    if (temSolucao) {
        return;
    }
    if (os.size() == 4) {
        if(o(o(o(o(num[0], os[0], num[1]), os[1], num[2]), os[2], num[3]), os[3], num[4]) == 23) {
            printf("Possible\n");
            temSolucao = 1;
        }
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (temSolucao == 0) {
            os.push_back(ops[i]);
            back();
            os.pop_back();
        } else {
            break;
        }
    }
}

vector<int> solucao;
vector<int> nums;
unsigned int tam;

void back2(unsigned int pos) {
    if (temSolucao) return;
	if (num.size() == tam) {
		back();
		return;
	}
	for (unsigned int j = 0; j < tam - pos; j++) {
		if (temSolucao == 0) {
            num.push_back(nums[j]); nums.erase(nums.begin() + j);
            back2(pos+1);
            nums.insert(nums.begin()+j, num.back()); num.pop_back();
		} else {
			break;
		}
	}
}

int main(void) {
    temSolucao = 0;
    int soma, val;
    while (1) {
    	soma = 0;
	    nums.clear();
	    for (int i = 0; i < 5; i++) {
	    	scanf("%d", &val);
	        nums.push_back(val);
	        soma += val;
	    }
    	if (soma == 0) break;
    	os.clear();
    	temSolucao = 0;
        tam = nums.size();
    	back2(0);
    	if (temSolucao == 0) printf("Impossible\n");
    }
    return 0;
}
