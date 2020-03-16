#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 1e6;

bitset<N+5> bs;
vector<int> prime;

void sieve() {
	int sz = 1e6;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= sz; i++) if (bs[i]) {
		for (ll j = i*i; j <= sz; j += i) bs[j] = 0;
		prime.push_back((int)i);
	}
}

bool isPrime(ll x) {
	if (x < 1e6) return bs[x];
	else {
		for (int i = 0; i < prime.size(); i++) {
			if (x % prime[i] == 0) return false;
		}
	}
	return true;
}

int main() {
	sieve();
	cout << "HEHE\n";
	ll a, ans = 1, cnt = 0;
	cin >> a;
	for (int i = 0; i < prime.size(); i++) {
		if (prime[i] * prime[i] * prime[i] > a) break;
		cnt = 1;
		while(a % prime[i] == 0) {
			a /= prime[i];
			cnt++;
		}
		ans *= cnt;
	}
	if (isPrime(a)) ans *= 2;
	else if (sqrt(a) * sqrt(a) == a && isPrime(sqrt(a))) ans *= 3;
	else if (a != 1) ans *= 4;
	cout << ans << "\n";
	return 0;
}
/*

*/