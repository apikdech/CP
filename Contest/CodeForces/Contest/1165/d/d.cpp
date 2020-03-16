/*
 * Author: apikdech
 * Time: 22:33:20 14-05-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 305, M = 1e6+5;
ll a[N];


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, ok = 1;
        map<ll, bool> vis;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a+n);

        ll tmp = a[0] * a[n-1], cnt = 0;
        for (int i = 0; i < n/2; i++) {
            if (a[i] * a[n-i-1] != tmp) ok = 0;
        }
        for (ll i = 2; i * i <= tmp; i++) {
            if (tmp % i == 0) {
                if (i * i == tmp) cnt++, vis[i] = 1;
                else cnt+=2, vis[i] = vis[tmp/i] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (!vis[a[i]]) ok = 0;
        }
        // cerr << cnt << "\n";
        if (cnt != n) ok = 0;
        if (!ok) cout << "-1\n";
        else cout << a[0] * a[n-1] << "\n";
    }
    return 0;
}
