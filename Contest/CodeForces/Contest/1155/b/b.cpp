#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int n, cnt = 0;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n - 10; i++) {
		if (s[i] == '8') cnt++;
	}
	if (cnt > (n-10)/2) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}