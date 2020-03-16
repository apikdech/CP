/**
 * author:  apikdech
 * created: 04.02.2020 22:02:12
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, INF = 2e9;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, x = 0, y = 0, prev_x = 0, prev_y = 0, ans = INF, pos = -1;
    cin >> n;
    string s;
    cin >> s;
    map<pair<int, int>, int> dist;
    dist[{0, 0}] = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'L') x--;
      else if (s[i] == 'R') x++;
      else if (s[i] == 'U') y++;
      else y--;
      if (dist.count({x, y})) {
        int dif = abs(dist[{prev_x, prev_y}] - dist[{x, y}]);
        if (ans > dif) ans = dif, pos = i + 1;
      }
      dist[{x, y}] = dist[{prev_x, prev_y}] + 1;
      prev_x = x;
      prev_y = y;
    }
    if (pos != -1) cout << pos - ans << " " << pos << "\n";
    else cout << pos << "\n";
  }
  return 0;
}
