#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int n, k, x, y, xx, yy, kk;
bool vis[2005][2005];
char loc[2005][2005], dist[2005][2005];
vector<string> ans;
pair<int, int> o[] = {mp(0, 1), mp(1, 0)};
pair<int, int> p[2005][2005];

bool valid(int i, int j) {
	return (i > 0 && j > 0 && i <= n && j <= n);
}

void bfs() {
	queue<pair<int, pair<int, int>>> q;
	if (loc[1][1] != 'a' && k > 0) {
		dist[1][1] = 'a';
		k--;
	}
	else dist[1][1] = loc[1][1];
	q.push(mp(0, mp(0, k)));
	vis[1][1] = 1;
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second.first;
		kk = q.front().second.second;
		q.pop();
		for (auto dir : o) {
			xx = x + dir.first;
			yy = y + dir.second;
			if (vis[xx][yy]) continue;
			if (!valid(xx, yy)) continue;
			if (kk > 0 && loc[xx][yy] != 'a' && dist[x][y] + 'a' < dist[xx][yy]) {
				dist[xx][yy] = dist[x][y] + 'a';
				q.push(mp(xx, mp(yy, kk-1)));
			} else if (loc[xx][yy] == 'a' && dist[x][y] + 'a' < dist[xx][yy]) {
				dist[xx][yy] = dist[x][y] + 'a';
				q.push(mp(xx, mp(yy, kk)));
			} else if (dist[x][y] + loc[xx][yy] < dist[xx][yy]) {
				dist[xx][yy] = dist[x][y] + loc[xx][yy];
				q.push(mp(xx, mp(yy, kk)));
			}
			vis[xx][yy] = 1;
		}
	}
}

int main() {
	memset(vis, 0, sizeof vis);
	string temp = ("z" + 10);
	for (int i = 0; i <= 2000; i++) {
		for (int j = 0; j <= 2000; j++) {
			dist[i][j] = temp;
		}
	}
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> loc[i][j];
		}
	}
	bfs();
	cout << dist[n][n] << "\n";
	// cout << "0n";
	return 0;
}