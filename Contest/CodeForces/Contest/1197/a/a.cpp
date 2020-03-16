/*
 * Author: apikdech
 * Time: 21:34:59 22-07-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
int a[N], l[N], r[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		memset(a, 0, sizeof a);
		int n, ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			a[x]++;
		}
		for (int i = 1; i <= 1e5; i++) {
			l[i] = l[i-1] + a[i];
		}
		for (int i = 1e5; i > 0; i--) {
			r[i] = r[i+1] + a[i];
		}
		for (int i = 1; i < 1e5; i++) {
			if (r[i+1] >= 2 && l[i] + r[i+1] - 2 >= i) ans = i;
		}
		cout << ans << "\n";
	}
	return 0;
}
