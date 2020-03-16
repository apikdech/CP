/**
 * author:  apikdech
 * created: 27.11.2019 20:55:48
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	while(n--) {
		ll c, sum, sisa, ans = 0, cnt = 0, add;
		cin >> c >> sum;
		add = sum/c;
		cnt = sum % c;
		c -= cnt;
		while(cnt--) {
			ans += (add + 1)*(add+1);
		}
		while(c--) {
			ans += add*add;
		}
		cout << ans << "\n";

	}
	return 0;
}
