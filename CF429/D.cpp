#include<bits/stdc++.h>
using namespace std;

struct StructSegTree {
	static const int MAXN = 300000;
	int ren = 0;
	int occ_min;
	int N, Q;
	int inp[MAXN + 5];
	int root[MAXN + 5];

	struct Tree {
		int le;
		int ri;
		int val;
	} segTree[40 * MAXN];

	void read() {
		scanf("%d %d", &N, &Q);
		for(int i = 1; i <= N; i++) {
			scanf("%d", inp + i);
		}
	}

	int build(int kiri, int kanan) {
		ren++;
		int ret = ren;
		if(kiri == kanan) {
			segTree[ret] = {-1, -1, 0};
			return ret;
		}
		int ten = (kiri + kanan) / 2;
		segTree[ret].le = build(kiri, ten);
		segTree[ret].ri = build(ten + 1, kanan);
		segTree[ret].val = 0;
		return ret;
	}

	int update(int prevNod, int kiri, int kanan, int pos) {
		ren++;
		int ret = ren;
		if(kiri == kanan) {
			assert(kiri == pos);
			segTree[ret] = {-1, -1, segTree[prevNod].val + 1};
			return ret;
		}
		int ten = (kiri + kanan) / 2;
		if(pos <= ten) {
			int nole = segTree[ret].le = update(segTree[prevNod].le, kiri, ten, pos);
			int nori = segTree[ret].ri = segTree[prevNod].ri;
			segTree[ret].val = segTree[nole].val + segTree[nori].val;
		}
		else {
			int nori = segTree[ret].ri = update(segTree[prevNod].ri, ten + 1, kanan, pos);
			int nole = segTree[ret].le = segTree[prevNod].le;
			segTree[ret].val = segTree[nole].val + segTree[nori].val;
		}
		return ret;
	}

	void make_segtree() {
		ren = -1;
		root[0] = build(1, N);
		for(int i = 1; i <= N; i++) {
			root[i] = update(root[i - 1], 1, N, inp[i]);
		}
	}

	int cari(int nodA, int nodB, int kiri, int kanan, int aw, int ak) {
		if(kiri == kanan) {
			if(segTree[nodB].val - segTree[nodA].val >= occ_min) {
				return kiri;
			}
			else {
				return -1;
			}
		}
		int ret = -1;
		int nexA = segTree[nodA].le;
		int nexB = segTree[nodB].le;
		int ten = (kiri + kanan) / 2;
		if(segTree[nexB].val - segTree[nexA].val >= occ_min) {
			ret = cari(nexA, nexB, kiri, ten, aw, ak);
		}
		nexA = segTree[nodA].ri;
		nexB = segTree[nodB].ri;
		if(segTree[nexB].val - segTree[nexA].val >= occ_min && ret == -1) {
			ret = cari(nexA, nexB, ten + 1, kanan, aw, ak);
		}
		return ret;
	}

	void queries() {
		int aw, ak, k;
		while(Q--) {
			scanf("%d %d %d", &aw, &ak, &k);
			occ_min = (ak - aw + 1) / k + 1;
			printf("%d\n", cari(root[aw - 1], root[ak], 1, N, aw, ak));
		}
	}
} T;

int main() {
	T.read();
	T.make_segtree();
	T.queries();
}