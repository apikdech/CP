/*
 * Author: apikdech
 * Time: 22:31:16 30-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 55, M = 2e5 + 5;
int a[N], cnt[M], mx = 0;

int dist(int x, int num) {
	int res = 0;
	while(num != x && num > 0) num /= 2, res++;
	if (num == x) return res;
	return -1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k, ans = M;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
		mx = max(mx, a[i]);
	}
	sort(a, a+n);
	for (int i = 0; i <= mx; i++) {
		int tmp = 0, c = 0;
		for (int j = 0; j < n; j++) {
			if (i > a[j]) continue;
			int t = dist(i, a[j]);
			if (t != -1) tmp += t, c++;
			if (c >= k) {
				ans = min(ans, tmp);
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
