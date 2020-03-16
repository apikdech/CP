/*
 * Author: apikdech
 * Time: 21:54:04 14-05-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 2e5 + 5;
int a[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, cnt = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    for (int i = 0; i < n; i++) {
        if (a[i] >= cnt) cnt++;
    }
    cout << cnt-1 << "\n";
    return 0;
}
