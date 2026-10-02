#include <bits/stdc++.h>
using namespace std;

long long a, b;

vector<long long> v;

void dfs(long long u) {
	if (u > b) return;
	v.push_back(u);
	if (u == b) {
		cout << "YES\n" << v.size() << "\n";
		for (int x:v) cout << x << " ";
		exit(0);
	}
	dfs(2*u);
	dfs(10*u + 1);
	v.pop_back();
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> a >> b;
	dfs(a);
	cout << "NO";
	return 0;	
}

// https://codeforces.com/contest/727/problem/A
