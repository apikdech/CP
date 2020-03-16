/*
 * Author: apikdech
 * Time: 21:50:44 05-09-2019
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
		int s, i, e, ans = 0;
		cin >> s >> i >> e;
		ans = (s + e - i + 1)/2;
		// if ((s + e - i) % 2 == 0) ans--;
		ans = min(ans, e+1);
		if (ans < 0) ans = 0;
		cout << ans << "\n";
	}
	return 0;
}
