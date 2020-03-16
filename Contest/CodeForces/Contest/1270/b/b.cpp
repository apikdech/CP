/**
 * author:  apikdech
 * created: 29.12.2019 21:14:39
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;

int a[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, ok = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i + 1 < n; i++) {
      if (abs(a[i] - a[i+1]) >= 2) {
        ok = 1;
        cout << "YES\n";
        cout << i+1 << " " << i+2 << "\n";
        break;
      }
    }
    if (!ok) cout << "NO\n";
  }
  return 0;
}
