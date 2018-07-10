#include <bits/stdc++.h>
using namespace std;

int ar[100];
int N;

int main(int argc, char** argv) {
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> ar[i];
	}
	sort(ar, ar + N);
	int skor = 0;
	int minSkor = (9 * N + 1) / 2;
	for(int i = 0; i < N; i++) {
		skor += ar[i];
		ar[i] = 5 - ar[i];
	}
	int has = 0;
	for(int i = 0; i < N; i++) {
		if(skor >= minSkor) {
			break;
		}
		skor += ar[i];
		++has;
	}
	cout << has << "\n";
}