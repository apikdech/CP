/**
 * author:  apikdech
 * created: 04.11.2019 20:50:56
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e3 + 5;
int c[N], sum = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, d;
	cin >> n >> m >> d;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		sum += c[i];
	}
	if (sum + (m+1)*(d-1) >= n) {
		cout << "YES\n";
		int x = n - sum;
		vector<int> a(m+1), ans;
		for (int i = 0; i <= m; i++) {
			a[i] = min(d-1, x);
			x -= a[i];
		}
		for (int i = 0; i < a[0]; i++) ans.push_back(0);
		for (int i = 1; i <= m; i++) {
			for (int j = 0; j < c[i]; j++) ans.push_back(i);
			for (int j = 0; j < a[i]; j++) ans.push_back(0);
		}
		for (int it : ans) cout << it << " ";
	}
	else cout << "NO\n";
	return 0;
}
