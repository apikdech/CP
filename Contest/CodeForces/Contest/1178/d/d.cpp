/*
 * Author: apikdech
 * Time: 23:14:29 20-07-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e4 + 5;
bitset<N> bs;
vector<int> prime;

void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i < N; i++) if (bs[i]) {
		for (ll j = i * i; j < N; j += i) bs[j] = 0;
		prime.push_back((int)i);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	sieve();
	int n;
	cin >> n;
	int m = lower_bound(prime.begin(), prime.end(), n) - prime.begin();
	m = prime[m];
	cout << m << "\n";
	for (int i = 1; i < n; i++) {
		cout << i << " " << i + 1 << "\n";
	}
	cout << "1 " << n << "\n";
	for (int i = 0; i < m - n; i++) {
		cout << i+1 << " " << i+1+n/2 << "\n";
	}
	return 0;
}
