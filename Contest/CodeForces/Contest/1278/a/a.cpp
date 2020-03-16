/**
 * author:  apikdech
 * created: 19.12.2019 21:36:47
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 105;

int cnt[N], sum[N][30];

bool calc(int fi, int la) {
	for (int i = 0; i < 26; i++) {
		if (sum[la][i] - sum[fi][i] != cnt[i]) return 0;
		// else if (sum[la][i] != cnt[i]) return 0;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		memset(cnt, 0, sizeof cnt);
		memset(sum, 0, sizeof sum);
		string s, h;
		int ok = 0;
		cin >> s >> h;
		for (char c : s) {
			cnt[c - 'a']++;
		}
		h = ' ' + h;
		for (int i = 1; i < h.length(); i++) {
			for (int j = 0; j < 26; j++) {
				if (h[i] - 'a' == j) sum[i][j] = sum[i-1][j] + 1;
				else sum[i][j] = sum[i-1][j];
			}
		}
		if (h.length() < s.length()) ok = 0;
		else 
			for (int i = s.length(); i < h.length(); i++) {
				ok |= calc(i - s.length(), i);
			}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
