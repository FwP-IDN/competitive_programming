#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

struct tikus {
	int f;
	int g;
	ull hh; // hashnya

	bool operator < (const &other) const {
		return f < other.f;
	}
};

priority_queue<tikus> pq;
int x, y;

ull encode() {
	ull ret = 0;
	ull mul = 1;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			ret += (mul * temp[i][j]);
			mul <<= 4;
		}
	}
}

void decode(ull inp) {
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			temp[i][j] = inp & (ull)15;
			inp >>= 4;
			if(temp[i][j] == 0) {
				x = i;
				y = j;
			}
		}
	}
}

int main() {
	scanf("%d", &tes);
	while(tes--) {
		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 4; j++) {
				scanf("%d", temp[i] + j);
			}
		}
		aStar();
	}
}