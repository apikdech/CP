#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5, sz = 1e6 + 5;
ll a[N], ans = 0, mod = 1e9+7, factor[sz], fact[N], ifact[N], cnt[N], icnt[N], n;
bitset<sz> bs, primesquare;
vector<int> v;

ll powmod(ll a,ll b, ll m) {ll res=1;a%=m; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%m;a=a*a%m;}return res;}
ll inv(ll n, ll m) {return powmod(n, m-2, m);}

void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i < sz; i++) if (bs[i]) {
		for (ll j = i * i; j < sz; j+=i) {
			if (j == i*i) primesquare[j] = true;
			bs[j] = 0;
			factor[j]=i;
		}
		v.push_back((int)i);
	}
}

void pre() {
	fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
	for (ll i = 2; i < N; i++) {
		fact[i] = (i * fact[i-1]) % mod;
		// ifact[i] = inv(fact[i], mod);
	}
	cnt[1] = 1;
	for (int i = 2; i < N; i++) {
		cnt[i] = 1;
		if (bs[i]) cnt[i] = 2, icnt[i] = inv(3, mod);
		else {
			int x = i;
			for (int j = 0;; j++) {
				if (v[j]*v[j] > i) break;
				int temp = 1;
				while (x % v[j] == 0) {
					x /= v[j];
					temp++;
				}
				cnt[i] *= temp;
			}
			if (bs[x]) cnt[i] *= 2;
			else if (primesquare[x]) cnt[i] *= 3;
			else if (x != 1) cnt[i] *= 4;
			icnt[i] = inv(cnt[i]+1, mod);
		}
	}
}

int main() {
	sieve(); pre();
	// for (int i = 0; i < 10; i++) cout << v[i] << " ";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	// for (int i = 2; i <= 20; i++) cout << cnt[i] << " ";
	if (n == 1) return cout << "0\n", 0;
	ans = ((n*fact[n])%mod - (fact[n+1]*inv(2,mod))%mod)%mod;
	while(ans < 0) ans += mod;
	ans = (ans * a[1]) % mod;
	for (int i = 2; i <= n; i++) {
		ll kali = ((n*fact[n])%mod - (((fact[n+1]*cnt[i])%mod)*icnt[i])%mod)%mod;
		while(kali < 0) kali += mod;
		// printf("%d\n", kali);
		ans = (ans + (a[i] * kali)%mod)%mod;
	}
	ll res = (ans * inv(fact[n], mod))%mod;
	cout << res << "\n";
	return 0;
}