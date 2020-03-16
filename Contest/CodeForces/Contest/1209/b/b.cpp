/*
 * Author: apikdech
 * Time: 20:13:59 14-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 105;
int a[N], b[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, ans = 0;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i < n; i++) {
		ans += s[i] - '0';
	}
	// cout << ans << "\n";

	for (int i = 1; i < 1000; i++) {
		for (int j = 0; j < n; j++) {
			if (i < b[j]) continue;
			if (((i - b[j]) % a[j]) == 0) {
				if (s[j] == '1') s[j] = '0';
				else s[j] = '1';
			}
		}
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			cnt += s[j] - '0';
		}
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
	return 0;
}
