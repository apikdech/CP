#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool loc[55][30];
vector<int> adj[55];
int n, q;
string x;

bool dfs(int i) {
	stack<int> s;
	bool vis[55];
	int dist[55];
	memset(vis, 0, sizeof vis);
	s.push(i);
	vis[i] = 1;
	dist[i] = 0;
	while(!s.empty()) {
		int u = s.top();
		for (int j = 0; j < n; j++) {
			if (vis[j]) continue;
			dist[j] = dist[u] + 1;
			if (loc[j][x[dist[j]]-'A']) {
				if (dist[j] == x.length()-1) return true;
				vis[j] = 1;
				s.push(j);
			}
		}
		s.pop();
		vis[u] = 0;
	}
	return false;
}

int main() {
	cin >> n >> q;
	string s;
	getline(cin, s);
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		for (int j = 0; j < s.length(); j++) {
			if (s[j] >= 'A' && s[j] <= 'Z') {
				loc[i][s[j]-'A'] = 1;
			}
		}
	}
	while(q--) {
		cin >> x;
		if (x.length() > n) {
			cout << "NO\n";
			continue;
		}
		bool flag = false;
		for (int i = 0; i < n; i++) {
			if (loc[i][x[0]-'A']) {
				if (x.length() == 1) flag = true;
				else flag = dfs(i);
			}
			if (flag) {
				cout << "YES\n";
				break;
			}
		}
		if (!flag) cout << "NO\n";
	}
	return 0;
}