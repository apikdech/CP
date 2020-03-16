/**
 * author:  apikdech
 * created: 24.12.2019 21:37:30
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int a, b, c, r, x, y;
		cin >> a >> b >> c >> r;
		if (a > b) swap(a, b);
		if (a <= c && c <= b) {
			x = max(c-r, a);
			y = min(c+r, b);
			cout << max(0, x-a) + max(0, b-y) << "\n";
		} else if (c >= b) {
			b = min(c-r, b);
			cout << max(0, b-a) << "\n";
		} else {
			a = max(a, c+r);
			cout << max(0, b-a) << "\n";
		}
	}
	return 0;
}
