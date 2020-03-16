/*
 * Author: apikdech
 * Time: 21:37:13 20-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	int x = 0, ans = 0;
	cin >> s;
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.length(); i+=2) {
		if (i < s.length()) ans++;
		if (s[i] == '1') x++;
		if (s[i+1] == '1') x++;
	}
	if (x == 1 && s.length() % 2 == 1 || x == 0) ans--;
	cout << ans << "\n";
	return 0;
}
