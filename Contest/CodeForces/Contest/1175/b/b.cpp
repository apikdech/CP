/*
 * Author: apikdech
 * Time: 07:57:27 06-06-2019
 * Last Modified: 20:04:32 06-06-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007, INF = (1LL << 32) - 1;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int l, ok = 1;
	vector<ll> v;
	cin >> l;
	ll x = 0;
	while(l--) {
		string s;
		cin >> s;
		if (s[0] == 'f') {
			ll y;
			cin >> y;
			v.push_back(y);
		}
		else if (s[0] == 'a') {
			if (!ok) continue;
			if (v.empty()) x++;
			else {
				ll tmp = 1;
				for (auto it : v) {
					if (it == 1) continue;
					tmp *= it;
					if (tmp > INF) {
						ok = 0;
						break;
					}
				}
				x += tmp;
			}
		} else if (!v.empty()) v.pop_back();
		if (x > INF) ok = 0;
	}
	if (!ok) cout << "OVERFLOW!!!\n";
	else cout << x << "\n";
	// cerr << "time = " << (int)(clock() * 1000. / CLOCKS_PER_SEC) << " ms\n";
	return 0;
}