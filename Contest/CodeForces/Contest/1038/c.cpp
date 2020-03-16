#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MXN = 1e5+5;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, A[MXN] = {0}, B[MXN] = {0}, a = 0, b = 0;
	cin >> n;
	ll cnta = n, cntb = n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) cin >> B[i];
	sort(A, A+n+1);
	sort(B, B+n+1);
	while(true) {
		if (A[cnta] >= B[cntb]) {
			a += A[cnta];
			cnta--;
		} else cntb--;
		if (B[cntb] >= A[cnta]) {
			b += B[cntb];
			cntb--;
		} else cnta--;
		//cout << a << " " << b << "\n";
		if (cnta <= 0 && cntb <= 0) break;
	}
	cout << a - b << "\n";
	return 0;
}