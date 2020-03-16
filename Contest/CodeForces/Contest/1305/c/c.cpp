/**
 * author:  apikdech
 * created: 03.03.2020 22:07:32
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;

int a[N];
map<int, int> cnt;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, ok = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i] % m]++;
    if (cnt[a[i] % m] > 1) ok = 1;
  }
  if (ok) cout << "0\n";
  else {
    ll ans = 1;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        ans = (ans * abs(a[j] - a[i])) % m;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
