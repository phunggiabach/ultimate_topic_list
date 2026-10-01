#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1000000];

int visited[1000000], parent[1000000];

void dfs(int u) {
	visited[u] = 1;
	for (auto v: adj[u]) {
		if (!visited[v]) {
			dfs(v);
			parent[u] += parent[v]+1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 2; i <= n; i++) {
		int x; cin >> x;
		adj[i].push_back(x);
		adj[x].push_back(i);	
	}
	
	dfs(1);
	
	for (int i = 1; i <= n; i++) cout << parent[i] << " ";
	
	return 0;	
}
