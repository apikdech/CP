/**
 * author:  apikdech
 * created: 16.11.2019 22:11:39
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;
ll a[N], sum[N], ans = 0, add[N], BIT[N];
int n, m;

void adx(int idx, ll val) {
	for (int i = idx; i <= n; i += i & -i) {
		BIT[i] += val;
	}
}

ll query(int idx) {			//query sum [1, idx]
	ll res = 0;
	for (int i = idx; i > 0; i -= i & -i) {
		res += BIT[i];
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	for (int i = 0; i < n; i++) {
		sum[i % m] += a[i];
		add[i % m] += a[i];
		adx(i % m + 1, add[i % m]);
		sum[i % m] += add[i % m];
		cout << query(m) << " \n"[i + 1 == n];
	}
	return 0;
}
