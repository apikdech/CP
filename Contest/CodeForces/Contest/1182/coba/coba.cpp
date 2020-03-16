/*
 * Author: apikdech
 * Time: 18:54:20 12-06-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> mat;
const int MOD = 998244353, N = 105;
ll K, b[N], factor;
unordered_map<ll, ll> table;

ll powmod(ll a,ll b) {ll res=1; assert(b>=0); for(;b;b>>=1){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;}return res%MOD;}

mat mul(mat A, mat B) {
	mat C(K+1, vector<ll>(K+1));
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= K; j++) {
			for (int k = 1; k <= K; k++) {
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % (MOD - 1);
			}
		}
	}
	return C;
}

mat matpow(mat A, ll n) {
	if (n == 1) return A;
	mat X = matpow(A, n/2);
	X = mul(X, X);
	if (n % 2) return mul(A, X);
	return X;
}

ll babystep(ll x) {
	ll m = ceil(sqrt(MOD)), e = 1LL;
	for (int i = 0; i < m; i++) {
		table[e] = i;
		e = (e * 3) % MOD;
	}
	factor = powmod(3LL, MOD - m - 1);
	e = x;
	for (int i = 0; i < m; i++) {
		if (table.count(e)) return i * m + table[e];
		e = (e * factor) % MOD;
	}
	return -1;
}

ll ex_gcd(ll a, ll b, ll &x, ll &y){
	if (!b){
		x = 1; y = 0;
		return a;
	}
	
	ll q = ex_gcd(b, a % b, y, x);
	y -= a / b * x;
	return q;
}

ll f(ll n, ll m) {
	mat T(K+1, vector<ll>(K+1));
	/* Write T[1][1] to T[K][K] here */
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= K; j++) {
			if (i == 1) T[i][j] = b[j];
			else if (i == j + 1) T[i][j] = 1;
			else T[i][j] = 0;
		}
	}
	T = matpow(T, n-K);
	m = babystep(m);
	ll a = T[1][1], b = MOD - 1, q, ans, _;
	q = __gcd(a, b);
	if (m % q) return -1;
	a /= q, b /= q, m /= q;
	q = ex_gcd(a, b, ans, _);
	ans = (ans * m) % b;
	while(ans < 0) ans += b;
	return powmod(3, ans);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll n, m;
	cin >> K;
	for (int i = 1; i <= K; i++) {
		cin >> b[i];
	}
	cin >> n >> m;
	cout << f(n, m);
	return 0;
}
