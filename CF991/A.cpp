#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int A, B, C, N;
	cin >> A >> B >> C >> N;
	int D = N - A - B + C;
	if(D <= 0 || C > min(A, B) || N < max(A, B)) {
		D = -1;
	}
	cout << D << "\n";
}