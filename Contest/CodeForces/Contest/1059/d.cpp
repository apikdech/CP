#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e5+5;
int n, pos, neg;
ld x[N], y[N];

ld cek(ld a) {
	ld res = 0;
	for (int i = 0; i < n; i++) {
		ld dx = a-x[i];
		ld r = (dx*dx+(ld)y[i]*y[i])/(2*y[i]);
		res = max(res, r);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		if (y[i] > 0) pos = 1;
		else neg = 1;
	}
	if (pos & neg) return cout << "-1\n", 0;
	if (neg) for (int i = 0; i < n; i++) y[i] *= -1;
	ld l = -1e8, r = 1e8;
	for (int i = 0; i < 150; i++) {
		ld x1 = l + (r-l)/3.0, x2 = r - (r-l)/3.0;
		if (cek(x1) < cek(x2)) r = x2;
		else l = x1;
	}
	cout << fixed << setprecision(10) << cek(l) << "\n";
	return 0;
}