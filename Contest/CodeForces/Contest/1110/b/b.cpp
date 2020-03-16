#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 1e5 + 5;
ll a[N];
vector<ll> v;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n, m, k, x;
	ll ans = 0;
	cin >> n >> m >> k;
	x = k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i) v.push_back(a[i] - a[i-1]);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n-k; i++) ans += v[i];
	cout << ans + k << "\n";
	return 0;
}