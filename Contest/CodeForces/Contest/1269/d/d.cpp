/**
 * author:  apikdech
 * created: 21.12.2019 19:27:46
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 3e5 + 5;

ll a[N], ans = 0, cnt[N];
vector<pair<ll, ll>> x, v;
int vis[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = N-1; i >= 0; i--) {
		if (cnt[i] == 0) continue;
		x.push_back({i, cnt[i]});
	}
	// reverse(x.begin(), x.end());
	for (auto [id, num] : x) {
		if (num % 2 == 0) {
			ans += num * id / 2;
			v.push_back({id, 0});
		}
		else {
			ans += (num - 1) * id / 2;
			v.push_back({id, 1});
		}
	}
	for (int i = 0; i + 1 < v.size(); i++) {
		if (v[i].second == 0) continue;
		if (vis[i] || vis[i+1]) continue;
		if (v[i+1].second != 0) {
			ans += v[i+1].first;
			// v[i].first -= v[i+1].first;
			ans += (v[i].first - v[i+1].first)/2;
			vis[i] = vis[i+1] = 1;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (vis[i] || v[i].second == 0) continue;
		ans += v[i].first / 2;
	}
	cout << ans << "\n";
	return 0;
}
