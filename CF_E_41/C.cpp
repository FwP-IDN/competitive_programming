#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair

#define minn(aa, bb, cc, dd, ee, ff) min(min(aa, min(bb, cc)), min(dd, min(ee, ff)))

typedef long long ll;

pair<int, int> minc[4];
char chessB[105][105];
int N;

int main() {
	cin >> N;
	for(int k = 0; k < 4; k++) {
		for(int i = 0; i < N; i++) {
			cin >> chessB[i];
		}
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(((i ^ j) & 1)) {
					if(chessB[i][j] == '0') {
						minc[k].f++;
					}
					else {
						minc[k].s++;
					}
				}
				else {
					if(chessB[i][j] == '0') {
						minc[k].s++;
					}
					else {
						minc[k].f++;
					}
				}
			}
		}
	}
	int A0 = minc[0].f;
	int A1 = minc[0].s;
	int B0 = minc[1].f;
	int B1 = minc[1].s;
	int C0 = minc[2].f;
	int C1 = minc[2].s;
	int D0 = minc[3].f;
	int D1 = minc[3].s;

	cout << minn(
		A0 + B0 + C1 + D1,
		A0 + B1 + C0 + D1,
		A0 + B1 + C1 + D0,
		A1 + B0 + C0 + D1,
		A1 + B0 + C1 + D0,
		A1 + B1 + C0 + D0
		) << "\n";
}