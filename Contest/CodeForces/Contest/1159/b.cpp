#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 3e5 + 5;
ll a[N], ans = 1e9 + 5;

int main() {
	int n, id = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ll tmp = max(i - 0, n - 1 - i);
		ans = min(a[i]/tmp, ans);
	}
	cout << ans << "\n";
	return 0;
}