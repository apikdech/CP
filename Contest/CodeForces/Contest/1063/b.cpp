#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

ll powmod(ll a,ll b) {ll res=1; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}


int main() {
	int t;
	cin >> t;
	while(t--) {
		ll a, cnt, ans;
		cin >> a;
		if (a == 0) cout << "1\n";
		else {
			cnt = __builtin_popcountll(a);
			// cout << cnt << "\n";
			ans = powmod(2, cnt);
			cout << ans << "\n";
		}
	}
	return 0;
}