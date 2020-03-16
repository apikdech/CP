/*
 * Author: apikdech
 * Time: 19:40:11 11-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	string s, ans = "0000000000";
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') {
			for (int j = 0; j < 10; j++) if (ans[j] == '0') {
				ans[j] = '1';
				break;
			}
		} else if (s[i] == 'R') {
			for (int j = 9; j >= 0; j--) if (ans[j] == '0') {
				ans[j] = '1';
				break;
			}
		} else ans[s[i] - '0'] = '0';
	}
	cout << ans << "\n";
	return 0;
}
