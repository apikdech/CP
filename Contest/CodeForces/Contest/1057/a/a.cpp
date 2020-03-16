#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 2e5 + 5;
vector<int> adj[N];
int a[N], last[N], n;

void dfs(int i) {
	stack<int> s;
	s.push(i);
	while(!s.empty()) {
		int u = s.top(); s.pop();
		for (auto v : adj[u]) {
			s.push(v);
			last[v] = u;
			if (v == n) return;
		}
	}
}

int main() {
	cin >> n;
	a[1] = 0;
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
		adj[a[i]].push_back(i);
	}
	dfs(1);
	int idx = n;
	vector<int> ans;
	ans.push_back(n);
	while (last[idx]) {
		ans.push_back(last[idx]);
		idx = last[idx];
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		if (i != ans.size() - 1) cout << ans[i] << " ";
		else cout << ans[i] << "\n";
	}
	return 0;
}