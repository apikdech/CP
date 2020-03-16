/*
 * Author: apikdech
 * Time: 08:22:04 22-07-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 3005, M = 1e7;
int n, m, a, b;
ll g[M], h[N][N], x, y, z, c[N][N], ans = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> a >> b;
	cin >> g[0] >> x >> y >> z;
	for (int i = 1; i <= n*m + m; i++) {
		g[i] = ((g[i-1]*x)%z + y) % z;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			h[i][j] = g[(i-1)*m + j-1];
		}
	}
	for (int i = 1; i <= n; i++) {
		deque<int> dq;
		for (int j = 1; j <= b; j++) {
			while(!dq.empty() and h[i][j] <= h[i][dq.back()]) dq.pop_back();
			dq.push_back(j);
		}
		for (int j = b+1; j <= m; j++) {
			c[i][j-b] = h[i][dq.front()];
			// cout << c[i][j-b] << " ";
			while(!dq.empty() and dq.front() <= j-b) dq.pop_front();
			while(!dq.empty() and h[i][j] <= h[i][dq.back()]) dq.pop_back();
			dq.push_back(j);
		}
		c[i][m-b+1] = h[i][dq.front()];
		// cout << c[i][m-b+1] << "\n";
	}
	for (int j = 1; j <= m - b + 1; j++) {
		deque<int> dq;
		for (int i = 1; i <= a; i++) {
			while(!dq.empty() and c[i][j] <= c[dq.back()][j]) dq.pop_back();
			dq.push_back(i);
		}
		for (int i = a+1; i <= n; i++) {
			// r[i-a][j] = c[dq.front()][j];
			ans += c[dq.front()][j];
			// cout << r[i-a][j] << " ";
			while(!dq.empty() and dq.front() <= i-a) dq.pop_front();
			while(!dq.empty() and c[i][j] <= c[dq.back()][j]) dq.pop_back();
			dq.push_back(i);
		}
		// r[n-a+1][j] = c[dq.front()][j];
		ans += c[dq.front()][j];
		// cout << r[n-a+1][j] << "\n";
	}
	cout << ans << "\n";
	return 0;
}