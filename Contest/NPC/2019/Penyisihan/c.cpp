/*
 * Author: apikdech
 * Time: 08:44:33 22-09-2019
 * Last Modified: 18:25:16 22-09-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 15, M = 1e5 + 5;
int a[N][M];
vector<vector<int>> bit(N, vector<int>(M));

int n, m;
int sum(int x, int y) {
    int ret = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
            ret += bit[i][j];
    return ret;
}

void add(int x, int y, int delta) {
    for (int i = x; i < n; i = i | (i + 1))
        for (int j = y; j < m; j = j | (j + 1))
            bit[i][j] += delta;
}



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			a[i][j] = x;
			if (x) add(i, j, 1);
		}
	}
	int q;
	cin >> q;
	while(q--) {
		string s;
		cin >> s;
		if (s == "ON") cout << sum(n-1, m-1) << "\n";
		else if (s == "OFF") cout << n*m - sum(n-1, m-1) << "\n";
		else if (s == "TOGGLE") {
			int x, y;
			cin >> x >> y;
			x--, y--;
			if (a[x][y] == 0) {
				add(x, y, 1);
				a[x][y] = 1;
			} else {
				add(x, y, -1);
				a[x][y] = 0;
			}
			cout << "DONE\n";
		} else if (s == "COUNT") {
			int k, x, y;
			cin >> k >> x >> y;
			k--, x--, y--;
			int ans = sum(k, y) - sum(k, x-1);
			cout << ans << "\n";
		} else {
			int x, idx = 0;
			cin >> x;
			if (x > sum(n-1, m-1)) {
				cout << "-1\n";
				continue;
			}
			for (int i = 0; i < n; i++) {
				if (sum(i, m-1) >= x) break;
				idx = i+1;
			}
			// cout << "index = " << idx << "\n";
			int l = 0, r = m-1, ans = 1e9;
			if (idx > 0) x -= sum(idx-1, m-1);
			// cout << x << "\n";
			// cout << "TES\n";
			while(l <= r) {
				int mid = (l + r) >> 1;
				int tmp = sum(idx, mid) - sum(idx-1, mid);
				// cout << tmp << "\n";
				if (x <= tmp) {
					r = mid-1;
				} else {
					l = mid+1;
				}
				if (x == tmp) {
					ans = min(ans, mid);
					// cout << "TRUE" << " on pos" << mid << "\n";
				}
			}
			cout << idx+1 << " " <<  ans+1 << '\n';
		}
	}
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++) cout << bit[i][j] << " ";
	// 	cout << "\n";
	// }
	// cerr << "time = " << (int)(clock() * 1000. / CLOCKS_PER_SEC) << " ms\n";
	return 0;
}