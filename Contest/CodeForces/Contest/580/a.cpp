#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, last = -1, cnt = 0, ans = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x >= last) cnt++;
		else cnt = 1;
		last = x;
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
	return 0;
}