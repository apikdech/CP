#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int n, a[10], ok = 0;
	cin >> n;
	string s;
	cin >> s;
	a[0] = 0;
	for (int i = 1; i <= 9; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		char w = s[i] - '0';
		if (w < a[w] && !ok) ok = 1, s[i] = a[w] + '0';
		else if (ok && w <= a[w]) s[i] = a[w] + '0';
		else if (ok && w > a[w]) break;
	}
	cout << s << "\n";
	return 0;
}