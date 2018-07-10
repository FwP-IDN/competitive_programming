#include<bits/stdc++.h>
using namespace std;

const int logmax = 20;
const int maxn = 200000;

#define f first
#define s second


// struct SuffixArrayStruct {
	int N;
	pair<string, int> str[maxn + 5];
	string strall;
	pair<int, int> chr_num[maxn + 5], ar[maxn + 5];
	int cnt[maxn + 5];
	pair<pair<int, int>, int> xx[maxn + 5], yy[maxn + 5];
	int RA[logmax][maxn + 5];
	int SA[maxn + 5];
	
	static bool cmp(pair<string, int> A, pair<string, int> B) {
		if(A.f.length() < B.f.length()) {
			return true;
		}
		if(A.f.length() > B.f.length()) {
			return false;
		}
		return A < B;
	}

	void sort_elem() {
		sort(str, str + N, cmp);
		strall = "";
		for(int i = 0; i < N; i++) {
			strall += str[i].f + "{";
		}
	}

	void counting_sort() {
		for(int k = 0; k <= max(30, (int)strall.length()); k++) {
			cnt[k] = 0;
		}
		for(int i = 0; i < (int)strall.length(); i++) {
			int k = xx[i].f.s;
			cnt[k]++;
		}
		for(int k = 1; k <= max(30, (int)strall.length()); k++) {
			cnt[k] += cnt[k - 1];
		}
		for(int i = (int)strall.length() - 1; i >= 0; i--) {
			int k = xx[i].f.s;
			yy[--cnt[k]] = xx[i];
		}

		for(int k = 0; k <= max(30, (int)strall.length()); k++) {
			cnt[k] = 0;
		}
		for(int i = 0; i < (int)strall.length(); i++) {
			int k = yy[i].f.f;
			cnt[k]++;
		}
		for(int k = 1; k <= max(30, (int)strall.length()); k++) {
			cnt[k] += cnt[k - 1];
		}
		for(int i = (int)strall.length() - 1; i >= 0; i--) {
			int k = yy[i].f.f;
			xx[--cnt[k]] = yy[i];
		}
	}

	string getFrom(int st) {
		string ret = "";
		for(int i = st; i < (int)strall.length(); i++) {
			ret += strall[i];
		}
		return ret;
	}

	void testingSA() {
		for(int i = 0; i < (int)strall.length(); i++) {
			cout << i << ". " << getFrom(SA[i]) << "\n";
		}
	}

	void make_suffix_array() {
			for(int j = 0; j < (int)strall.length(); j++) {
				RA[0][j] = strall[j] - '`';
			}
		for(int i = 1; i < logmax; i++) {
			for(int j = 0; j < (int)strall.length(); j++) {
				xx[j].f.f = RA[i - 1][j];
				int span = (1 << (i - 1));
				if(j + span < (int)strall.length()) {
					xx[j].f.s = RA[i - 1][j + span];
				}
				else {
					xx[j].f.s = 0;
				}
				xx[j].s = j;
			}
			counting_sort();
			for(int j = 0; j < (int)strall.length(); j++) {
				int k = xx[j].s;
				int rank = j + 1;
				if(j > 0) {
					int prev_k = xx[j - 1].s;
					if(xx[j].f == xx[j - 1].f) {
						rank = RA[i][prev_k];
					}
				}
				RA[i][k] = rank;
			}
		}
		for(int j = 0; j < (int)strall.length(); j++) {
			int k = RA[logmax - 1][j];
			SA[k - 1] = j;
		}
		// testingSA();
	}

	void enum_chr() {
		int i_sorted_str = 0;
		for(int i = 0; i < (int)strall.length(); i++) {
			chr_num[i].f = i_sorted_str;
			chr_num[i].s = str[i_sorted_str].s;
			if(strall[i] == '{') {
				i_sorted_str++;
			}
		}
	}

	void testing_ar() {
		for(int i = 0; i < (int)strall.length(); i++) {
			cout << i << ". " << ar[i].f << " " << ar[i].s << "\n";
		}
	}

	void construct_ar() {
		for(int i = 0; i < (int)strall.length(); i++) {
			ar[i] = chr_num[SA[i]];
		}
		// testing_ar();
	}

	int parse(string &wrd, int olap) {
		int i;
		for(i = 0; i < (int)wrd.length() && i + olap < (int)strall.length(); i++) {
			if(wrd[i] < strall[i + olap]) {
				return -1;
			}
			else if(wrd[i] > strall[i + olap]) {
				return 1;
			}
		}
		if(i < (int)wrd.length()) {
			return 1;
		}
		return 0;
	}

	int getUB(string &wrd) {
		int le = 0;
		int ri = (int)strall.length();
		while(le < ri) {
			int mid = (le + ri) >> 1;
			// cout << le << " " << mid << " " << ri << "\n";
			if(parse(wrd, SA[mid]) < 0) {
				ri = mid;
			}
			else {
				le = mid + 1;
			}
		}
		return le;
	}

	int getLB(string &wrd) {
		int le = 0;
		int ri = (int)strall.length();
		while(le < ri) {
			int mid = (le + ri) >> 1;
			if(parse(wrd, SA[mid]) <= 0) {
				ri = mid;
			}
			else {
				le = mid + 1;
			}
		}
		return le;
	}
