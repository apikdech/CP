/*
 * Author: apikdech
 * Time: 10:23:26 07-10-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int a[30], b[30];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s, t;
		int ok = 0;
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		cin >> s >> t;
		for (char c : s) {
			a[c - 'a']++;
		}
		for (char c : t) {
			b[c - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (a[i] && b[i]) ok = 1;
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
