/*
 * Author: apikdech
 * Time: 21:58:57 13-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1005;
int a[N], vis[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		map<int, int> cnt;
		int n, area = 0, ok = 1;
		cin >> n;
		n <<= 2;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cnt[a[i]]++;
		}
		sort(a, a+n);
		area = a[0] * a[n-1];
		// cout << a[0] << " " << a[n-1] << "\n";
		// cout << area << "\n";
		for (int i = 0; i < n; i++) {
			int x = area/a[i];
			if (x * a[i] == area && x == a[i]) {
				if (cnt[x] % 4 != 0) ok = 0;
			}
			if (cnt[a[i]] % 2 != 0 || cnt[x] % 2 != 0 || x * a[i] != area || cnt[x] == 0 || cnt[a[i]] != cnt[x]) ok = 0;
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
