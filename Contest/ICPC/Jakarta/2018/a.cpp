/*
 * Author: apikdech
 * Time: 11:10:17 03-09-2019
 * Last Modified: 09:01:45 05-09-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int satu = 0, nol = 0;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s, ans = "";
	cin >> s;	
	int n = s.length();
	for (char c : s) {
		if (c == '1') satu++;
		else nol++;
	}
	for (int i = 0; i < s.length(); i++) {
		if (satu > nol) ans += '0';
		else if (satu < nol) ans += '1';
	}
	if (satu == nol) {
		if (s[0] == '1') {
			for (int i = 0; i < n; i++) ans += '1';
			ans[0] = '0';
		} else if (s[0] == '0') {
			for (int i = 0; i < n; i++) ans += '0';
			ans[0] = '1';
		}
	}
	cout << ans << "\n";
	// cerr << "time = " << (int)(clock() * 1000. / CLOCKS_PER_SEC) << " ms\n";
	return 0;
}