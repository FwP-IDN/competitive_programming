#include<bits/stdc++.h>
using namespace std;

#define maxn 1000

int n, m, tes, cas;
bool bisa;
int col[maxn + 5];
int conn[maxn + 5][maxn + 5];

void dfs(int nod, int cc) {
	col[nod] = cc;
	for(int ke = 1; ke <= n; ke++) {
		if(!bisa) {
			return;
		}
		if(ke == nod) {
			continue;
		}
		if(conn[nod][ke] < cas) {
			// ada rev-edgenya
			if(col[ke] == cc) {
				bisa = false;
				return;
			}
			else if(col[ke] == 0) {
				dfs(ke, -cc);
			}
		}
	}
}


int main() {
	scanf("%d", &tes);
	for(cas = 1; cas <= tes; cas++) {
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; i++) {
			col[i] = 0;
		}
		while(m--) {
			int a, b;
			scanf("%d %d", &a, &b);
			conn[a][b] = cas;
			conn[b][a] = cas;
		}
		bisa = true;
		for(int i = 1; i <= n; i++) {
			if(col[i] == 0) {
				dfs(i, 1);
			}
		}
		if(bisa) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}