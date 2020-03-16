#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll a[105];
vector<int> adj[105], ans;
int n;

bool dfs(int x) {
	bool visited[105];
	int dist[105], before[105];
	memset(visited, 0, sizeof visited);
	memset(dist, 0, sizeof dist);
	memset(before,-1, sizeof before);
	stack<int> s;
	s.push(x);
	visited[x] = 1;
	dist[x] = 1;
	while(!s.empty()) {
		int v = s.top();
		// cout << v << "\n";
		s.pop();
		for (auto u : adj[v]) {
			if (!visited[u]) {
				visited[u] = 1;
				before[u] = v;
				dist[u] = dist[v] + 1;
				if (dist[u] == n) {
					ans.push_back(u);
					while(true) {
						u = before[u];
						if (u == -1) return 1;
						ans.push_back(u);
					}
				}
				s.push(u);
			}
		}
	}
	return 0;
}

int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (a[j] == a[i]/3 && a[i] % 3 == 0) adj[i].push_back(j);
			if (a[j]/2 == a[i] && a[j] % 2 == 0) adj[i].push_back(j);
		}
	}
	for (int i = 0; i < n; i++) {
		if(!dfs(i)) continue;
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		if (i != ans.size()-1) cout << a[ans[i]] << " ";
		else cout << a[ans[i]] << "\n";
	}
	return 0;
}