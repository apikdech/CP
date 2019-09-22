/*
 * Author: apikdech
 * Time: 08:44:19 22-09-2019
 * Last Modified: 18:24:18 22-09-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e6 + 5;
int a[N];

int to_int(string s) {
	int ans = 0;
	for (char c : s) {
		ans *= 2;
		ans += c - '0';
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	string s = "";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int j = 0; j < 32; j++) {
		int nol = 0, satu = 0;
		for (int i = 0; i < n; i++) {
			bool tmp = (a[i] & (1 << j));
			if (tmp == 0) nol++;
			else satu++;
		}
		if (nol && satu) s += '1';
		else s += '0';
	}
	reverse(s.begin(), s.end());
	cout << to_int(s) << "\n";
	// cerr << "time = " << (int)(clock() * 1000. / CLOCKS_PER_SEC) << " ms\n";
	return 0;
}