#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int q;
	cin >> q;
	while(q--) {
		ll x, ans = 1;
		cin >> x;
		if (x & (x+1)) {
			while(ans <= x) ans <<= 1;
			ans--;
		} else {
			ll tmp = x;
			tmp++, tmp >>= 1;
			if ((ll)log2(tmp) & 1) {
				while(tmp) x ^= tmp, tmp >>= 2;
				ans = x;
			}
		}
		cout << ans << "\n";
	}
	// cout << log2(8388608 >> 1) << "\n";
	return 0;
}
