/**
 * author:  apikdech
 * created: 24.02.2020 21:46:46
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 105;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int m, n;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> v;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      x--;
      v.push_back(x);
    }
    sort(v.begin(), v.end());
    int lst = v[0], now = v[0] + 1;
    for (int i = 1; i < m; i++) {
      if (v[i] == now) now = v[i] + 1;
      else {
        // cout << lst << " " << now << "\n";
        sort(a.begin() + lst, a.begin() + now + 1);
        lst = v[i];
        now = v[i] + 1;
      }
    }
    sort(a.begin() + lst, a.begin() + now + 1);
    int ok = 1;
    for (int i = 0; i + 1 < n; i++) {
      if (a[i] > a[i + 1]) ok = 0;
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}