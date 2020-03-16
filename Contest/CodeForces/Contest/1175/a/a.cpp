/*
 * Author: apikdech
 * Time: 06:31:43 06-06-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll n, k, ans = 0;
		cin >> n >> k;
		while(n) {
			if (n % k == 0) ans++, n/=k;
			else ans += n % k, n -= n % k;
		}
		cout << ans << "\n";
	}
	return 0;
}
