/**
 * author:  apikdech
 * created: 29.12.2019 01:18:33
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

queue<pair<int, int>> q;
vector<int> ans;
ll res;
unordered_map<int, bool, custom_hash> vis;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  // vis.reserve(1 << 15);
  // vis.max_load_factor(0.25);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    vis[x] = 1;
    q.push({x, 0});
  }
  while(m) {
    int x = q.front().first;
    int dist = q.front().second;
    q.pop();
    for (auto &i : {1, -1}) {
      int nxt_x = x + i;
      if (vis.count(nxt_x)) continue;
      vis[nxt_x] = 1;
      res += (ll)(dist + 1);
      ans.push_back(nxt_x);
      m--;
      if (!m) break;
      q.push({nxt_x, dist + 1});
    }
    if (!m) break;
  }
  cout << res << "\n";
  for (auto &it : ans) cout << it << " ";
  return 0;
}
