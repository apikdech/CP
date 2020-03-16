#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 2e5 + 5;
int s[N];

int main() {
	int n, b, a, x, ans = 0;
	cin >> n >> b >> a;
	int ta = a, tb = b;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		if (s[i]) {
			if (ta == a) ta--, ans++;
			else if (tb > 0) tb--, ta++, ans++;
			else if (ta > 0) ta--, ans++;
			else break;
		} else {
			if (ta > 0) ta--, ans++;
			else if (tb > 0) tb--, ans++;
			else break;
		}
	}
	cout << ans << "\n";
	return 0;
}