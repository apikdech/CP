/**
 * author:  apikdech
 * created: 19.01.2020 21:00:55
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;

int a[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q, ok = 0;
  cin >> n >> q;
  set<pair<int, int>> blocked;
  while(q--) {
    int r, c;
    cin >> r >> c;
    if (a[c] == r || a[c] == 3) a[c] -= r;
    else a[c] += r;
    if (a[c] == 3) blocked.insert({c, 0});
    else if (a[c] == 1) {
      if (a[c+1] == 2 || a[c+1] == 3) blocked.insert({c, c+1});
      if (a[c-1] == 2 || a[c-1] == 3) blocked.insert({c-1, c});
      if (blocked.count({c, 0})) blocked.erase({c, 0});
      if (a[c+1] <= 1 && blocked.count({c, c+1})) blocked.erase({c, c+1});
      if (a[c-1] <= 1 && blocked.count({c-1, c})) blocked.erase({c-1, c});
    } else if (a[c] == 2) {
      if (a[c+1] == 1 || a[c+1] == 3) blocked.insert({c, c+1});
      if (a[c-1] == 1 || a[c-1] == 3) blocked.insert({c-1, c});
      if (blocked.count({c, 0})) blocked.erase({c, 0});
      if ((a[c+1] == 2 || a[c+1] == 0) && blocked.count({c, c+1})) blocked.erase({c, c+1});
      if ((a[c-1] == 2 || a[c-1] == 0) && blocked.count({c-1, c})) blocked.erase({c-1, c});
    } else {
      if (blocked.count({c, c+1})) blocked.erase({c, c+1});
      if (blocked.count({c-1, c})) blocked.erase({c-1, c});
    }
    if (blocked.empty()) cout << "Yes\n";
    else cout << "No\n";
  }
  return 0;
}
