/*
 * Author: apikdech
 * Time: 22:51:55 20-07-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	ll o = 0, to = 0, v = 0, vo = 0, sum = 0, ans = 0;
	char last;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'v') {
			vo++;
			if (vo == 2) sum += v * to, to = 0;
			if (vo > 1) ans += sum;
		}
		else {
			v += max(vo - 1, 0LL);
			vo = 0;
			to++;
		}
		// cout << i << " " << o << " " << v << " " << sum << " " << "\n";
	}
	cout << ans << "\n";
	return 0;
}
