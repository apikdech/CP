#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 3e5 + 5;
ll x[N], p[N], d[N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, m, g = 0, j = -1;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		if (i) d[i] = x[i] - x[i-1];
	}
	for (int i = 1; i < n; i++) {
		// cerr << d[i] << "\n";
		g = __gcd(g, d[i]);
	}
	// cerr << g << "\n";
	for (int i = 0; i < m; i++) {
		cin >> p[i];
		if (j != -1) continue;
		if (g == p[i]) j = i+1;
		else if (g % p[i] == 0) j = i+1;
	}
	if (j == -1) return cout << "NO\n", 0;
	cout << "YES\n";
	cout << x[0] << " " << j << "\n";
	return 0;
}