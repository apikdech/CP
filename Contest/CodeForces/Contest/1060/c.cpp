#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2005;
ll a[N], b[N], sa[N], sb[N], x;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i-1];
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		b[i] += b[i-1];
	}
	cin >> x;
	for (int i = 1; i <= max(n, m); i++) sa[i] = sb[i] = 1e9;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i + 1; j++) { //mencari nilai paling kecil dari segment i elemen
			sa[i] = min(sa[i], a[i+j-1] - a[j-1]);
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m - i + 1; j++) {
			sb[i] = min(sb[i], b[i+j-1] - b[j-1]);
		}
	}
	cout << "\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (sa[i]*sb[j] <= x) ans = max(ans, i*j);
		}
	}
	cout << ans << "\n";
	return 0;
}