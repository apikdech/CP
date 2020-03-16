#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 4e5 + 5;
int a[N];

int main() {
	int n, cnt = 0, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[n+i] = a[i];
	}
	for (int i = 0; i < 2*n; i++) {
		if (a[i]) cnt++;
		else {
			ans = max(ans, cnt);
			cnt = 0;
		}
	}
	cout << ans << "\n";
	return 0;
}