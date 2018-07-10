#include<bits/stdc++.h>
using namespace std;



struct StructDP{
	int N, M;
	static const int maxn = 1000;
	char ar[maxn + 5][maxn + 5];
	int h[maxn + 5][maxn + 5];
	int kiri[maxn + 5][maxn + 5];
	int kanan[maxn + 5][maxn + 5];
	int has = 0;
	
	void read_input() {
		scanf("%d %d", &N, &M);
		for(int i = 1; i <= N; i++) {
			scanf("%s", ar[i] + 1);
		}
	}

	void find_h() {
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				if(ar[i][j] == '.') {
					h[i][j] = h[i - 1][j] + 1;
				}
			}
		}
	}

	void left_hist() {
		for(int i = 1; i <= N; i++) {
			kiri[i][1] = 1;
			for(int j = 2; j <= M; j++) {
				if(h[i][j]) {
					int now = j;
					while(now > 1 && h[i][now - 1] >= h[i][j]) {
						now = kiri[i][now - 1];
					}
					kiri[i][j] = now;
				}
			}
		}
	}

	void right_hist() {
		for(int i = 1; i <= N; i++) {
			kanan[i][N] = N;
			for(int j = N - 1; j >= 1; j--) {
				if(h[i][j]) {
					int now = j;
					while(now < N && h[i][now + 1] >= h[i][j]) {
						now = kanan[i][now + 1];
					}
					kanan[i][j] = now;
				}
			}
		}
	}

	void solve() {
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				if(h[i][j]) {
					has = max(has, h[i][j] + kanan[i][j] - kiri[i][j] + 1);
				}
			}
		}
	}

	void print_ans() {
		printf("%d\n", has * 2 - 1);
	}

} DP;

int main() {
	DP.read_input();
	DP.find_h();
	DP.left_hist();
	DP.right_hist();
	DP.solve();
	DP.print_ans();
}