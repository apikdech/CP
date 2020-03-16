#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, h, a, b, k;
	cin >> n >> h >> a >> b >> k;
	for (int i = 0; i < k; i++) {
		int ta, fa, tb, fb, ans = 0;
		cin >> ta >> fa >> tb >> fb;
		if (ta != tb) {
			if (fa < a) {
				ans += a - fa;
				fa = a;
			} else if (fa > b) {
				ans += fa - b;
				fa = b;
			}
			if (fb < a) {
				ans += a - fb;
				fb = a;
			} else if (fb > b) {
				ans += fb - b;
				fb = b;
			}
		}
		ans += abs(fa - fb) + abs(ta - tb);
		cout << ans << "\n";
	}
	return 0;
}