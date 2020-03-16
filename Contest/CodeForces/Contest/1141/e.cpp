#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 2e5 + 5;
ll hp, n, a[N], dmg, l, r, m, ans, k, sum[N];

bool cek(ll x) {
	if (x * dmg + hp <= 0) {
		k = 0;
		return 1;
	}
	for (int i = 1; i <= n; i++) {
		if (x * dmg + sum[i] + hp <= 0) {
			k = i;
			return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> hp >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = a[i] + sum[i-1];
		dmg += a[i];
	}
	if (dmg >= 0) {
		for (int i = 1; i <= n; i++) {
			if (sum[i] + hp <= 0) return cout << i << "\n", 0;
		}
		return cout << "-1\n", 0;
	}
	l = 0, r = abs(hp/dmg) + 10;
	while(l <= r) {
		m = (l+r) >> 1;
		if (cek(m)) r = m+1, ans = m*n + k;
		else l = m+1;
	}
	cout << ans << "\n";
	return 0;
}