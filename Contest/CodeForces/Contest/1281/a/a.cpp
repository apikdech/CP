/**
 * author:  apikdech
 * created: 15.12.2019 12:06:48
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
		string s;
		int ok = 0;
		cin >> s;
		int la = s.length() - 1;
		if (s.length() >= 2 && s[la-1] == 'p' && s[la] == 'o') ok = 1;
		else if (s.length() >= 4 && s[la-3] == 'd' && s[la-2] == 'e' && s[la-1] == 's' && s[la] == 'u') ok = 2;
		else if (s.length() >= 4 && s[la-3] == 'm' && s[la-2] == 'a' && s[la-1] == 's' && s[la] == 'u') ok = 2;
		else if (s.length() >= 5 && s[la-4] == 'm' && s[la-3] == 'n' && s[la-2] == 'i' && s[la-1] == 'd' && s[la] == 'a') ok = 3;
		if (ok == 1) cout << "FILIPINO\n";
		else if (ok == 2) cout << "JAPANESE\n";
		else if (ok == 3) cout << "KOREAN\n";
	}
	return 0;
}
