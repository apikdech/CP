/*
 * Author: apikdech
 * Time: 21:39:00 22-10-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int a[105];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		int n, ok = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a+n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				if (a[i] - a[j] == 1) ok = 1;
			}
		}
		if (ok) cout << 2 << "\n";
		else cout << 1 << "\n";
	}
	return 0;
}
