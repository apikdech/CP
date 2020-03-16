/*
 * Author: apikdech
 * Time: 21:56:38 30-06-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;
int cnt[N][30], w[30], n;

bool cek(int m) {
	for (int i = 0; i < 26; i++) if (cnt[m][i] < w[i]) return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (i) {
			// cnt[i][s[i] - 'a'] = cnt[i-1][s[i] - 'a'] + 1;
			for (int j = 0; j < 26; j++) {
				if (j == s[i] - 'a') cnt[i][j] = cnt[i-1][j] + 1;
				else cnt[i][j] = cnt[i-1][j];
			}
		}
		else cnt[i][s[i] - 'a'] = 1;
	}
	int q;
	cin >> q;
	while(q--) {
		memset(w, 0, sizeof w);
		string t;
		cin >> t;
		for (int i = 0; i < t.length(); i++) {
			w[t[i] - 'a']++;
		}
		int l = 0, r = n-1, m, ans = -1;
		while(l <= r) {
			m = (l+r) >> 1;
			if (cek(m)) ans = m, r = m-1;
			else l = m+1;
			// cerr << m << "\n";
		}
		cout << ans+1 << "\n";
	}
	return 0;
}
