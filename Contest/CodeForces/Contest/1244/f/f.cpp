/*
 * Author: apikdech
 * Time: 00:16:22 15-10-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;
int p[N], sz[N], r[N];
bool v[N];

int f(int v) {
	return (v == p[v] ? v : p[v] = f(p[v]));
}

void unite(int u, int v) {
	u = f(u), v = f(v);
	if (u == v) return;
	if (sz[u] > sz[v]) p[v] = u, sz[u] += sz[v];
	else sz[v] += sz[u], p[u] = p[v];
}

void pre() {
	for (int i = 0; i < N; i++) {
		p[i] = i, sz[i] = 1, r[i] = i;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	pre();
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	queue<pair<int, int>> q;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == s[(i+1) % s.length()]) {
			unite(i, (i + 1) % s.length());
			v[i] = v[(i+1) % s.length()] = 1;
			q.push({i, k});
			q.push({(i+1) % s.length(), k});
		}
	}
	while(!q.empty()) {
		int u = q.front().first;
		int step = q.front().second;
		q.pop();
		v[u] = 1;
		if (!step) continue;
		if (!v[(u+1)%n]) {
			v[(u+1)%n] = 1;
			unite(u, (u+1)%n);
			q.push({(u+1)%n, step-1});
		}
		if (!v[(u+n-1)%n]) {
			v[(u+n-1)%n] = 1;
			unite(u, (u+n-1)%n);
			q.push({(u+n-1)%n, step-1});
		}
	}
	// for (int i = 0; i < n; i++) {
	// 	cout << i << " " << f(i) << " " << sz[f(i)] << "\n";
	// 	// cout << s[f(i)];
	// }
	for (int i = 0; i < n; i++) {
		if (sz[f(i)] == 1) {
			if (k & 1) {
				if (s[f(i)] == 'W') cout << 'B';
				else cout << 'W';
			} else {
				cout << s[f(i)];
			}
		}
		else cout << s[f(i)];
	}
	cout << "\n";
	return 0;
}
