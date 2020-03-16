#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	string s = "";
	for (int i = 0; i < 1005; i++) s+= '0';
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		for (int j = l; j <= r; j++) {
			if (s[j+1] == '0') s[j] = '1';
			else s[j] = '0';
		}
	}
	for (int i = 0; i < n; i++) cout << s[i];
	cout << "\n";
	return 0;
}