/*
 * Author: apikdech
 * Time: 17:35:03 12-06-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> mat;
const ll MOD = 1000000007, K = 5;
ll f1, f2, f3, f4, f5, c, factor;
unordered_map<ll, ll> table;

mat mul(mat A, mat B) {
	mat C(K+1, vector<ll>(K+1));
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= K; j++) {
			for (int k = 1; k <= K; k++) {
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % (MOD-1);
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

ll powmod(ll a,ll b) {ll res=1; assert(b>=0); for(;b;b>>=1){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;}return res%MOD;}

ll f(ll n) {
	vector<ll> F(K+1);
	// F[1] = f3;
	// F[2] = f2;
	// F[3] = f1;
	// F[4] = 2*c;
	// F[5] = 2*c;
	F[1] = f5;
	F[2] = f4;
	F[3] = f3;
	F[4] = f2;
	F[5] = f1;
	mat T(K+1, vector<ll>(K+1));
	T[1][1] = 3, T[1][2] = MOD - 1 - 2, T[1][3] = 0, T[1][4] = MOD - 1 - 1, T[1][5] = 1;
	T[2][1] = 1, T[2][2] = 0, T[2][3] = 0, T[2][4] = 0, T[2][5] = 0;
	T[3][1] = 0, T[3][2] = 1, T[3][3] = 0, T[3][4] = 0, T[3][5] = 0;
	T[4][1] = 0, T[4][2] = 0, T[4][3] = 1, T[4][4] = 0, T[4][5] = 0;
	T[5][1] = 0, T[5][2] = 0, T[5][3] = 0, T[5][4] = 1, T[5][5] = 0;
	T = matpow(T, n-5);
	// T[1][1] = 1, T[1][2] = 1, T[1][3] = 1, T[1][4] = 1, T[1][5] = 0;
	// T[2][1] = 1, T[2][2] = 0, T[2][3] = 0, T[2][4] = 0, T[2][5] = 0;
	// T[3][1] = 0, T[3][2] = 1, T[3][3] = 0, T[3][4] = 0, T[3][5] = 0;
	// T[4][1] = 0, T[4][2] = 0, T[4][3] = 0, T[4][4] = 1, T[4][5] = 1;
	// T[5][1] = 0, T[5][2] = 0, T[5][3] = 0, T[5][4] = 0, T[5][5] = 1;
	// T = matpow(T, n-3);
	ll fn = 0;
	for (int i = 1; i <= K; i++) fn = fn + T[1][i] * F[i];
	return powmod(5, fn);
}

void pre() {
	ll m = ceil(sqrt(MOD)), e = 1LL;
	for (int i = 0; i < m; i++) {
		table[e] = i;
		e = (e * 5) % MOD;
	}
	factor = powmod(5LL, MOD - m - 1);
}

ll babystep(ll x) {
	ll e = x, m = ceil(sqrt(MOD));
	for (int i = 0; i < m; i++) {
		if (table.count(e)) return i * m + table[e];
		e = (e * factor) % MOD;
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	pre();
	ll n;
	cin >> n >> f1 >> f2 >> f3 >> c;
	//new thing
	f4 = powmod(c, 2*4-6) * f3 % MOD * f2 % MOD * f1 % MOD;
	f5 = powmod(c, 2*5-6) * f4 % MOD * f3 % MOD * f2 % MOD;
	if (n == 4) cout << f4 << "\n";
	else if (n == 5) cout << f5 << "\n";
	else {
		f1 = babystep(f1), f2 = babystep(f2), f3 = babystep(f3), c = babystep(c), f4 = babystep(f4), f5 = babystep(f5);
		cout << f(n);
	}
	return 0;
}
