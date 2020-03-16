/*
 * Author: apikdech
 * Time: 21:09:41 27-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		string s, rev;
		cin >> s;
		rev = s;
		reverse(rev.begin(), rev.end());
		if (s != rev) cout << s << "\n";
		else {
			set<int> S;
			for (char c : s) {
				S.insert(c - 'a');
			}
			if (S.size() == 1) cout << "-1\n";
			else {
				sort(s.begin(), s.end());
				cout << s << "\n";
			}
		}
	}
	return 0;
}