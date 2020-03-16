/**
 * author:  apikdech
 * created: 07.11.2019 21:12:59
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

set<pair<int, int>> edges;
set<int> s;
int cnt = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		edges.insert({x, y});
		edges.insert({y, x});
	}
	for (int i = 1; i <= n; i++) s.insert(i);
	for (int i = 1; i <= n; i++) {
		if (!s.count(i)) continue;
		cnt++;
		queue<int> q;
		q.push(i);
		s.erase(i);
		while(!q.empty()) {
			int u = q.front(); q.pop();
			vector<int> nxt;
			for (int v : s) {
				if (!edges.count({u, v})) nxt.push_back(v);
			}
			for (int v : nxt) {
				s.erase(v);
				q.push(v);
			}
		}
	}
	cout << cnt - 1 << "\n";
	return 0;
}
