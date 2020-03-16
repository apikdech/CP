/*
 * Author: apikdech
 * Time: 21:35:25 25-08-2019
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
		ll a, b, n;
		cin >> a >> b >> n;
		if (n % 3 == 0) cout << a << "\n";
		else if (n % 3 == 1) cout << b  << "\n";
		else cout << (a ^ b) << "\n";
	}
	return 0;
}
