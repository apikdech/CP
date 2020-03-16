/**
 * author:  apikdech
 * created: 15.12.2019 12:16:33
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
		string s, c, x;
		int ok = 0;
		cin >> s >> c;
		if (s < c) {
			cout << s << "\n";
			continue;
		}
		x = s;
		sort(x.begin(), x.end());
		for (int i = 0; i < s.length(); i++) {
			if (s[i] > x[i])
				for (int j = i + 1; j < s.length(); j++) {
					swap(s[i], s[j]);
					if (s < c) {
						cout << s << "\n";
						ok = 1;
						break;
					}
					swap(s[i], s[j]);
				}
			if (ok) break;
		}
		if (ok) continue;
		cout << "---\n";
	}
	return 0;
}
