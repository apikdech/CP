#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 505;
int a[N][N], b[N][N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> b[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] != b[i][j]) {
				if (i == n || j == m) return cout << "No\n", 0;
				a[i][j] ^= 1;
				a[i+1][j] ^= 1;
				a[i][j+1] ^= 1;
				a[i+1][j+1] ^= 1;
			}
		}
	}
	cout << "Yes\n";
	return 0;
}
