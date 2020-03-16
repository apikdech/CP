#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5+5;

int main() {
	ll n, L, a, t[N], l[N], ans = 0, ptr = 0;
	cin >> n >> L >> a;
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> l[i];
	}
	for (int i = 0; i < n; i++) {
		ans += (t[i]-ptr)/a;
		ptr = t[i] + l[i];
	}
	ans += (L-ptr)/a;
	cout << ans << "\n";
	return 0;
}

/*
0 1 1 2
0 sampe 2
0 1 2 3

*/