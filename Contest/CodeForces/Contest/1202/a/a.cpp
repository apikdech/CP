/*
 * Author: apikdech
 * Time: 21:44:58 07-08-2019
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
		string x, y;
		int idx = 0, ans = 0;
		cin >> x >> y;
		reverse(x.begin(), x.end());
		reverse(y.begin(), y.end());
		for (int i = 0; i < y.length(); i++) {
			if (y[i] == '1') {
				idx = i;
				break;
			}
		}
		for (int i = idx; i < x.length(); i++) {
			if (x[i] == y[idx]) break;
			else ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
