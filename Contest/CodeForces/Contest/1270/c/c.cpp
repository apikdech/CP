/**
 * author:  apikdech
 * created: 29.12.2019 21:34:20
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;

ll a[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    ll sum = 0, sor = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
      sor ^= a[i];
    }
    if (sum == 2*sor) cout << "0\n\n";
    else {
      if (sor == 0) {
        cout << "1\n";
        cout << sum << "\n";
      } else {
        sum += sor;
        cout << "2\n";
        cout << sor << " " << sum << "\n";
      }
    }
  }
  return 0;
}
