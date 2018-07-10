#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

struct Adhoc {
	char grid[101][101];
	int drop[100], dest[100];
	int cas = 0;
	int N, mini[100], maxi[100], row;
	void read() {
		scanf("%d", &N);
		for(int i = 0; i < N; i++) {
			scanf("%d", drop + i);
		}
	}

	void solve_all() {
		cas++;
		row = 0;
		int fly = 0;
		for(int i = 0; i < N; i++) {
			mini[i] = fly;
			for(int j = 0; j < drop[i]; j++) {
				dest[fly] = i;
				++fly;
			}
			maxi[i] = fly - 1;
		}
		for(int i = 0; i < N; i++) {
			if(drop[i]) {
				for(int j = mini[i], k = 0; j < i; ++j) {
					if(k >= row) {
						memset(grid[row], '.', N * sizeof(char));
						grid[row][N] = '\0';
						row++;
					}
					grid[k][j] = '\\';
					++k;
				}
				for(int j = maxi[i], k = 0; j > i; --j) {
					if(k >= row) {
						memset(grid[row], '.', N * sizeof(char));
						grid[row][N] = '\0';
						row++;
					}
					grid[k][j] = '/';
					++k;
				}
			}
		}
		memset(grid[row], '.', N * sizeof(char));
		grid[row++][N] = '\0';
	} 

	void print() {
		if(drop[0] == 0 || drop[N - 1] == 0) {
			printf("Case #%d: %s\n", cas, "IMPOSSIBLE");
			return;
		}
		printf("Case #%d: %d\n", cas, row);
		for(int i = 0; i < row; i++) {
			printf("%s\n", grid[i]);
		}
	}
} A;

int main() {
	// ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int tes;
	cin >> tes;
	while(tes--) {
		A.read();
		A.solve_all();
		A.print();
	}
}