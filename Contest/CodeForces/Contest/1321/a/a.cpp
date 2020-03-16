/**
 * author:  apikdech
 * created: 02.03.2020 12:20:15
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 105;

int a[N], b[N], x = 0, y = 0, ans = 0;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) continue;
    if (a[i]) x++;
    if (b[i]) y++;
  }
  if (!x) return cout << "-1\n", 0;
  while(ans * x <= y) ans++;
  cout << ans << "\n";
  return 0;
}
