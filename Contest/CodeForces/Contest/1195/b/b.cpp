/*
 * Author: apikdech
 * Time: 22:13:53 17-07-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll n, k;
	cin >> n >> k;
	ll l = 1, r = n, m, ans;
	while(l <= r) {
		m = (l + r) >> 1;
		if (m*(m+1)/2 - (n-m) >= k) ans = n-m, r = m-1;
		else l = m+1;
	}
	cout << ans << "\n";
	return 0;
}
