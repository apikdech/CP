#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i-1]) {
			cout << "YES\n";
			string ans = "";
			ans += s[i-1];
			ans += s[i];
			cout << ans << "\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}