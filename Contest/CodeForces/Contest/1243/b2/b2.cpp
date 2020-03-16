/**
 * author:  apikdech
 * created: 07.11.2019 07:54:55
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int cnt[26];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		memset(cnt, 0, sizeof cnt);
		int n, ok = 1;
		cin >> n;
		string s, t;
		cin >> s >> t;
		vector<pair<int, int>> ans;
		for (int i = 0; i < n; i++) {
			if (s[i] == t[i]) continue;
			cnt[s[i] - 'a']++;
			cnt[t[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++) if (cnt[i] & 1) ok = 0;
		if (ok) {
			cout << "Yes\n";
			for (int i = 0; i < n; i++) {
				ok = 0;
				if (s[i] == t[i]) continue;
				for (int j = i+1; j < n; j++) {
					if (s[i] == s[j]) {
						ans.push_back({j+1, i+1});
						ok = 1;
						swap(s[j], t[i]);
						break;
					}
				}
				if (ok) continue;
				for (int j = i+1; j < n; j++) {
					if (s[i] == t[j]) {
						ans.push_back({i+1, i+1});
						ans.push_back({i+1, j+1});
						swap(s[i], t[i]);
						swap(s[i], t[j]);
					}
				}
			}
			// cout << s << "\n";
			// cout << t << "\n";
			cout << ans.size() << "\n";
			for (auto [u, v] : ans) cout << u << " " << v << "\n";
		}
		else cout << "No\n";
	}
	return 0;
}
