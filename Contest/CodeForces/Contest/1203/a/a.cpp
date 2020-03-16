/*
 * Author: apikdech
 * Time: 21:38:54 13-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 500;
int a[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		int n, s, ok = 1, x = 0, y = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n-1; i++) {
			if (a[i] < a[i+1] && a[i+1] - a[i] == 1) x++;
			else if (a[i] > a[i+1] && a[i] - a[i+1] == n-1) x++;
		}
		for (int i = 0; i < n-1; i++) {
			if (a[i] > a[i+1] && a[i] - a[i+1] == 1) y++;
			else if (a[i] < a[i+1] && a[i+1] - a[i] == n-1) y++;
		}
		if (x == n-1 || y == n-1) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