// };

// struct SegmentTreeStruct {
	#define tole(x) (x << 1)
	#define tori(x) ((x << 1) | 1)
	int s_ar;
	// pair<int, int> ar[maxn + 5];
	set<pair<int, int> > segTree[4 * maxn + 5];


	void bangun(int idx, int kiri, int kanan) {
		if(kiri == kanan) {
			segTree[idx].insert(ar[kiri]);
		}
		else {
			int ten = (kiri + kanan) >> 1;
			bangun(tole(idx), kiri, ten);
			bangun(tori(idx), ten + 1, kanan);
			set<pair<int, int> >::iterator itle = segTree[tole(idx)].begin(), itri = segTree[tori(idx)].begin();
			while(itle != segTree[tole(idx)].end() && itri != segTree[tori(idx)].end() && (int)segTree[idx].size() < 10) {
				if(*itle < *itri) {
					segTree[idx].insert(segTree[idx].end(), *itle);
					itle++;
				}
				else if(*itle > *itri) {
					segTree[idx].insert(segTree[idx].end(), *itri);
					itri++;
				}
				else {
					segTree[idx].insert(segTree[idx].end(), *itle);
					itle++; itri++;
				}
			}
			while((int)segTree[idx].size() < 10 && (itle != segTree[tole(idx)].end() || itri != segTree[tori(idx)].end())) {
				if(itle != segTree[tole(idx)].end()) {
					segTree[idx].insert(segTree[idx].end(), *itle);
					itle++;
				}
				else if(itri != segTree[tori(idx)].end()) {
					segTree[idx].insert(segTree[idx].end(), *itri);
					itri++;
				}
				else {
					break;
				}
			}
		}
	}

	void make_segment_tree() {
		bangun(1, 0, s_ar - 1);
	}

	void cari(int idx, int kiri, int kanan, int aw, int ak, set<pair<int, int> > &sen) {
		if(aw > kanan || ak < kiri) {
			return;
		}
		else if(aw <= kiri && kanan <= ak) {
			for(pair<int, int> x : segTree[idx]) {
				sen.insert(x);
			}
			while((int)sen.size() > 10) {
				set<pair<int, int> >::iterator it = sen.end();
				it--;
				sen.erase(it);
			}
		}
		else {
			int ten = (kiri + kanan) >> 1;
			cari(tole(idx), kiri, ten, aw, ak, sen);
			cari(tori(idx), ten + 1, kanan, aw, ak, sen);
		}
	}

	void getRes(int aw, int ak, set<pair<int, int> > &sen) {
		if(aw == ak) {
			return;
		}
		cari(1, 0, s_ar - 1, aw, ak - 1, sen);
	}
// };

// void parse_S_T(SuffixArrayStruct &S, SegmentTreeStruct &T) {
// 	T.s_ar = S.strall.length();
// 	for(int i = 0; i < T.s_ar; i++) {
// 		T.ar[i] = S.ar[i];
// 	}
// }

void parse_S_T() {
	s_ar = strall.length();	
}

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	// SuffixArrayStruct S = SuffixArrayStruct();

	// cin >> S.N;
	cin >> N;
	// for(int i = 0; i < S.N; i++) {
	// 	cin >> S.str[i].f;
	// 	S.str[i].s = i + 1;
	// }
	for(int i = 0; i < N; i++) {
		cin >> str[i].f;
		str[i].s = i + 1;
	}
	// S.sort_elem();
	sort_elem();
	// S.make_suffix_array();
	make_suffix_array();
	// S.enum_chr();
	enum_chr();
	// S.construct_ar();
	construct_ar();
	// SegmentTreeStruct T = SegmentTreeStruct();
	
	// parse_S_T(S, T);
	parse_S_T();
	// T.make_segment_tree();
	make_segment_tree();
	set<pair<int, int> > res;
	int Q;
	cin >> Q;
	string wrd;
	while(Q--) {
		cin >> wrd;
		// int aw = S.getLB(wrd), ak = S.getUB(wrd);
		int aw = getLB(wrd), ak = getUB(wrd);
		res.clear();
		// T.getRes(aw, ak, res);
		getRes(aw, ak, res);
		// cout << "aw " << aw << " -- " << "ak " << ak << "\n";
		if(res.empty()) {
			cout << "-1\n";
		}
		else {
			for(set<pair<int, int> >::iterator it = res.begin(); it != res.end(); it++) {
				if(it != res.begin()) {
					cout << " ";
				}
				cout << it -> s;
			}
			cout << "\n";
		}
	}
}