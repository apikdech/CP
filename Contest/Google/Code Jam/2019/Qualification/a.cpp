#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		string s, a = "", b = "";
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '4') a += s[i] - 1, b += '1';
			else a += s[i], b += '0';
		}
		int i = s.length()-1;
		reverse(b.begin(), b.end());
		while(b[i] == '0') {
			b.pop_back();
			i--;
		}
		reverse(b.begin(), b.end());
		printf("Case #%d: %s %s\n", tc, a.c_str(), b.c_str());
	}
	return 0;
}