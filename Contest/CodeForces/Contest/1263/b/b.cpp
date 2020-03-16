/**
 * author:  apikdech
 * created: 29.11.2019 21:51:11
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 15;

bool vis[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, res = 0;
		memset(vis, 0, sizeof vis);
		map<string, int> m;
		vector<string> ans;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			m[s]++;
			ans.push_back(s);
		}
		for (auto [pin, cnt] : m) {
			res += cnt - 1;
			if (cnt == 1) {
				for (int i = 0; i < n; i++) {
					if (!vis[i] && pin == ans[i]) {
						vis[i] = 1;
						break;
					}
				}
			} else {
				for (int i = 0; i < n; i++) {
					if (!vis[i] && ans[i] == pin) {
						vis[i] = 1;
						break;
					}
				}
				cnt--;
				m[pin]--;
				while(cnt--) {
					string newpin;
					for (int i = 1; i <= 10; i++) {
						newpin = pin;
						int num = newpin[0] - '0';
						num = (num + i) % 10;
						newpin[0] = num + '0';
						if (m.count(newpin) == 0) break;
					}
					// cout << newpin << "\n";
					for (int i = 0; i < n; i++) {
						if (!vis[i] && ans[i] == pin) {
							ans[i] = newpin;
							m[newpin]++;
							m[pin]--;
							vis[i] = 1;
							break;
						}
					}
				}
			}
		}
		cout << res << "\n";
		for (int i = 0; i < n; i++) cout << ans[i] << "\n";
	}
	return 0;
}
