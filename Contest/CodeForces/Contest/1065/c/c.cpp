#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 2e5 + 5;
int a[N], mn = N, h[N], mx = -1, cnt[N];

int main() {
	ll n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
		mn = min(a[i], mn);
		mx = max(mx, a[i]);
	}
	if (cnt[mn] == n) return cout << "0\n", 0;
	sort(a, a+n);
	for (int i = mn; i <= mx; i++) {
		int idx = lower_bound(a, a+n, i) - a;
		idx = n-idx;
		h[i] = idx;
		// cout << i << " " << h[i] << "\n";
	}
	ll temp = 0, ans = 0;
	while(mx != mn) {
		if (temp + h[mx] <= k) temp += h[mx];
		else {
			temp = h[mx];
			ans++;
		}
		mx--;
	}
	cout << ans+1 << "\n";
	return 0;
}