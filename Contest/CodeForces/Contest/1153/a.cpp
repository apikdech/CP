#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int n, t, ans = 1e6, id = -1;
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a >= t) {
			if (ans > a) ans = a, id = i;
		}
		else {
			int temp = a + (t-a)/b*b + b;
			if (ans > temp) ans = temp, id = i;
		}
	}
	cout << id + 1 << "\n";
	return 0;
}