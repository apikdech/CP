/*
 * Author: apikdech
 * Time: 08:27:59 19-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e3 + 5;
ll a[N][N], ans[N], g = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, ok = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;
		int k = (j + 1) % n;
		ans[i] = a[i][j] * a[i][k] / a[j][k];
		ans[i] = sqrt(ans[i]);
		cout << ans[i] << " \n"[i==n-1];
	}
	return 0;
}
