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
	int k;
	bool flag = false;
	cin >> k;
	map<int, int> m;
	map<int, pair<int, int>> idx;
	for (int seq = 0; seq < k; seq++) {
		int n, sum = 0;
		cin >> n;
		int a[n+10];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		set<int> s;
		for (int i = 0; i < n; i++) {
			if (!s.count(a[i])) {
				s.insert(a[i]);
				m[sum-a[i]]++;
				if (m[sum-a[i]] == 2) {
					cout << "YES\n";
					cout << idx[sum-a[i]].second+1 << " " << idx[sum-a[i]].first+1 << "\n"; 
					cout << seq+1 << " " << i+1 << "\n";
					return 0;
				}
				idx[sum-a[i]].second = seq;
				idx[sum-a[i]].first = i;
			}
		}
	}
	cout << "NO\n";
	return 0;
}