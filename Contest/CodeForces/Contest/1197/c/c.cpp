/*
 * Author: apikdech
 * Time: 22:28:31 22-07-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 3e5 + 5;
ll a[N], ans = 0;
vector<ll> v;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i) v.push_back(a[i] - a[i-1]);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n-k; i++) {
		ans += v[i];
	}
	cout << ans << "\n";
	return 0;
}
