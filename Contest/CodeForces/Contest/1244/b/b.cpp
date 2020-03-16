/*
 * Author: apikdech
 * Time: 15:22:59 16-10-2019
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
		int n, l = 1005, r = 0, ans = 0, ok = 0;
		cin >> n;
		string s;
		cin >> s;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') l = min(l, i+1), r = max(r, i+1), ok = 1;
		}
		if (!ok) cout << n << "\n";
		else {
			ans = max(ans, 2*(n-l+1));
			ans = max(ans, 2*r);
			cout << ans << "\n";	
		}
	}
	return 0;
}
