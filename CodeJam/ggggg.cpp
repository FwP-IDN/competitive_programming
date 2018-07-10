#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second

pair<vector<int>, vector<int> > ar[4];
int cas = 0;

bool isGreater(vector<int> A, vector<int> B) {
	for(int i = 0; i < 6; i++) {
		if(A[i] > B[i]) {
			return true;
		}
		if(A[i] < B[i]) {
			return false;
		}
	}
	return false;
}

bool isCollide(pair<vector<int>, vector<int> > A, pair<vector<int>, vector<int> > B) {
	if(isGreater(A.f, B.f)) {
		swap(A.f, B.f);
	}
	return !(isGreater(B.f, A.s));
}

void solve() {
	for(int i = 0; i < 4; i++) {
		ar[i].f.resize(6);
		ar[i].s.resize(6);
		for(int j = 0; j < 6; j++) {
			cin >> ar[i].f[j];	
		}
		swap(ar[i].f[0], ar[i].f[2]);
		for(int j = 0; j < 6; j++) {
			cin >> ar[i].s[j];
		}
		swap(ar[i].s[0], ar[i].s[2]);
	}
	bool collide = false;
	for(int i = 0; i < 3; i++) {
		if(isCollide(ar[i], ar[3])) {
			collide = true;
			cout << i << "::\n";
		}
	}
	char status[10];
	if(collide) {
		strcpy(status, "COLLIDE");
	}
	else {
		strcpy(status, "OK");
	}
	printf("Case #%d: %s\n", ++cas, status);
}

int main() {
	int tes;
	cin >> tes;
	while(tes--) {
		solve();
	}
}