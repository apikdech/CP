#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 1005;
int f[N], l[N], t[N][N], cntf[N], cntl[N];

int main() {
	int n, m, h;
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		cin >> f[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> t[i][j];
		}
	}
	for (int i = 0; i < min(n, m); i++) {
		if (f[i] == l[min(n, m) - i - 1] && t[min(n,m) - i - 1][i]) t[min(n, m) - i - 1][i] = f[i], cntf[i] = 1, cntl[min(n, m) - i - 1] = 1;
	}
	for (int j = m-1; j >= 0; j--) {
		if (cntf[j] == 1) continue;
		for (int i = n-1; i >= 0; i--) {
			if (f[j] > l[i]) continue;
			if(t[i][j]) t[i][j] = f[j], cntf[j]++;
		}
	}
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++) {
	// 		cout << t[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	for (int i = 0; i < n; i++) {
		if (cntl[i] == 1) continue;
		for (int j = 0; j < m; j++) {
			if (l[i] > f[j]) continue;
			if (t[i][j]) t[i][j] = l[i], cntf[j]--;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << t[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}