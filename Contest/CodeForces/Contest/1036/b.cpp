#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int q;
	cin >> q;
	while(q--) {
		ll n, m, k, ans = 0;
		cin >> n >> m >> k;
		if (n < 0) n = -n;
		if (m < 0) m = -m;
		if (n < m) swap(n, m);
		if (n > k) cout << "-1\n";
		else if ((n - m) % 2) cout << k-1 << "\n";
		else if ((k - n) % 2) cout << k-2 << "\n";
		else cout << k << "\n";
	}
	return 0;
}
/*
0 0 ke 4 3 dalam 7 step

0 -1
1 0
2 1
3 2
2 1
3 2
4 3*/

