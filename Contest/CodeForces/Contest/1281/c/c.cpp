/**
 * author:  apikdech
 * created: 15.12.2019 13:05:35
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
		int x;
		string s;
		cin >> x >> s;
		ll ptr = 1LL;
		while(s.length() < x && ptr <= x) {
			int bck = s[ptr-1] - '0';
			int len = s.length();
			for (int it = 0; it < bck-1; it++) {
				for (int i = ptr; i < len; i++) {
					s += s[i];
				}
			}
			ptr++;
		}
		// cout << s << "\n";
		if (ptr > x) cout << s.length() << "\n";
		else {
			ll len = s.length();
			for (int i = ptr; i <= x; i++) {
				ll add = len - (ll)i;
				if (add < 0) add += MOD;
				add = (add * (ll)(s[i-1] - '0')) % MOD;
				// cout << add << " " << len << " " << i << "jadinya : ";
				len = ((ll)i + add) % MOD;
				// cout << len << "\n";
			}
			cout << len << "\n";
		}
	}
	return 0;
}
 