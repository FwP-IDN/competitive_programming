#include <bits/stdc++.h>
using namespace std;

// kita naruh di rentang {1..3} dan {1..7}/{1..67}
// shg {2} dan {2..6}/{2..66}

vector<int> needToCall;
bool isPlanted[4][68];
int cnt[67];

void init(int anc) {
	needToCall.resize(anc / 3 - 1);
	for(int i = 0; i < anc / 3 - 1; i++) {
		needToCall[i] = i + 2;
	}
	for(int i = 1; i <= 3; i++) {
		for(int j = 1; j <= anc / 3 + 1; j++) {
			isPlanted[i][j] = 0;
		}
	}
	for(int j = 2; j <= anc / 3; j++) {
		cnt[j] = 9;
	}
}

void del(vector<int> &vec, int val) {
	for(int i = 0; i < (int)vec.size(); i++) {
		if(vec[i] == val) {
			vec.erase(vec.begin() + i);
			return;
		}
	}
	assert(false);
}

void eval(int y) {
	assert(cnt[y]);
	cnt[y]--;
	if(!cnt[y]) {
		del(needToCall, y);
	}
}

bool inRange(int L, int mid, int R) {
	return L <= mid && mid <= R;
}

void play() {
	int A;
	cin >> A;
	init(A);
	while(!needToCall.empty()) {
		int x, y = needToCall[rand() % ((int)needToCall.size())];
		cout << 2 << " " << y << endl;
		cin >> x >> y;
		if(x == 0 && y == 0) {
			return;
		}
		if(isPlanted[x][y]) {
			// do nothing
			continue;
		}
		isPlanted[x][y] = 1;
		if(inRange(2, y, A / 3)) {
			eval(y);
		}
		if(inRange(2, y - 1, A / 3)) {
			eval(y - 1);
		}
		if(inRange(2, y + 1, A / 3)) {
			eval(y + 1);
		}
	}
}

int main() {
	int tes;
	cin >> tes;
	while(tes--) {
		play();
	}
}