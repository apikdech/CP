/*
 * Author: apikdech
 * Time: 21:52:05 25-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2005;
int a[N];

int main() {
	// ios::sync_with_stdio(0); cin.tie(0);
	int n, y = 0, ans = N;
	cin >> n;
	unordered_map<int, int> m;
	unordered_map<int, bool> v;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m[a[i]]++;
		if (!v[a[i]] && m[a[i]] > 1) y++, v[a[i]] = 1;
	}
	for (int i = n; i >= 0; i--) {
		unordered_map<int, int> cnt = m;
		unordered_map<int, bool> vis = v;
		int x = y;
		for (int j = 0; j < i; j++) {
			cnt[a[j]]--;
			if (cnt[a[j]] == 1) x--, vis[a[j]] = 0;
			else if (cnt[a[j]] > 1 && !vis[a[j]]) x++, vis[a[j]] = 1;
		}
		if (x == 0) ans = min(ans, i);
		for (int j = i; j < n; j++) {
			cnt[a[j-i]]++;
			if (cnt[a[j-i]] > 1 && !vis[a[j-i]]) x++, vis[a[j-i]] = 1;
			cnt[a[j]]--;
			if (cnt[a[j]] == 1) x--, vis[a[j]] = 0;
			if (x == 0) ans = min(ans, i);
		}
	}
	cout << ans << "\n";
	return 0;
}
