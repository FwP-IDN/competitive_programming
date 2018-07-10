#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back

string flag[505];
int match[505], dist[505];
vector<int> cons[2][505];
vector<int> adj[505];
int n;

void read_input() {
	cin >> n >> n >> n;
	for(int i = 1; i <= n; i++) {
		cin >> flag[i];
		int jump;
		while(cin >> jump && jump != -1) {
			cons[0][i].pb(jump);
		}
		while(cin >> jump && jump != -1) {
			cons[1][i].pb(jump);
		}
	}
}

bool parsing(vector<int> &A, vector<int> &B) {
	// kalau ada yang sama return true
	vector<int>::iterator itA = A.begin(), itB = B.begin();
	while(itA != A.end() && itB != B.end()) {
		if(*itA == *itB) {
			return true;
		}
		else if(*itA < *itB) {
			itA++;
		}
		else if(*itA > *itB) {
			itB++;
		}
	}
	return false;
}

void make_graph() {
	for(int i = 1; i <= n; i++) {
		sort(cons[0][i].begin(), cons[0][i].end());
		sort(cons[1][i].begin(), cons[1][i].end());
	}
	for(int i = 1; i <= n; i++) {
		if(flag[i] != "A") {
			continue;
		}
		for(int j = 1; j <= n; j++) {
			if(flag[j] != "B") {
				continue;
			}
			// cout << i << " :: " << j << "\n";
			if(parsing(cons[0][i], cons[1][j]) || parsing(cons[1][i], cons[0][j])) {
				adj[i].pb(j);
				// cout << i << " ;; " << j << "\n";
			}
		}
	}
}

bool dfs(int nod) {
	if(nod == 0) {
		return true;
	}
	for(int ke : adj[nod]) {
		int pake = match[ke];
		if(dist[pake] > dist[nod]) {
			if(dfs(pake)) {
				match[nod] = ke;
				match[ke] = nod;
				return true;
			}
		}
	}
	return false;
}

bool bfs() {
	queue<int> qq;
	dist[0] = -1;
	for(int i = 1; i <= n; i++) {
		if(flag[i] != "A") {
			continue;
		}
		if(match[i] == 0) {
			qq.push(i);
			dist[i] = 0;
		}
		else {
			dist[i] = -1;
		}
	}
	while(!qq.empty()) {
		int nod = qq.front(); qq.pop();
		for(int ke : adj[nod]) {
			int pake = match[ke];
			if(dist[pake] == -1) {
				dist[pake] = dist[nod] + 1;
				qq.push(pake);
			}
		}
	}
	if(dist[0] == -1) {
		return false;
	}
	dist[0] = INT_MAX;
	return true;
}

void solve() {
	int mf = 0;
	while(bfs()) {
		for(int i = 1; i <= n; i++) {
			if(flag[i] == "A" && match[i] == 0 && dfs(i)) {
				mf++;
			}
		}
	}
	cout << n - mf << "\n";
}

int main() {
	read_input();
	make_graph();
	solve();
}