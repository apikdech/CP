/*
 * Author: apikdech
 * Time: 22:49:42 20-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 105;
int sum[N], a[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		memset(sum, 0, sizeof sum);
		int n, ok = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sort(a, a+n);
		for (int i = 1; i <= n; i++) {
			sum[i] = sum[i-1] + a[i];
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= i; j++) {
				if (sum[i] - sum[j] == 2048) ok = 1;
			}
		}
		if (ok ) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
