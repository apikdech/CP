/*
 * Author: apikdech
 * Time: 16:58:58 20-07-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e6 + 3, N = 1e6 + 5;
ll a[15][15], inv[N], ans[15];

ll f(ll x) {
	ll res = 0, it = 1;
	for (int i = 0; i <= 10; i++) {
		res = res + (it * ans[i]) % MOD;
		res %= MOD;
		it = (it * x) % MOD;
	}
	return res;
}

void solve() {
	inv[1] = 1;
	for (ll i = 2; i < MOD; i++) {
		inv[i] = (MOD - (MOD/i) * inv[MOD%i] % MOD) % MOD;
	}
	int n = 11, m = 11;
	for (int col = 0, row = 0; col < m and row < n; col++, row++) {
		for (int i = 0; i < n; i++) {
			if (i != row) {
				ll c = (a[i][col] * inv[a[row][col]]) % MOD;
				for (int j = col; j <= m; j++) {
					a[i][j] = a[i][j] - (a[row][j] * c) % MOD;
					if (a[i][j] < 0) a[i][j] += MOD;
				}
			}
		}
	}
	for (int i = 0; i <= 10; i++) {
		ans[i] = (a[i][11] * inv[a[i][i]]) % MOD;
	}
	for (int i = 0; i < MOD; i++) {
		if (f(i) == 0) {
			cout << "! " << i << endl;
			exit(0);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i <= 10; i++) {
		cout << "? " << i << endl;
		cin >> a[i][11];
		a[i][0] = 1;
		for (int j = 1; j <= 10; j++) {
			a[i][j] = (i * a[i][j-1]) % MOD;
		}
	}
	solve();
	cout << "! -1" << endl;
	return 0;
}
