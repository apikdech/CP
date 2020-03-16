/*
 * Author: apikdech
 * Time: 21:42:32 14-05-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x, y, ans = 0;
    cin >> n >> x >> y;
    string s, a;
    cin >> s;
    a = "1";
    for (int i = 0; i < y; i++) {
        a += "0";
    }
    for (int i = 0; i < x - y - 1; i++) {
        a = "0" + a;
    }
    // cout << a << "\n";
    for (int i = 0; i < x; i++) { 
        if (s[n-i-1] != a[x-i-1]) ans++;
    }
    cout << ans << "\n";
    return 0;
}
