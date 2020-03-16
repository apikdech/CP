/*
 * Author: apikdech
 * Time: 21:02:50 18-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
vector<ll> pos, neg;
ll ans = 0, nol = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		if (x == 0) nol++;
		else if (x > 0) pos.push_back(x);
		else neg.push_back(-x);
	}
	for (ll it : pos) ans += it - 1;
	for (ll it : neg) ans += it - 1;
	if (neg.size() & 1) {
		if (nol) ans += nol;
		else ans += 2;
	} else {
		ans += nol;
	}
	cout << ans << "\n";
	return 0;
}
