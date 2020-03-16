/**
 * author:  apikdech
 * created: 07.02.2020 02:02:32
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> dp(26), ans;
  string s;
  cin >> s;
  for (char &c : s) {
    int mx = 0;
    for (int i = 25; i > c - 'a'; i--) {
      mx = max(mx, dp[i] + 1);
    }
    dp[c - 'a'] = mx;
    ans.push_back(mx);
  }
  cout << *max_element(dp.begin(), dp.end()) << "\n";
  for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i + 1 == n];
  return 0;
}
