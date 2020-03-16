/**
 * author:  apikdech
 * created: 23.02.2020 16:07:34
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int a[3], ans = 0;
    for (int i = 0; i < 3; i++) cin >> a[i];
    sort(a, a+3);
    reverse(a, a+3);
    if (a[0]) ans++, a[0]--;
    if (a[1]) ans++, a[1]--;
    if (a[2]) ans++, a[2]--;
    if (a[0] && a[1]) ans++, a[0]--, a[1]--;
    if (a[0] && a[2]) ans++, a[0]--, a[2]--;
    if (a[1] && a[2]) ans++, a[1]--, a[2]--;
    if (a[0] && a[1] && a[2]) ans++;
    cout << ans << "\n";
  }
  return 0;
}
