#include <bits/stdc++.h>
using namespace std;

int cnt[105];

int main() {
	int n, a[105], ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
		ans = max(ans, cnt[a[i]]);
	}
	cout << ans << "\n";
	return 0;
}