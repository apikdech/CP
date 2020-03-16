/*
 * Author: apikdech
 * Time: 23:03:58 30-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
int n, ok = 1;
string s[2];

void cek(string ans) {
	for (int i = 0; i+1 < 3*n; i++) {
		if (ans[i] == s[0][0] && ans[i+1] == s[0][1] || ans[i] == s[1][0] && ans[i+1] == s[1][1]) return;
	}
	cout << "YES\n";
	cout << ans << "\n";
	exit(0);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	cin >> s[0] >> s[1];
	vector<char> ans;
	ans.push_back('a');
	ans.push_back('b');
	ans.push_back('c');
	do {
		string a = "", b = "";
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < n; j++) {
				a += ans[i];
			}
		}
		for (int i = 0; i < 3*n; i++) b += ans[i % 3];
		cek(a);
		cek(b);
	} while(next_permutation(ans.begin(), ans.end()));
	cout << "NO\n";
	return 0;
}
