/**
 * author:  apikdech
 * created: 21.11.2019 23:10:32
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 105;

string words = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
vector<char> word;
char loc[N][N], ans[N][N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for (char c : words) word.push_back(c);
	int t;
	cin >> t;
	while(t--) {
		int r, c, k, rice = 0;
		cin >> r >> c >> k;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> loc[i][j];
				if (loc[i][j] == 'R') rice++;
			}
		}
		int cnt = 0, jatah = (rice+k-1)/k, idx = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (i & 1) {
					ans[i][c-j-1] = word[idx];
					if (loc[i][c-j-1] == 'R') cnt++;
				}
				else {
					ans[i][j] = word[idx];
					if (loc[i][j] == 'R') cnt++;
				}
				if (cnt == jatah) {
					rice -= jatah, cnt = 0, k--, jatah = (rice+k-1)/max(k, 1);
					if (rice != 0) idx++;
				}
			}
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << ans[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}
