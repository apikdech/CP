/*
 * Author: apikdech
 * Time: 23:07:35 20-07-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

ll powmod(ll a,ll b) {ll res=1; assert(b>=0); for(;b;b>>=1){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;}return res%MOD;}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll w, h;
	cin >> w >> h;
	cout << powmod(2, w+h) << "\n";
	return 0;
}
