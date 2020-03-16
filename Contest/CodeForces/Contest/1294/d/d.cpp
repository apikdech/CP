/**
 * author:  apikdech
 * created: 22.01.2020 22:36:03
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int mex = 0;
unordered_map<int, int> cnt, lst;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cnt.reserve(1 << 15);
  cnt.max_load_factor(0.25);
  int q, x;
  cin >> q >> x;
  while(q--) {
    int y;
    cin >> y;
    y %= x;
    y = lst[y] + y;
    cnt[y]++;
    lst[y % x] += x;
    while(cnt.count(mex)) mex++;
    cout << mex << "\n";
  }
  return 0;
}
