#include<bits/stdc++.h>
using namespace std;

int gcd, gap, rem, N;
vector<int> minNum;
priority_queue<int, vector<int> , greater<int> > pq;
int ar[5000];

int GCD(int a, int b) {
	return a == 0 ? b : GCD(b % a, a);
}

void precomp() {
	for(int i = 0; i < N; i++) {
		gcd = GCD(gcd, ar[i]);
	}
	gap = ar[0] / gcd;
	rem = gap;
	minNum.resize(gap, 0xfffffff);
	pq.push(0);
	minNum[0] = 0;
	int atas, newVal, nod;
	while(!pq.empty()) {
		atas = pq.top(); pq.pop();
		if(minNum[atas % ar[0]] != atas) {
			continue;
		}
		for(int i = 1; i < N; i++) {
			newVal = atas + ar[i];
			nod = newVal % ar[0];
			if(minNum[nod] > newVal) {
				minNum[nod] = newVal;
				pq.push(newVal);
			}
		}
	}
}

char yes[] = "TAK", no[] = "NIE";
char* solve(int num) {
	// printf("%d %d\n", num, minNum[(num / gcd) % gap]);
	if((num % gcd) || num < minNum[(num / gcd) % gap]) {
		return no;
	}
	else {
		return yes;
	}
}

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d", ar + i);
	}
	sort(ar, ar + N);
	precomp();
	int Q;
	scanf("%d", &Q);
	int num;
	while(Q--) {
		scanf("%d", &num);
		printf("%s\n", solve(num));
	}
}