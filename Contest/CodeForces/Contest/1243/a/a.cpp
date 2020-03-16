/**
 * author:  apikdech
 * created: 07.11.2019 07:47:57
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e3 + 5;

int a[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a+n);
		for (int i = 0; i < n; i++) {
			ans = max(ans, min(n-i, a[i]));
		}
		cout << ans << "\n";
	}
	return 0;
}
