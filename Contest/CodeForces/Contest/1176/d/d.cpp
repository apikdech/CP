/*
 * Author: apikdech
 * Time: 23:08:27 09-06-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 3e6, M = 3e6;
int b[N], c[N];
vector<int> ans, prime;
bitset<M> bs;
unordered_map<int, int> m;

void sieve() {
	int cnt = 0;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i < M; i++) if (bs[i]) {
		for (ll j = i * i; j < M; j += i) bs[j] = 0;
		prime.push_back((int)i);
		m[(int)i] = cnt;
		cnt++;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	sieve();
	int n;
	cin >> n;
	for (int i = 0; i < 2*n; i++) {
		cin >> b[i];
		c[b[i]]++;
	}
	sort(b, b+2*n);
	reverse(b, b+2*n);
	for (int i = 0; i < 2*n; i++) {
		if (c[b[i]] == 0) continue;
		int x = b[i];
		
		// cerr << x << " " << bs[x] << "\n";
		if (!bs[x]) {
			int tmp = -1;
			for (int i = 2; i * i <= x; i++) {
				if (x % i == 0) {
					tmp = i;
					break;
				}
			}
			tmp = x / tmp;
			if (c[tmp] == 0) continue; 
			c[b[i]]--, c[tmp]--;
			ans.push_back(x);
		}
	}
	reverse(b, b+2*n);
	for (int i = 0; i < 2*n; i++) {
		// cerr << b[i] << " " << c[b[i]] << "\n";
		if (c[b[i]] == 0) continue;
		c[b[i]]--;
		ans.push_back(b[i]);
		c[prime[b[i]-1]]--;
	}
	for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n-1];
	return 0;
}
