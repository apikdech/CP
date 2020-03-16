#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	string x = s;
	sort(x.begin(), x.end());
	if (x == s) return cout << "NO\n", 0;
	cout << "YES\n";
	for (int i = 0; i < n-1; i++) {
		if (s[i] > s[i+1]) return cout << i+1 << " " << i+2 << "\n", 0;
	}
	return 0;
}