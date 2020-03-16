/*
 * Author: apikdech
 * Time: 07:05:39 20-06-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;
int a[N], cnt[105], sum = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, ans;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		sum += a[i];
		ans = 0;
		if (sum <= m) cout << ans << " \n"[i==n-1];
		else {
			int tsum = sum;
			for (int j = 100; j >= 1; j--) {
				if (tsum - cnt[j]*j > m) tsum -= cnt[j] * j, ans += cnt[j];
				else {
					ans += (tsum-m+j-1)/j;
					break;
				}
			}
			cout << ans << " \n"[i==n-1];
		}
		cnt[a[i]]++;
	}
	return 0;
}
