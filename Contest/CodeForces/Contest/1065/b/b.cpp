#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ll n, m, mn, mx = 0;
	cin >> n >> m;
	if (m == 0) mn = mx = n;
	else if (m == 1) mn = mx = max((ll)0, n-2);
	else {
		mn = max((ll)0, n - 2*m);
		ll l = 0, r = 1e10;
		while(l <= r) {
			ll k = (l+r)/2;
			if ((k * (k+1)) >= m*2) r = k-1, mx = k;
			else l = k + 1;
		}
		mx++;
		mx = max(ll(0), n-mx);
	}
	cout << mn << " " << mx << "\n";
	return 0;
}

//misal ada 7 node dan 3 edge
/*
1 2
3 4
5 6
7 sendirian kan
8 node 2 edge
nah 
4 edge
2 edge
1 2
3 4
5, 6, 7 sendiri kan?
2 1
3 1
brati ada 5 kan?
8 - 2+1

sekarang maxnya
7 node 3 edge
1 2
1 3
2 3
1 4
2 4
3 4
7 node 6 edge itu yang kepake bisa 4
jadi gini
1 2 3 4 5 6 7 8 9 10
2 3 3 4 4 4 5 5 5 5
n(n-1)/2
6 * 5 / 2
15
misal ada 15 edge
maka kita kai 2
30
akar 30 itu kan 5
ansnya itu 6

ya ngga?
nah misal ada 4 edge
8
akar 8 itu kan 2
2 + 1 itu 3
harusnya ngga kan

misal ada 8 node 4 edge nah
1 sampe 10k
cek 5k
5k * 5k+1 > 2*m ?
true maka bates kanan jadi

*/