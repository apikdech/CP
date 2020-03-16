/**
 * author:  apikdech
 * created: 01.11.2019 09:13:26
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, p;
	cin >> n >> p;
	for (int i = 1; i < 32; i++) {
		int x = n, cnt = 0;
		x -= i * p;
		if (x < i) continue;
		cnt = __builtin_popcount(x);
		// while(x) {
		// 	x -= (1 << (31 - __builtin_clz(x)));
		// 	cnt++;
		// }
		if (cnt <= i) return cout << i << "\n", 0;
	}
	cout << "-1\n";
	return 0;
}
