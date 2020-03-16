/*
 * Author: apikdech
 * Time: 23:09:57 05-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

ll to_int(string s) {
	ll res = 0;
	for (int i = 0; i < s.length(); i++) {
		res *= 2;
		res += s[i] - '0';
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	cout << to_int(s) << "\n";
	return 0;
}
