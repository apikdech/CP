/**
 * author:  apikdech
 * created: 10.01.2020 22:27:44
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;

int solve(vector<int> &a, int pos) {
  if (pos == -1) return 0;
  vector<int> v[2];
  for (int &it : a) {
    if (it & 1 << pos) v[1].push_back(it);
    else v[0].push_back(it);
  }
  if (v[0].empty()) return solve(v[1], pos - 1);
  if (v[1].empty()) return solve(v[0], pos - 1);
  int ans_on = solve(v[1], pos - 1);
  int ans_off = solve(v[0], pos - 1);
  return 1 << pos | min(ans_on, ans_off);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &it : a) {
    cin >> it;
  }
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  cout << solve(a, 29) << "\n";
  return 0;
}
