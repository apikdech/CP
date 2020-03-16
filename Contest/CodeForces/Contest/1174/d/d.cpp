/**
 * author:  apikdech
 * created: 10.01.2020 18:31:38
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int n, x;
vector<int> ans, v;

void build(int n) {
  if (n == -1) return;
  build(n-1);
  ans.push_back(v[n]);
  build(n-1);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    v.push_back(1 << i);
  }
  if (x < (1 << n)) {
    int pos = 0;
    for (int i = 0; i < n; i++) {
      if (x >= v[i]) pos = max(pos, i);
    }
    v.erase(v.begin() + pos);
  }
  build(v.size() - 1);
  cout << ans.size() << "\n";
  if (ans.size()) for (int it : ans) cout << it << " ";
  return 0;
}
