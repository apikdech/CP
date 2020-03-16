/*
 * Author: apikdech
 * Time: 14:54:04 11-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e3 + 5;
int cnt[N][30];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			cnt[j][s[j] - 'A']++;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, mx = 0;
		cin >> x;
		for (int j = 0; j < 26; j++) {
			mx = max(mx, cnt[i][j]);
		}
		ans += x*mx;
	}
	cout << ans << "\n";
	return 0;
}
