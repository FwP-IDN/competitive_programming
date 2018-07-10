#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
vector<int> fact[MANX + 5];

struct Node {
	int child;
	Node *le;
	Node *ri;

	Node() {
		le = NULL;
		ri = NULL;
		child = 1;
	}
};

void prekom() {
	for(int i = 1; i <= MAXN; i++) {
		for(int j = i; j <= MAXN; j += i) {
			fact[j].push_back(i);
		}
		root[i] = NULL;
	}
}

bool udah[MAXN + 5];

int main() {
	prekom();
	cin >> Q;
	while(Q--) {
		cin >> iden;
		if(iden == 1) {
			cin >> uu;
			if(udah[uu]) {
				continue;
			}
			udah[uu] = true;
			for(int x : fact[uu]) {

			}
		}
		else {

		}
	}
}