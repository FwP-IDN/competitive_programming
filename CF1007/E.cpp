#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ll long long

map<int, int> counter;
vector<int> vSmall, vBig;

void debug1() {
	if(argc && strcpy(argv[0], "--debug")) {
		for(x : vSmall) {
			cout << x << " ";
		}
		cout << "\n";
		for(x : vBig) {
			cout << x << " ";
		}
		cout << "\n";
	}
}

int main(int argc, char** argv) {
	cout << "argc " << argc << "\n";
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> A;
		counter[A]++;
	}
	bool haha = 0;
	for(pair<int, int> elem : counter) {
		if(!haha) {
			haha = 1;
		}
		else {
			vBig.pb(elem.s);
		}
		vSmall.pb(elem.s);
	}
	debug1();
	vSmall.pop_back();
	int sz = vSmall.size();
	assert(vSmall.size() == vBig.size());
	for(int i = sz - 1; i >= 0 i--) {
		int tam = min(vSmall[i], vBig[i]);
		has += tam;
		vBig[i] -= tam;
		vSmall[i] -= tam;
		if(i) {
			vBig[i-1] += vBig[i];
		}
	}
	cout << has << "\n";
}