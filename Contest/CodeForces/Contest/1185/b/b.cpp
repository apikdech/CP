/*
 * Author: apikdech
 * Time: 06:17:35 20-06-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		bool ok = 1, okk = 0;
		int cnt1 = 1, cnt2 = 0, j = 0;
		string s, t;
		cin >> s >> t;
		char last = s[0];
		if (t.length() < s.length()) ok = 0;
		else {
			for (int i = 1; i < s.length(); i++) {
				if (s[i] != last) {
					cnt2 = 0;
					while(j < t.length() && t[j] == last) j++, cnt2++;
					if (cnt2 < cnt1) ok = 0;
					else okk = 0;
					last = s[i], cnt1 = 1, okk = 1;
				}
				else cnt1++;
			}
			if (j < t.length()) {
				cnt2 = 0;
				while(j < t.length() && t[j] == last) j++, cnt2++;
				if (cnt2 < cnt1) ok = 0;
				else okk = 0;
			}
			if (j < t.length() || okk) ok = 0;
		}
		if (!ok) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}
