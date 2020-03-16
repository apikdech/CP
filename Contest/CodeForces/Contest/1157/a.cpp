#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int n, ans = 0, vis = 0;
	map<int, bool> m;
	cin >> n;
	if (n % 10 == 0) ans++, n++;
	while(1) {
		while(n % 10 == 0) n /= 10;
		if (m[n] && n > 1) n++;
		else if (n > 1) m[n] = 1, n++, ans++;
		else if (!vis && n == 1) vis = 1, n++, ans++;
		else if (vis && n == 1) break;
	}
	cout << ans << "\n";
	return 0;
}