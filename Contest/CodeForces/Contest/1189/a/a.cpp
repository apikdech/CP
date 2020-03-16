/*
 * Author: apikdech
 * Time: 22:08:01 05-07-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, a = 0, b = 0;
	cin >> n;
	string s;
	cin >> s;
	for (auto c : s) {
		if (c == '0') a++;
		else b++;
	}
	if (a != b) cout << "1\n" << s << "\n";
	else {
		cout << "2\n";
		cout << s[0] << " ";
		for (int i = 1; i < s.length(); i++) cout << s[i];
		cout << "\n";
	}
	return 0;
}
