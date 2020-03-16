/**
 * author:  apikdech
 * created: 15.12.2019 14:01:31
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
		string s, c;
		cin >> s >> c;
		int ok = 0;
		if (s < c) {
			cout << s << "\n";
			continue;
		}
		for (int i = 0; i < s.length(); i++) {
			int la = -1;
			for (int j = i+1; j < s.length(); j++) {
				if (s[j] < s[i]) {
					if (la == -1) la = j;
					else if (s[la] > s[j]) la = j;
				}
			}
			if (la != -1) swap(s[i], s[la]);
			if (s < c) {
				cout << s << "\n";
				ok = 1;
				break;
			}
			if (ok) break;
			if (la != -1) swap(s[i], s[la]);
		}
		if (ok) continue;
		cout << "---\n";
	}
	return 0;
}
