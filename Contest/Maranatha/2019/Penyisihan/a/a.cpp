/*
 * Author: apikdech
 * Time: 09:53:50 07-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
string a = " .--. ";
string b[2] = {"|oo  |", "|  oo|"};
string c = "|/\\/\\|";

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < 3*n; i++) {
		for (int j = 0; j < n; j++) {
			if (i % 3 == 0) cout << a;
			else if (i % 3 == 1) cout << b[i%2];
			else cout << c;
		}
		cout << "\n";
	}
	return 0;
}
