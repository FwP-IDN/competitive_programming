#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

ll n, m;
ll ar[205][205];
ll dist[205];
ll match[205];
ll maxi[205];
ll notNol = 0;
vector<ll> adj[205];
ll total = 0;

void make_graph() {
	for(ll i = 1; i <= n; i++) {
		for(ll j = n + 1; j <= n + m; j++) {
			maxi[i] = max(maxi[i], ar[i][j]);
		}
	}
	for(ll j = n + 1; j <= n + m; j++) {
		for(ll i = 1; i <= n; i++) {
			maxi[j] = max(maxi[j], ar[i][j]);
		}
	}
	for(ll i = 1; i <= n; i++) {
		for(ll j = n + 1; j <= n + m; j++) {
			if(ar[i][j] && maxi[i] == maxi[j]) {
				adj[i].pb(j);
			}
		}
	}
}

bool dfs(ll now) {
	if(now == 0) {
		return true;
	}
	for(ll ke : adj[now]) {
		ll pake = match[ke];
		if(dist[pake] > dist[now]) {
			if(dfs(pake)) {
				match[now] = ke;
				match[ke] = now;
				return true;
			}
		}
	}
	return false;
}

bool bfs() {
	queue<ll> qq;
	dist[0] = -1;
	for(ll i = 1; i <= n; i++) {
		if(match[i] == 0) {
			qq.push(i);
			dist[i] = 0;
		}
		else {
			dist[i] = -1;
		}
	}
	while(!qq.empty()) {
		ll now = qq.front(); qq.pop();
		for(ll ke : adj[now]) {
			ll pake = match[ke];
			if(dist[pake] == -1) {
				dist[pake] = dist[now] + 1;
				qq.push(pake);
			}
		}
	}
	if(dist[0] != -1) {
		dist[0] = INT_MAX;
		return true;
	}
	return false;
}

ll mcbm() {
	ll ret = 0;
	for(ll k = 1; k <= n + m; k++) {
		ret += maxi[k];
		if(maxi[k]) notNol--;
	}
	while(bfs()) {
		for(ll i = 1; i <= n; i++) {
			if(!match[i]) {
				dfs(i);
			}
		}
	}
	for(ll i = 1; i <= n; i++) {
		if(match[i]) {
			ret -= maxi[i];
			if(maxi[i]) notNol++;
		}
	}
	return ret;
}

int main() {
	scanf("%lld %lld", &n, &m);
	for(ll i = 1; i <= n; i++) {
		for(ll j = n + 1; j <= n + m; j++) {
			scanf("%lld", &ar[i][j]);
			if(ar[i][j]) {
				notNol++;
				total += ar[i][j];
			}
		}
	}
	make_graph();
	ll res = mcbm();
	// cout << total << "\n";
	// cout << res << "\n";
	// cout << notNol << "\n";
	printf("%lld\n", total - res - notNol);
}