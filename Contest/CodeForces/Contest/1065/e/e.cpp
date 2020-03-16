/**
 * author:  apikdech
 * created: 05.11.2019 16:22:06
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353, N = 2e5 + 5;
ll a[N], b[N], sum, sisa;

ll powmod(ll a,ll b, ll m = MOD) {ll res=1; assert(b>=0); for(;b;b>>=1){if(b&1)res=(res*a)%m;a=(a*a)%m;}return res%m;}

ll inv(ll a) {
	return powmod(a, MOD - 2);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll n, m, A;
	cin >> n >> m >> A;
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		a[i] = b[i] - b[i-1];
	}
	sisa = n - 2*b[m];
	sisa = powmod(A, sisa);
	sum = powmod(A, b[m]);
	for (int i = 1; i <= m; i++) {
		sum = sum * (powmod(A, a[i]) + 1LL) % MOD;
	}
	sum = sum * inv(powmod(2, m)) % MOD;
	sum = sum * sisa % MOD;
	cout << sum << "\n";
	return 0;
}
