/*
 * Author: apikdech
 * Time: 20:08:03 11-06-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll n;
	cin >> n;
	if (n & 1) cout << "0\n";
	else {
		ll ans = 1LL << (n/2);
		cout << ans << "\n";
	}
	return 0;
}
