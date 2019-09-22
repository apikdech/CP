/*
 * Author: apikdech
 * Time: 09:31:20 05-09-2019
 * Last Modified: 11:34:32 05-09-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int len = 0, n, ans = 0, cnt = 0;
ll k, x;
string s, t = "";

ll to_int(string s) {
	ll res = 0;
	for (char c : s) {
		res *= 2;
		res += c - '0';
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> k >> s;
	n = s.length();
	while((1LL << ++len) <= k);
	cnt = n - len;
	if (n < len || to_int(s) <= k) cout << "0\n";
	else {
		t += "1";
		for (int i = 1; i < n; i++) {
			if (s[i] == '1') 
				if (cnt) cnt--, ans++;
				else t += "1";
			else t += "0";
		}
		x = to_int(t);
		while (x > k) ans++, x >>= 1;
		cout << ans << "\n";
	}
	// cerr << "time = " << (int)(clock() * 1000. / CLOCKS_PER_SEC) << " ms\n";
	return 0;
}