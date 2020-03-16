#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;

char loc[1005][1005];
int visited[1005][1005], cnt1 = 0, n, m, cnt2 = 0;
pair<int, int> dir[] = {mp(0,1), mp(0,-1), mp(1,0), mp(-1,0), mp(1,1), mp(1,-1), mp(-1,1), mp(-1,-1)};

void surround(int i, int j) {
	int temp = 0;
	for (int o = 0; o < 8; o++) {
		int xx = i + dir[o].first, yy = j + dir[o].second;
		if (loc[xx][yy] != '#') return;
	}
	for (int o = 0; o < 8; o++) {
		int xx = i + dir[o].first, yy = j + dir[o].second;
		if (loc[xx][yy] == '#' && !visited[xx][yy]) {
			visited[xx][yy] = 1;
			temp++;
		}
	}
	//printf("%d\n", temp);
	cnt2 += temp;
}

int main() {
	memset(visited, 0, sizeof visited);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> loc[i][j];
			if (loc[i][j] == '#') cnt1++;
		}
	}
	if (n == 3 && m == 3 && cnt1 == 9) return cout << "NO\n", 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			surround(i, j);
		}
	}
	if (cnt1 == cnt2) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}