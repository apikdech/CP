#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int a, b, c, ans = 0, ta, tb, tc, t;
	int l = 1, r = 7e8+5, m;
	cin >> a >> b >> c;
	while(l < r) {
		m = (l+r)>>1;
		if (a - (m-3)/7*3 - (m%7 < 1 ? 1 : m%7 < 4 ? 2 : 0) >= 0 && b - (m-1)/7*2 - (m%7 < 6 ? 1 : 0) >= 0 && c - (m-2)/7*2 - (m%7 < 5 ? 1 : 0) >= 0) l = m+1;
		else r = m-1;
	}
	int x = l;
	while(c - (x-2)/7*2 - (x%7 < 5? 1:0) < 0 || b - (x-1)/7*2 - (x%7 < 6? 1:0) < 0 || a - (x-3)/7*3 - (x%7 < 1? 1 : x%7 < 4? 2 : 0) < 0) {
		cerr << c - (x-2)/7*2 - (x%7 < 5? 1:0) << " " << b - (x-1)/7*2 - (x%7 < 6? 1:0) << " " << a - (x-3)/7*3 - (x%7 < 1? 1 : x%7 < 4? 2 : 0) << "\n";
		x--;
	}
	cout << x << "\n";
	cout << ans << "\n";
	return 0;
}