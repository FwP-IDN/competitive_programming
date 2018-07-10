#include <bits/stdc++.h>
using namespace std;

int cntA[256], cntB[256], cntC[256];

int main() {
	int tam;
	string A, B ,C;
	cin >> tam;
	cin >> A >> B >> C;
	int len = (int)A.length();
	int maxiA, maxiB, maxiC;
	maxiA = maxiB = maxiC = 0;
	for(int i = 0; i < len; i++) {
		cntA[A[i]]++; maxiA = max(maxiA, cntA[A[i]]);
		cntB[B[i]]++; maxiB = max(maxiB, cntB[B[i]]);
		cntC[C[i]]++; maxiC = max(maxiC, cntC[C[i]]);
	}
	if(tam == 1) {
		maxiA = maxiA == len ? maxiA - 1 : maxiA + 1;
		maxiB = maxiB == len ? maxiB - 1 : maxiB + 1;
		maxiC = maxiC == len ? maxiC - 1 : maxiC + 1;
	}
	else {
		maxiA = min(len, maxiA + tam);
		maxiB = min(len, maxiB + tam);
		maxiC = min(len, maxiC + tam);
	}
	if(maxiA > max(maxiB, maxiC)) {
		cout << "Kuro\n";
	}
	else if(maxiB > max(maxiA, maxiC)) {
		cout << "Shiro\n";
	}
	else if(maxiC > max(maxiA, maxiB)) {
		cout << "Katie\n";
	}
	else {
		cout << "Draw\n";
	}
}