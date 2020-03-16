/*
 * Author: apikdech
 * Time: 20:46:12 30-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;

ll powmod(ll a,ll b) {ll res=1; assert(b>=0); for(;b;b>>=1){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;}return res%MOD;}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll x, n, ans = 1;
	cin >> x >> n;
	vector<ll> prime;
	for (ll i = 2; i * i <= x; i++) {
		bool ok = 0;
		while(x % i == 0) x /= i, ok = 1;
		if (ok) prime.push_back(i);
	}
	if (x >= 2) prime.push_back(x);
	for (ll it : prime) {
		ll tmp = n, cnt = 0;
		while(tmp) {
			cnt += tmp/it;
			tmp /= it;
		}
		ans = (ans * powmod(it, cnt)) % MOD;
	}
	cout << ans << "\n";
	return 0;
}
