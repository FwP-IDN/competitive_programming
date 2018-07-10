#include <bits/stdc++.h>
using namespace std;

long long p, a, r, d;

void init() {
	d = p - 1;
	r = 0;
	while(!(d & (long long)1)) {
		d /= (long long)2;
		r++;
	}
}

__int128 pows(__int128 x, long long pan, __int128 mod) {
	__int128 y = 1;
	if(pan == 0) {
		return (__int128)1;
	}
	while(pan ^ (long long)1) {
		if(pan & (long long)1) {
			y *= x;
			y %= mod;
		}
		pan /= (long long)2;

		x *= x;
		x %= mod;
	}
	x *= y;
	x %= mod;
	return (__int128)x;
}

bool test() {
	__int128 num = pows(a, d, p);
	// cout << a << " " << d << " " << r << " " << (long long)num << "\n";

	if(num == (__int128)1) {
		return true;
	}
	for(int i = 0; i < r; i++) {
		if(num == (__int128)p-1) {
			return true;
		}
		num *= num;
		num %= (__int128)p;
	}
	return false;
}

bool millerRabin() {
	init();
	for(int i = 1; i <= 100; i++) {
		a = (((long long)RAND_MAX * rand() + rand()) % (p - 1)) + 1;
		if(!test()) {
			return false;
		}
	}
	return true;
}

int main() {
	int tes;
	scanf("%d", &tes);
	while(tes--) {
		scanf("%lld", &p);
		if(p & (long long)1) {
			if(millerRabin()) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
		else {
			if(p == (long long)2) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}
}