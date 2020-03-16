/*
⠀⠀⠀⠀⠀⢀⣀⣀⣀
⠀⠀⠀⠰⡿⠿⠛⠛⠻⠿⣷
⠀⠀⠀⠀⠀⠀⣀⣄⡀⠀⠀⠀⠀⢀⣀⣀⣤⣄⣀⡀
⠀⠀⠀⠀⠀⢸⣿⣿⣷⠀⠀⠀⠀⠛⠛⣿⣿⣿⡛⠿⠷
⠀⠀⠀⠀⠀⠘⠿⠿⠋⠀⠀⠀⠀⠀⠀⣿⣿⣿⠇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠁

⠀⠀⠀⠀⣿⣷⣄⠀⢶⣶⣷⣶⣶⣤⣀
⠀⠀⠀⠀⣿⣿⣿⠀⠀⠀⠀⠀⠈⠙⠻⠗
⠀⠀⠀⣰⣿⣿⣿⠀⠀⠀⠀⢀⣀⣠⣤⣴⣶⡄
⠀⣠⣾⣿⣿⣿⣥⣶⣶⣿⣿⣿⣿⣿⠿⠿⠛⠃
⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄
⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡁
⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁
⠀⠀⠛⢿⣿⣿⣿⣿⣿⣿⡿⠟
⠀⠀⠀⠀⠀⠉⠉⠉
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2005, INF = 1e9;
int rain[N], p[N], a, n, m, ans = INF, dp[N][N], v[N][N];

// int f(int pos, int umbrella) {
// 	if (pos == a) return 0;
// 	if (dp[pos][umbrella] != INF) return dp[pos][umbrella];
// 	if (p[umbrella]) dp[pos][umbrella] = p[umbrella] + f(pos+1, umbrella);
// 	if (p[pos]) dp[pos][umbrella] = min(dp[pos][umbrella], p[pos] + f(pos+1, pos));
// 	if (!rain[pos]) dp[pos][umbrella] = min(dp[pos][umbrella], f(pos+1, 0));
// 	return dp[pos][umbrella];
// }

int main() {
	cin >> a >> n >> m;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) dp[i][j] = INF;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		for (int j = l; j < r; j++) rain[j] = 1;
	}
	vector<pair<int, int>> umb(a + 1, {INF, -1});
	for (int i = 0; i < m; i++) {
		int x, px;
		cin >> x >> px;
		p[i] = px;
		umb[x] = min(umb[x], {px, i});
	}
	// ans = f(0, 0);
	dp[0][m] = 0;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i][j] == INF) continue;
			if (!rain[i]) dp[i+1][m] = min(dp[i+1][m], dp[i][j]);
			if (j < m) dp[i+1][j] = min(dp[i+1][j], dp[i][j] + p[j]);
			if (umb[i].first != INF) dp[i+1][umb[i].second] = min(dp[i+1][umb[i].second], dp[i][j] + umb[i].first);
		}
	}
	for (int i = 0; i <= m; i++) ans = min(ans, dp[a][i]);
	if (ans == INF) ans = -1;
	cout << ans << "\n";
	return 0;
}