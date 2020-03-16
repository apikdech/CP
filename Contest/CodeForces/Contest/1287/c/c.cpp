/**
 * author:  apikdech
 * created: 06.01.2020 11:06:55
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 105;

int a[N], vis[N], zero, genap, ganjil, fi = 0, la = 1, ans = 0;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 0) a[i] = -1, zero++;
    else vis[a[i]]++;
  }
  if (zero == n) {
    if (n == 1) cout << "0\n";
    else cout << "1\n";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      if (i & 1) ganjil++;
      else genap++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] != -1) {
      a[0] = a[i] & 1;
      break;
    }
  }
  for (int i = n; i >= 1; i--) {
    if (a[i] != -1) {
      a[n+1] = a[i] & 1;
      break;
    }
  }

  for (int i = 1; i + 1 <= n; i++) {
    if (a[i] != -1 && a[i+1] != -1 && a[i] % 2 != a[i+1] % 2) ans++;
  }
  vector<int> uod, uev, od, ev;
  for (int i = 0; i <= n+1; i++) {
    if (a[i] == -1) la++;
    else {
      if (la - fi > 1) {
        if (fi == 0 || la == n+1) {
          if (a[la] & 1) uod.push_back(la - fi - 1);
          else uev.push_back(la - fi - 1);
        } else if (a[la] % 2 == a[fi] % 2) {
          if (a[la] & 1) od.push_back(la - fi - 1);
          else ev.push_back(la - fi - 1);
        } else ans++;
      } fi = i, la = i+1;
    }
  }
  ans += 2*(od.size() + ev.size()) + uod.size() + uev.size();
  sort(od.begin(), od.end());
  sort(ev.begin(), ev.end());
  sort(uod.begin(), uod.end());
  sort(uev.begin(), uev.end());
  for (int it : od) {
    if (it <= ganjil) ganjil -= it, ans -= 2;
  }
  for (int it : uod) {
    if (it <= ganjil) ganjil -= it, ans--;
  }
  for (int it : ev) {
    if (it <= genap) genap -= it, ans -= 2;
  }
  for (int it : uev) {
    if (it <= genap) genap -= it, ans--;
  }
  cout << ans << "\n";
  return 0;
}
