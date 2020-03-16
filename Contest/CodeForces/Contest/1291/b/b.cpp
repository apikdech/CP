/**
 * author:  apikdech
 * created: 02.02.2020 21:28:23
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 3e5 + 5;

int a[N], pref[N], suf[N];

void reset(int n) {
  for (int i = 0; i <= n + 1; i++) {
    a[i] = 0, pref[i] = 0, suf[i] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, ok = 0;
    cin >> n;
    reset(n);
    pref[0] = suf[n+1] = 1;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] >= i - 1) pref[i] = pref[i-1];
    }
    for (int i = n; i > 0; i--) {
      if (a[i] >= n - i) suf[i] = suf[i+1];
    }
    for (int i = 1; i <= n; i++) {
      if (pref[i] && suf[i]) ok = 1;
    }
    if (ok) cout << "Yes\n";
    else cout << "No\n";
  }
  return 0;
}
