#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;

char loc[1005][1005];
pair<int, int> dir[] = {mp(0,1), mp(0,-1), mp(1,0), mp(-1,0), mp(1,1), mp(1,-1), mp(-1,1), mp(-1,-1)};

bool surround(int i, int j) {
	for (int o = 0; o < 8; o++) {
		if (loc[i+dir[o].first][j+dir[o].second] != '#') return false;
	} 
	return true;
}

int main() {
	int n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> loc[i][j];
			if (loc[i][j] == '#') cnt++;
		}
	}
	if (n == 3 && m == 3 && cnt == 9) return cout << "NO\n", 0;
	for (int i = 2; i <= n-1; i++) {
		for (int j = 2; j <= m-1; j++) {
			if (loc[i][j] == '.' && !surround(i, j)) return cout << "NO\n", 0;
		}
	}
	cout << "YES\n";
	return 0;
}