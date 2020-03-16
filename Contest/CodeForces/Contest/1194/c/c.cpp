/*
 * Author: apikdech
 * Time: 22:14:25 14-07-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		string s, t, p, ans = "";
		cin >> s >> t >> p;
		int sz = s.length(), tz = t.length(), pz = p.length();
		int x = min(sz, tz), cnt[30], ok = 1;
		memset(cnt, 0, sizeof cnt);
		if (sz > tz) {
			cout << "NO\n";
			continue;
		}
		for (char c : p) cnt[c - 'a']++;
		for (int i = 0, j = 0; j < tz && ok;) {
			if (i < s.length() && s[i] == t[j]) ans += s[i], j++, i++;
			else if (cnt[t[j] - 'a']) {
				cnt[t[j] - 'a']--, ans += t[j];
				s.insert(i, 1, t[j]);
				i++;
				j++;
			}
			else ok = 0;
		}
		// cout << s << " " << t << "\n";
		if (s == t) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
