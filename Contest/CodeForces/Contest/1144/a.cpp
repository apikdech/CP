#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int cnt[30];

int main() {
	int n;
	cin >> n;
	while(n--) {
		memset(cnt, 0, sizeof cnt);
		string s;
		bool ans = 1;
		int mn = 30, mx = -1;
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			cnt[s[i] - 'a']++;
			mn = min(mn, s[i] - 'a');
			mx = max(mx, s[i] - 'a');
			if (cnt[s[i] - 'a'] > 1) ans = 0;
		}
		for (int i = mn; i <= mx; i++) {
			if (!cnt[i]) ans = 0;
		}
		if (ans) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}