/**
 * author:  apikdech
 * created: 27.02.2020 08:07:34
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;

pair<ll, ll> pt[N];
vector<ll> v;
ll ans = 0;
ll BIT[N][2];

void add(int idx, int val, int pos) {
  for (; idx < N; idx += idx & -idx) {
    BIT[idx][pos] += val;
  }
}

ll get(int idx, int pos) {
  ll res = 0;
  for (; idx > 0; idx -= idx & -idx) {
    res += BIT[idx][pos];
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> pt[i].first;
  }
  for (int i = 0; i < n; i++) {
    cin >> pt[i].second;
    v.push_back(pt[i].second);
  }
  sort(pt, pt + n);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 0; i < n; i++) {
    pt[i].second = lower_bound(v.begin(), v.end(), pt[i].second) - v.begin();
    pt[i].second++;
  }
  for (int i = 0; i < n; i++) {
    ll cnt = get(pt[i].second, 0);
    ll sum = get(pt[i].second, 1);
    ans += cnt * pt[i].first - sum;
    add(pt[i].second, 1, 0);
    add(pt[i].second, pt[i].first, 1);
  }
  cout << ans << "\n";
  return 0;
}
