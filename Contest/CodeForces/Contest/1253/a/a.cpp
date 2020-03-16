/**
 * author:  apikdech
 * created: 16.11.2019 21:38:03
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
int a[N], b[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, ok = 1, st = N, lst = -1, x = -1;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			b[i] -= a[i];
			if (b[i] < 0) ok = 0;
			else if (b[i] > 0) {
				st = min(i, st);
				lst = max(i, st);
				x = b[i];
			}
		}
		if (x != -1) 
			for (int i = st; i <= lst; i++) {
				if (b[i] != x) ok = 0;
			}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
