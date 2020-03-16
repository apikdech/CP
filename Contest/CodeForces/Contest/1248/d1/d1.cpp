/*
 * Author: apikdech
 * Time: 17:27:58 20-10-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

pair<int, int> ans;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, mx = -1;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			string x = s;
			swap(x[i], x[j]);
			// cout << x << " " << s << "\n";
			int sum = 0, cnt = 0, ok = 0, mn = 0;
			for (int k = 0; k < n; k++) {
				if (x[k] == '(') sum++;
				else sum--;
				mn = min(mn, sum);
			}
			sum = mn;
			for (int k = 0; k < 2*n; k++) {
				if (x[k % n] == '(') sum++;
				else sum--;
				if (sum == 0) {
					cnt++;
					if (k >= n - 1) break;
				}
			}
			if (cnt > mx) ans = {i+1, j+1}, mx = cnt;
		}
	}
	cout << mx << "\n";
	cout << ans.first << " " << ans.second << "\n";
	return 0;
}
