/**
 * author:  apikdech
 * created: 12.12.2019 20:53:28
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		string s;
		int u = 0, d = 0, l = 0, r = 0, ok = 1;
		cin >> s;
		for (char c : s) {
			if (c == 'U') u++;
			else if (c == 'D') d++;
			else if (c == 'L') l++;
			else r++;
		}
		if (l == 0 || r == 0) {
			if (u >= 1 && d >= 1) {
				cout << "2\n";
				cout << "UD\n";
			} else cout << "0\n";
		} else if (u == 0 || d == 0) {
			if (l >= 1 && r >= 1) {
				cout << "2\n";
				cout << "LR\n";
			} else {
				cout << "0\n";
			}
		} else {
			int x = min(u, d);
			int y = min(l, r);
			cout << x + x + y + y << "\n";
			for (int i = 0; i < x; i++) {
				cout << "U";
			}
			for (int i = 0; i < y; i++) {
				cout << "R";
			}
			for (int i = 0; i < x; i++) {
				cout << "D";
			}
			for (int i = 0; i < y; i++) {
				cout << "L";
			}
			cout << "\n";
		}
	}
	return 0;
}
