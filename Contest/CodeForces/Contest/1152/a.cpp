#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int n, m, a = 0, b = 0, ans = 0, c = 0, d = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x & 1) a++;
		else b++;
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if (x & 1) c++;
		else d++;
	}
	cout << min(a, d) + min(b, c) << "\n";
	return 0;
}