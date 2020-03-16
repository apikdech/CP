#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, cnt = 0;
	cin >> n;
	int a[n+5], ans = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n-1; i++) {
		if (2*a[i] >= a[i+1]) cnt++;
		else cnt = 0;
		if (cnt >= ans) ans = cnt;
	}
	cout << ans+1 << "\n";
	return 0;
}