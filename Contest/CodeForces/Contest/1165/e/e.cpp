/*
 * Author: apikdech
 * Time: 23:12:52 14-05-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const int N = 2e5 + 5;
ll a[N], b[N], ans = 0, n;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] *= (n-i) * (i+1LL);
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a, a+n);
    sort(b, b+n);
    reverse(b, b+n);
    for (int i = 0; i < n; i++) {
        ans = (ans + ((a[i] % MOD) * (b[i] % MOD)) % MOD) % MOD;
    }
    cout << ans << "\n";
    return 0;
}
