/**
 * author:  apikdech
 * created: 12.12.2019 20:44:48
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 30;

int vis[N];

ll calc(ll x) {
	return (x * (x+1))/2;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	for (int i = 0; i < k; i++) {
		char c;
		cin >> c;
		vis[c - 'a']++;
	}
	ll cnt = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if (!vis[s[i] - 'a']) ans += calc(cnt), cnt = 0;
		else cnt++;
	}
	ans += calc(cnt);
	cout << ans << "\n";
	return 0;
}
