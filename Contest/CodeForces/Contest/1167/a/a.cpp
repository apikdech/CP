#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, ok = 0;
		cin >> n;
		string s;
		cin >> s;
		for (int i = 0; i < n - 10; i++) {
			if (s[i] == '8') ok = 1;
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}