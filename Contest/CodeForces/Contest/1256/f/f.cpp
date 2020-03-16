/**
 * author:  apikdech
 * created: 04.11.2019 22:44:40
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int frek[30][2];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		int n, ok = 0;
		memset(frek, 0, sizeof frek);
		cin >> n;
		string s, t;
		cin >> s;
		cin >> t;
		for (char c : s) {
			frek[c - 'a'][0]++;
		}
		for (char c : t) {
			frek[c - 'a'][1]++;
		}
		for (int i = 0; i < 26; i++) {
			if (frek[i][0] != frek[i][1]) {
				ok = -1;
				break;
			}
			if (frek[i][0] > 1) ok = 1;
		}
		if (ok == -1) cout << "NO\n";
		else if (ok == 0) {
			ok = 1;
			for (int i = 0; i < n-1; i++) {
				int idx = -1;
				for (int j = i; j < n; j++) {
					if (s[i] == t[j]) {
						idx = j;
						break;
					}
				}
				if (idx == n-1) {
					// cout << s << " " << t << "\n";
					reverse(s.end() - 2, s.end());
					reverse(t.end() - 2, t.end());
					// cout << s << " " << t << "\n";
					idx--;
				}
				if (idx == -1) continue;
				// cout << s << " " << t << "\n";
				reverse(s.begin() + i + 1, s.begin() + idx + 2);
				reverse(t.begin() + i, t.begin() + idx + 1);
				// cout << s << " " << t << "\n";
			}
			// cout << s << "\n";
			// cout << t << "\n";
			for (int i = 0; i < n; i++) if (s[i] != t[i]) ok = 0;
			if (!ok) cout << "NO\n";
			else cout << "YES\n";
		}
		else cout << "YES\n";
	}
	return 0;
}
