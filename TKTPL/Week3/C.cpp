#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
const int MAXQ = 10000;

struct tikus {
	int x1;
	int x2;
	int y1;
	int y2;	
};

int concom, n, m, q;
int cnt[MAXN + 5][MAXN + 5];
tikus quer[MAXQ + 5];
int ans[MAXQ + 5];
int thenum[MAXN + 5][MAXN + 5];
int par[MAXN * MAXN + 5];
int xx[] = {1, 0, -1, 0};
int yy[] = {0, 1, 0, -1};

int fp(int nod) {
	if(nod == par[nod]) {
		return nod;
	}
	return par[nod] = fp(par[nod]);
}

int gabung(int a, int b) {
	if(a == 0 || b == 0) {
		return 0;
	}
	int aa = fp(a);
	int bb = fp(b);
	if(aa == bb) {
		return 0;
	}
	par[bb] = aa;
	return 1;
}

void initial_union() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(cnt[i][j]) {
				continue;
			}
			for(int k = 0; k <= 3; k++) {
				int ii = i + xx[k];
				int jj = j + yy[k];
				if(cnt[ii][jj]) {
					continue;
				}
				gabung(thenum[i][j], thenum[ii][jj]);
			}
		}
	}
}

void initial_count() {
	initial_union();
	concom = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(cnt[i][j] == 0 && fp(thenum[i][j]) == thenum[i][j]) {
				concom++;
			}
		}
	}
}

void solve(int Q) {
	tikus &item = quer[Q];
	for(int i = item.x1; i <= item.x2; i++) {
		for(int j = item.y1; j <= item.y2; j++) {
			cnt[i][j]--;
			if(!cnt[i][j]) {
				concom++;
			}
			else {
				continue;
			}
			for(int k = 0; k <= 3; k++) {
				int ii = i + xx[k];
				int jj = j + yy[k];
				if(cnt[ii][jj]) {
					continue;
				}
				concom -= gabung(thenum[i][j], thenum[ii][jj]);
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 0; i <= n + 1; i++) {
		for(int j = 0; j <= m + 1; j++) {
			cnt[i][j] = -1;
		}
	} 
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			thenum[i][j] = (i - 1) * m + j;
			par[thenum[i][j]] = thenum[i][j];
			cnt[i][j] = 0;
		}
	}
	for(int k = 1; k <= q; k++) {
		scanf("%d %d %d %d", &quer[k].x1, &quer[k].y1, &quer[k].x2, &quer[k].y2);
		for(int i = quer[k].x1; i <= quer[k].x2; i++) {
			for(int j = quer[k].y1; j <= quer[k].y2; j++) {
				cnt[i][j]++;
			}
		}
	}
	initial_count();
	for(int k = q; k >= 1; k--) {
		ans[k] = concom;
		solve(k);
	}
	for(int k = 1; k <= q; k++) {
		printf("%d\n", ans[k]);
	}
}