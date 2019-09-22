/*
 * Author: apikdech
 * Time: 06:59:46 06-09-2019
 * Last Modified: 07:02:40 06-09-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
string w[] = {"ei", "bi", "si", "di", "i", "ef", "dei", "eitf", "ai", "djei", "kei", "el", "em", "en", "ou", "pi", "kiu", "ar", "es", "ti", "ju", "vi", "dabelju", "eks", "wai", "zi"};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;
	getline(cin, s);
	for (char c : s) {
		if (c >= 'a' && c <= 'z') cout << w[c-'a'];
		else cout << c;
	}
	cout << "\n";
	// cerr << "time = " << (int)(clock() * 1000. / CLOCKS_PER_SEC) << " ms\n";
	return 0;
}