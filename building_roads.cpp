#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<pair<int, int>> vp;

vector<int> adj[1000000];

int visited[1000000];

void dfs(int u) {
	visited[u] = 1;
	for (int x:adj[u]) {
		if (!visited[x]) dfs(x);
	}
}

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	dfs(1);
	
	for (int i = 2; i <= n; i++) {
		if (!visited[i]) {
			vp.push_back({1, i});
			dfs(i);
		}
	}
	
	cout << vp.size() << "\n";
	for (int i = 0; i < vp.size(); i++) {
		cout << vp[i].first << " " << vp[i].second << "\n";	
	}
	return 0;
}
