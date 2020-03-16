#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int n, k;
	string s = "1", ans = "";
	cin >> n >> k;
	for (int i = 0; i < (n-k)/2; i++) {
		s = "0" + s;
	}
	for (int i = 0; i < n; i++) {
		ans += s[i % ((n-k)/2 + 1)];
	}
	cout << ans << "\n";
	return 0;
}