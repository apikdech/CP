/*
 * Author: apikdech
 * Time: 20:51:09 10-05-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    if (m == 0) cout << "1\n";
    else cout << min(n-m, m) << "\n";
    return 0;
}
