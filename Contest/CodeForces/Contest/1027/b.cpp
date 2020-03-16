#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, q;
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		ll x, y;
		cin >> x >> y;
		ll ans;
		//if (n & 1) {
			if ((x+y) & 1) {
				x--;
				ans = (n*n+1)/2 + (x*n+1)/2+(y+1)/2;
			} else {
				x--;
				ans = (x*n+1)/2+(y+1)/2;
			}
		//} else {
		// 	if ((x+y) & 1) {

		// 	} else {

		// 	}
		// }
		cout << ans << "\n";
	}
	return 0;
}