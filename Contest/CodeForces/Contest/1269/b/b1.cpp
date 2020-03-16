/**
 * author:  apikdech
 * created: 25.12.2019 19:58:03
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e3 + 5;

ll a[N], b[N];

vector<ll> x;
unordered_map<ll, ll> cnt;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  ll m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  // cout << "TES\n";
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    cnt[b[i]]++;
    x.push_back((a[0] - b[i] + m) % m);
    x.push_back((b[i] - a[0] + m) % m);
  }
  sort(x.begin(), x.end());
  for (auto it : x) {
    unordered_map<ll, ll> tmp;
    int ok = 1;
    for (int i = 0; i < n; i++) {
      tmp[(a[i] + it) % m]++;
    }
    for (auto [num, freq] : tmp) {
      if (cnt.count(num) == 0) ok = 0;
      else if (cnt[num] != freq) ok = 0;
    }
    if (ok) return cout << it << "\n", 0;
  }
  return 0;
}
