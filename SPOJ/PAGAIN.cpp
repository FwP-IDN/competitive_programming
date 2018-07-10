#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> tes;
	while(tes--) {
		cin >> N;
		if(!(N & 1)) {
			N--;
		}
		while(!isPrime(N)) {
			N -= 2;
		}
	}
}