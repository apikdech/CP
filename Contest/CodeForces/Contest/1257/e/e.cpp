/**
 * author:  apikdech
 * created: 17.11.2019 23:50:02
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, INF = 1e9, N = 4e5 + 5;

int BIT[N], sz;

void upd(int idx, int val) {
	for (int i = idx; i <= sz; i += i & -i) {
		BIT[i] = max(BIT[i], val);
	}
}

int query(int idx) {
	int res = 0;
	for (int i = idx; i > 0; i -= i & -i) {
		res = max(res, BIT[i]);
	}
	return res;
}

void pre(int n) {
	sz = n;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int k[3], n = 0, ans = 0;
	vector<int> t[3], v;
	for (int i = 0; i < 3; i++) {
		cin >> k[i];
		n += k[i];
	}
	pre(n);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < k[i]; j++) {
			int x;
			cin >> x;
			t[i].push_back(x);
		}
	}
	for (int i = 0; i < 3; i++) sort(t[i].begin(), t[i].end());
	for (int i = 0; i < 3; i++) v.insert(v.end(), t[i].begin(), t[i].end());
	vector<int> dp(n);
	for (int i = 0; i < n; i++) {
		dp[i] = max(query(v[i]-1) + 1, query(v[i]));
		ans = max(ans, dp[i]);
		upd(v[i], dp[i]);
	}
	// vector<int> d(n+1, INF);
	// d[0] = -INF;
	// for (int i = 0; i < n; i++) {
	// 	int j = upper_bound(d.begin(), d.end(), v[i]) - d.begin();
	// 	if (d[j-1] < v[i] && v[i] < d[j]) d[j] = v[i];
	// }
	// for (int i = 0; i <= n; i++) {
	// 	if (d[i] < INF) ans = i;
	// }
	cout << n - ans << "\n";
	return 0;
}