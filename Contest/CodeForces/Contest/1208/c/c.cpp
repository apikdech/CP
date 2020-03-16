/*
 * Author: apikdech
 * Time: 22:36:39 25-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1005;
int a[N][N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, cnt = 0, ok = 0;
	cin >> n;
	cnt = 0;
	for (int i = 0; i < n; i += 4) {
		for (int j = 0; j < n; j += 4) {
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 4; l++) {
					a[i+k][j+l] = cnt;
					cnt++;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		// int tmp = 0;
		for (int j = 0; j < n; j++) {
			// tmp ^= a[j][i];
			cout << a[i][j] << " \n"[j == n-1];
		}
		// cout << i << " " << tmp << "\n";
	}
	return 0;
}
