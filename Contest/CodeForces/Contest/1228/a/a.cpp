/*
 * Author: apikdech
 * Time: 20:13:36 30-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

string tostring(int x) {
	string res = "";
	while(x) {
		res = (char)((x % 10) + '0') + res;
		x /= 10;
	}
	return res;
}

bool cek(string x) {
	sort(x.begin(), x.end());
	for (int i = 1; i < x.length(); i++) {
		if (x[i] == x[i-1]) return 0;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int l, r;
	cin >> l >> r;
	for (int i = l; i <= r; i++) {
		string x = tostring(i);
		if (cek(x)) return cout << x << "\n", 0;
	}
	cout << "-1\n";
	return 0;
}
