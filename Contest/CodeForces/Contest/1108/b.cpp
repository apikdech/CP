#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 1e4 + 5;
int cnt[N];

int main() {
	int n, a[130], ans = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	sort(a, a+n, greater<int>());
	for (int i = 0; i < n; i++) {
		if (a[0] % a[i] != 0) ans = max(ans, a[i]);
		else if (cnt[a[i]] == 2) ans = max(ans, a[i]);
	}
	cout << a[0] << " " << ans << "\n";
	return 0;
}