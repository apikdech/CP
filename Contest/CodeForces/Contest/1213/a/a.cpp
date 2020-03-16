/*
 * Author: apikdech
 * Time: 21:37:23 30-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 105;
int a[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 1000;
	for (int i = 0; i < n; i++) {
		for (int j = -2; j <= 2; j++) {
			int tmp = 0;
			if (j == 0) continue;
			for (int k = 0; k < n; k++) {
				// if (i == k) continue;
				tmp += abs(a[i] + j - a[k]) % 2;
			}
			ans = min(ans, tmp);
		}
	}
	cout << ans << "\n";
	return 0;
}
