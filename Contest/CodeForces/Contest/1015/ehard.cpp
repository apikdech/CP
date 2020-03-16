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

int main() {
	int n, m, cnt = 0, bintang = 0, ans = 0, last;
	vector< pair <int, pair<int, int> > > v;
	cin >> n >> m;
	char loc[1005][1005];
	bool visited[1005][1005];
	memset(visited, 0, sizeof visited);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> loc[i][j];
			if (loc[i][j] == '*') bintang++;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			bool flag = false;
			if (loc[i][j] == '*') {
				for (int k = 1; k <= 500; k++) {
					if (loc[i+k][j] == '*' && loc[i][j+k] == '*' && loc[i-k][j] == '*' && loc[i][j-k] == '*') {
						last = k;
						flag = true;
						if (!visited[i+k][j]) visited[i+k][j] = 1, ans++;
						if (!visited[i][j+k]) visited[i][j+k] = 1, ans++;
						if (!visited[i-k][j]) visited[i-k][j] = 1, ans++;
						if (!visited[i][j-k]) visited[i][j-k] = 1, ans++;
						if (!visited[i][j]) visited[i][j] = 1, ans++;
					}
					else break;
				}
				if (flag) {
					v.push_back(make_pair(i, make_pair(j, last)));
					cnt++;
				}
			}
		}
	}
	//cout << bintang << " " << ans << "\n";
	if (ans != bintang) return cout << "-1\n", 0;
	cout << cnt << "\n";
	for (int i = 0; i < cnt; i++) {
		cout << v[i].first << " " <<  v[i].second.first << " " << v[i].second.second << "\n";
	}
	return 0;
}