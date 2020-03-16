#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int n, x, ans = 0;
	cin >> n;
	char s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		x = s - '0';
		if (x%2 == 0) ans += i;
	}
	cout << ans << "\n";
	return 0;
}