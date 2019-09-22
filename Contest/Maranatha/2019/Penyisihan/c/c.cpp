/*
 * Author: apikdech
 * Time: 09:53:54 07-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll josephus(ll n, ll k) {
    if (n == 1)
        return 0;
    if (k == 1)
        return n-1;
    if (k > n)
        return (josephus(n-1, k) + k) % n;
    ll cnt = n / k;
    ll res = josephus(n - cnt, k);
    res -= n % k;
    if (res < 0)
        res += n;
    else
        res += res / (k - 1);
    return res;
}

int main() {
	ll n, a, b;
	cin >> n >> a >> b;
	a += b;
	cout << josephus(n, a) + 1LL << "\n";
	return 0;

}