#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ll n, m, k, l, ans = 0;
	cin >> n >> m >> k >> l;
	if (n < m || n < l + k) return cout << "-1\n", 0;
	ll cnt = (l + k + m - 1)/m;
	if (cnt * m > n) return cout << "-1\n", 0;
	else cout << cnt << "\n";
	return 0;
}