/**
 * author:  apikdech
 * created: 18.12.2019 13:18:55
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
		ll n, ok = 0;
		cin >> n;
		ok = n/14;
		n %= 14;
		if (ok) {
			if (n >= 1 && n <= 6) cout << "YES\n";
			else cout << "NO\n";
		} else cout << "NO\n";
	}
	return 0;
}
