/*
 * Author: apikdech
 * Time: 22:45:18 13-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e6 + 5;
int pref[N], suf[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string s, t;
	cin >> s >> t;
	int pos = 0, ans = 0, n = s.length(), m = t.length();
	for (int i = 0; i < m; i++) {
		while(t[i] != s[pos]) pos++;
		pref[i] = pos++;
	}
	pos = n - 1;
	for (int i = m - 1; i >= 0; i--) {
		while(t[i] != s[pos]) pos--;
		suf[i] = pos--;
	}
	ans = max({0, n - 1 - pref[m-1], suf[0]});
	for (int i = 0; i < m - 1; i++) {
		ans = max(ans, suf[i+1] - pref[i] - 1);
	}
	cout << ans << "\n";
	return 0;
}
