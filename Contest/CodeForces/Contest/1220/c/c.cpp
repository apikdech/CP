/*
 * Author: apikdech
 * Time: 10:46:41 19-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int ok = 0;
	string s;
	cin >> s;
	char mn = s[0];
	for (char c : s) {
		if (c <= mn) {
			mn = c;
			cout << "Mike\n";
		} else cout << "Ann\n";
	}
	return 0;
}
