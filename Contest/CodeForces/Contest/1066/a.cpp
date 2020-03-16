#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int L, v, l, r, a, b, c, d, ans = 0;
		cin >> L >> v >> l >> r;
		if (l != 1) ans += ((l-1)/v);
		if (r != L) ans += (L/v) - ((r+1)/v) + ((r+1)%v == 0);
		cout << ans << "\n";
	}
	return 0;
}

/*
ada berapa sih bilangan dari 10 - 20 yang habis dibagi 2?
20/2 = 10
10/2 = 5
19/2 = 9
10/2 = 5
9 - 5 = 4
if (l % v == 0) ans++;

*/