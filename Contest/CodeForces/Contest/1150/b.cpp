#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
char a[55][55];

int main() {
	int n, ok = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == '.') {
				if (a[i+1][j] == '.' && a[i][j+1] == '.' && a[i-1][j] == '.' && a[i][j-1] == '.') a[i+1][j] = a[i-1][j] = a[i][j+1] = a[i][j-1] = a[i][j] = '#';
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == '.') ok = 0;
		}
	}
	if (ok) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}