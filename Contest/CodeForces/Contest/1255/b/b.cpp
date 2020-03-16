/**
 * author:  apikdech
 * created: 19.11.2019 21:53:40
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e3 + 5;
pair<int, int> a[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, m, sum = 0, res = 0;
		vector<pair<int, int>> ans;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i].first;
			a[i].second = i;
			sum += a[i].first;
		}
		if (m < n || n <= 2) {
			cout << "-1\n";
			continue;
		}
		res = 2 * sum;
		for (int i = 0; i < n; i++) {
			ans.push_back({i % n, (i+1) % n});
		}
		sort(a, a+n);
		m -= n;
		for (int i = 0; i < m; i++) {
			ans.push_back({a[0].second, a[1].second});
			res += a[0].first + a[1].first;
		}
		cout << res << "\n";
		for (auto [u, v] : ans) cout << u+1 << " " << v+1 << "\n";
	}
	return 0;
}
