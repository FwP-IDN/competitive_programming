#include<bits/stdc++.h>
using namespace std;


struct StructBinaryTree {
	static const int MAXN = 10000;
	int recentNod = 1;
	int ar[MAXN + 5];
	int N;
	vector<int> ans;
	
	struct Tree {
		int le; // left
		int ri; // right
		int val; //value inside
	} tree[MAXN + 5];

	void read() {
		cin >> N;
		for(int i = 0; i < N; i++) {
			cin >> ar[i];
		}
	}

	int insert(int nod, int value) {
		if(nod == 0) {
			recentNod++;
			tree[recentNod].le = 0;
			tree[recentNod].ri = 0;
			tree[recentNod].val = value;
			return recentNod;
		}
		if(value <= tree[nod].val) {
			tree[nod].le = insert(tree[nod].le, value);
			return nod;
		}
		else {
			tree[nod].ri = insert(tree[nod].ri, value);
			return nod;
		}
	}

	void solve() {
		tree[1].le = 0;
		tree[1].ri = 0;
		tree[1].val = ar[0];
		for(int i = 1; i < N; i++) {
			insert(1, ar[i]);
		}
	}

	void print() {
		for(int nod = 1; nod <= recentNod; nod++) {
			if(tree[nod].le != 0 || tree[nod].ri != 0) {
				ans.push_back(tree[nod].val);
			}
		}
		sort(ans.begin(), ans.end());
		for(int i = 0; i < (int)ans.size(); i++) {
			cout << ans[i] << "\n";
		}
	}

} T;

int main() {
	T.read();
	T.solve();
	T.print();
}