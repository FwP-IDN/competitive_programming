#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define maxn 100000
#define pii pair<int, int>
#define p3i pair<pii, int>
#define mp make_pair
#define pb push_back
#define f first
#define s second

struct tikus {
	int aw;
	int ak;
	int baw;
	int id;
};

tikus masuk(int a, int b, int c, int d) {
	tikus ret;
	ret.aw = a;
	ret.ak = b;
	ret.baw = c;
	ret.id = d;
	return ret;
}

bool tikusComp(tikus a, tikus b) {
	if(a.aw < b.aw)
		return true;
	if(a.aw > b.aw)
		return false;
	if(a.ak < b.ak)
		return true;
	if(a.ak > b.ak)
		return false;
	if(a.baw < b.baw)
		return true;
	return false;
}

int N, M, K;
int val[maxn + 5];
int ar[55][55];
vector<tikus> queryset[55];
ll has = 0;
priority_queue<p3i, vector<p3i>, greater<p3i> > pq;
int applestate[55];

void queryProc(int idx) {
	vector<tikus> QQ; QQ.assign(queryset[idx].begin(), queryset[idx].end());
	sort(QQ.begin(), QQ.end(), tikusComp);
	while(!pq.empty()) {
		pq.pop();
	}
	for(int i = 1; i <= M; i++) {
		applestate[i] = ar[idx][i];
	}
	vector<tikus>::iterator pt = QQ.begin();
	int rec = 1;
	while(rec <= M) {
		while(pt != QQ.end() && pt -> aw == rec) {
			pq.push({{pt -> ak, pt -> baw}, pt -> id});
			pt++;
		}
		while(!pq.empty()) {
			// cout << idx << " " << rec << "\n";
			p3i atas = pq.top();
			// cout << idx << "," << rec << "  " << atas.s << "\n";
			has += min(applestate[rec], val[atas.s]);
			if(val[atas.s] >= applestate[rec]) {
				val[atas.s] -= applestate[rec];
				// cout << "topnya tetep;\n";
				break;
			}
			else if(val[atas.s] < applestate[rec]){
				pq.pop();
				applestate[rec] -= val[atas.s];
				val[atas.s] = 0;
				// cout << "topnya berubah;\n";
			}
		}
		rec++;
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			scanf("%d", &ar[i][j]);
		}
	}
	int top, bot, le, ri;
	for(int k = 1; k <= K; k++) {
		scanf("%d %d %d %d %d", &top, &bot, &le, &ri, &val[k]);
		for(int row = top; row <= bot; row++) {
			queryset[row].pb(masuk(le, ri, bot, k));
		}
	}
	// printf("Success reading input\n");
	for(int i = 1; i <= N; i++) {
		queryProc(i);
	}
	printf("%lld\n", has);
}












