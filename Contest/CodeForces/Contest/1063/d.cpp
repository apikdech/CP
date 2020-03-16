#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
const int MOD = 1000000007, INF = 2e9;
const int N = 2005;
char loc[N][N];
int x, y, n, m, r, c, ans = 0, a, b, aa, bb, kiri[N][N], kanan[N][N];
bool vis[N][N];
pair<int, int> dir[] = {mp(1, 0), mp(-1, 0), mp(0, 1), mp(0,-1)};

bool valid(int i, int j) { return (i > 0 && j > 0 && i <= n && j <= m); }

void bfs(int i, int j) {
	deque<pair<int, int>> q;
	q.push_front(mp(i, j));
	vis[i][j] = 1;
	kiri[i][j] = kanan[i][j] = 0;
	while(!q.empty()) {
		a = q.front().first;
		b = q.front().second;
		q.pop_front();
		for(int o = 0; o < 4; o++) {
			aa = a + dir[o].first;
			bb = b + dir[o].second;
			if (!valid(aa, bb)) continue;
			if (vis[aa][bb] || loc[aa][bb] == '*') continue;
			kanan[aa][bb] = kanan[a][b] + (dir[o].second == 1);
			kiri[aa][bb] = kiri[a][b] + (dir[o].second == -1);
			vis[aa][bb] = 1;
			if (o <= 1) q.push_front(mp(aa, bb));
			else q.push_back(mp(aa, bb));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(vis, 0, sizeof vis);
	cin >> n >> m >> r >> c >> x >> y;
	for (int i = 1; i < N; i++) for (int j = 1; j < N; j++) kiri[i][j] = kanan[i][j] = INF;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> loc[i][j];
	bfs(r, c);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (loc[i][j] == '*') continue;
			if (kiri[i][j] <= x && kanan[i][j] <= y) ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}