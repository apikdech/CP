/*
 * Author: apikdech
 * Time: 22:01:07 14-05-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, cnt = 0;
    cin >> n;
    string s;
    char prev = 'A';
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (i >= s.length()) break;
        if ((i % 2 == 0) && s[i] == s[i+1]) {
            s.erase(s.begin() + i + 1);
            cnt++;
            i--;
        }
    }
    int t = s.length();
    if (t & 1) {
        cnt++;
        s.erase(s.begin() + t-1);
    }
    cout << cnt << "\n";
    cout << s << "\n";
    return 0;
}
 