#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n;
		string s, ans = "";
		cin >> n >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'S') ans += 'E';
			else ans += 'S';
		}
		printf("Case #%d: %s\n", tc, ans.c_str());
	}
	return 0;
}