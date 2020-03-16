/**
 * author:  apikdech
 * created: 07.11.2019 07:54:55
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
		int n, ok = 1;
		cin >> n;
		string s, t;
		cin >> s >> t;
		map<pair<char, char>, int> m;
		for (int i = 0; i < n; i++) {
			if (s[i] == t[i]) continue;
			m[{s[i], t[i]}]++;
		}
		if (!m.empty() && (m.size() > 1 || (*m.begin()).second != 2)) ok = 0;
		if (ok) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
