#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int a[3], ans = 0;
	cin >> a[0] >> a[1] >> a[2];
	if (a[0] + a[1] > a[2] && a[0] + a[2] > a[1] && a[1] + a[2] > a[0]) cout << "0\n";
	else {
		sort(a, a+3);
		ans = a[2] - (a[0] + a[1]);
		ans++;
		cout << ans << "\n";
	}
	return 0;
}