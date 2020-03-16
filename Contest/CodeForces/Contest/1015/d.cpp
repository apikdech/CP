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
	ll n, k, s, cnt, dist1, dist2, temp = 1;
	cin >> n >> k >> s;
	if (s > k*(n-1) || k > s) return cout << "NO\n", 0;
	cout << "YES\n";
	cnt = (s - (s/k)*k);
	dist1 = ceil(s*1.0/k);
	dist2 = s/k;
	//cout << dist1 << " " << dist2 << "\n" << cnt << "\n";
	for (int i = 0; i < k; i++) {
		if (cnt) {
			if (i & 1) temp -= dist1;
			else temp += dist1;
			cnt--;
		}
		else {
			if (i & 1) temp -= dist2;
			else temp += dist2;
		}
		cout << temp << " ";
	}
	return 0;
}