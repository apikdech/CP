/*
 * Author: apikdech
 * Time: 22:41:12 07-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e6;
bitset<N> bs;

void pre() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i < N; i++) if (bs[i]) {
		for (ll j = i*i; j < N; j+=i) bs[j] = 0;
	}
	bs[1] = 1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	pre();
	int t;
	cin >> t;
	while(t--) {
		ll n, tiga = 2, satu = 1, tuju = 1;
		string ans = "";
		cin >> n;
		if (n < 1e5 - 3 && bs[n]) {
			for (int i = 0; i < n; i++) ans += '1';
			ans += "337";
		}
		else {
			for (ll i = 2; i < 1e5; i++) {
				if (n % (i * (i-1))/2 == 0) {
					tiga = max(i, tiga);
				}
			}
			if (tiga != 2) n /= (tiga * (tiga-1)/2);
			if (n < 1e5 - 3 && bs[n]) satu = n;
			else for (ll i = 2; i * i <= n; i++) {
				if (n % i == 0) {
					satu = i, tuju = n/i;
					break;
				}
			}
			for (int i = 0; i < satu; i++) ans += '1';
			for (int i = 0; i < tiga; i++) ans += '3';
			for (int i = 0; i < tuju; i++) ans += '7';
		}
		cout << ans << "\n";
	}
	return 0;
}
