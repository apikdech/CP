/**
 * author:  apikdech
 * created: 27.11.2019 21:09:01
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
		ll a, b;
		cin >> a >> b;
		if (a < b) swap(a, b);
		if (a == b) {
			if (a % 3 == 0) cout << "YES\n";
			else cout << "NO\n";
		} else {
			ll diff = a - b;
			a -= 2 * diff;
			b -= diff;
			if (a < 0 || b < 0) cout << "NO\n";
			else if (a == b) {
				if (a % 3 == 0) cout << "YES\n";
				else cout << "NO\n";
			} else cout << "NO\n";
		}
	}
	return 0;
}
