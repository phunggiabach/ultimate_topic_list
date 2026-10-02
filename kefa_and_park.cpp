#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = 0;

int a[1000000], visited[1000000], parent[1000000];

vector<int> adj[1000000];

void dfs(int u) {
	visited[u] = 1;
	bool check = true;
	for (int v:adj[u]) {
		if (!visited[v]) {
			check = false;
			if (a[u] == 1) parent[v] = parent[u]+a[v];
			else parent[v] = a[v];
			if (parent[v] > m) continue;
			dfs(v);
		}
	}
	if (check == true) {
		cnt++;	
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i =  1; i <= n; i++) cin >> a[i];
	
	for (int i = 1; i <= n-1; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);	
	}
	
	if (a[1] == 1) parent[1] = 1;
	
	dfs(1);
	
	cout << cnt;
	return 0;	
}

// https://codeforces.com/problemset/problem/580/C
