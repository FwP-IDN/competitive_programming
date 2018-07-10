#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

char ar[2500][2500];

int main(int argc, char** argv) {
	int A, B, C, D;
	scanf("%d %d %d %d", &A, &B, &C, &D);
	A--;
	D--;
	for(int i = 0; i < 25; i++) {
		for(int j = 0; j < 50; j++) {
			ar[i][j] = 'A';
		}
	}
	for(int i = 25; i < 50; i++) {
		for(int j = 0; j < 50; j++) {
			ar[i][j] = 'D';
		}
	}
	C += D;
	B += C;
	for(int num = 0; num < D; num++) {
		int x, y;
		x = (num / 25) * 2;
		y = (num % 25) * 2;
		ar[x][y] = 'D';
	}
	for(int num = D; num < C; num++) {
		int x, y;
		x = (num / 25) * 2;
		y = (num % 25) * 2;
		ar[x][y] = 'C';
	}
	for(int num = C; num < B; num++) {
		int x, y;
		x = (num / 25) * 2;
		y = (num % 25) * 2;
		ar[x][y] = 'B';
	}
	for(int num = 0; num < A; num++) {
		int x, y;
		x = (num / 25) * 2; x += 26;
		y = (num % 25) * 2;
		ar[x][y] = 'A';
	}
	cout << "50 50\n";
	for(int i = 0; i < 50; i++) {
		for(int j = 0; j < 50; j++) {
			cout << ar[i][j];
		} cout << "\n";
	}
}