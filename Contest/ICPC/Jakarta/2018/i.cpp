/*
 * Author: apikdech
 * Time: 10:57:22 03-09-2019
 * Last Modified: 11:06:02 03-09-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
bool ok[N], x[N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "LIE") x[i] = 0;
		else x[i] = 1;
	}
	reverse(x, x+n);
	for (int i = 0; i < n; i++) {
		if (i == 0) ok[i+1] = x[i];
		else if (ok[i]) ok[i+1] = x[i];
		else ok[i+1] = !(ok[i] ^ x[i]);
	}
	if (ok[n]) cout << "TRUTH\n";
	else cout << "LIE\n";
	// cerr << "time = " << (int)(clock() * 1000. / CLOCKS_PER_SEC) << " ms\n";
	return 0;
}