/**
 * author:  apikdech
 * created: 29.11.2019 22:17:35
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 30;

int p[N];
set<int> S;

int f(int v) {
	return (v == p[v] ? v : p[v] = f(p[v]));
}

void unite(int u, int v) {
	u = f(u), v = f(v);
	if (u == v) return;
	p[v] = u;
}

void init() {
	for (int i = 0; i < N; i++) p[i] = i;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	init();
	int n, ans = 0;
	cin >> n;
	while(n--) {
		string s;
		cin >> s;
		S.insert(s[0] - 'a');
		for (int i = 1; i < s.length(); i++) {
			unite(s[i] - 'a', s[0] - 'a');
			S.insert(s[i] - 'a');
		}
	}
	for (auto it : S) {
		// cout << it << "\n";
		if (it == p[it]) ans++;
	}
	cout << ans << "\n";
	return 0;
}
