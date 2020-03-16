/**
 * author:  apikdech
 * created: 15.02.2020 21:30:26
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    string s;
    cin >> n >> s;
    vector<int> l(n), r(n), v;
    set<int> S;
    for (int i = 1; i <= n; i++) S.insert(i);
    int num = 0, prv = 0;
    for (int i = 0; i < n-1; i++) {
      if (s[i] == '<') v.push_back(i), r[i] = ++num;
    }
    v.push_back(n);
    for (int &it : v) {
      for (int i = it - 1; i >= prv; i--) {
        r[i] = ++num;
      }
      prv = it + 1;
    }
    num = n;
    v.clear();
    int ok = 1, lst = -1;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == '>') l[i] = num, lst = i, S.erase(num--);
      else v.push_back(i);
    }
    vector<pair<int, int>> tmp;
    if (!v.empty()) tmp.push_back({v[0], v[0]});
    if (!l[n-1]) v.push_back(n-1);
    for (int i = 1; i < v.size(); i++) {
      if (v[i] - tmp.back().second == 1) tmp[tmp.size() - 1].second = v[i];
      else tmp.push_back({v[i], v[i]});
    }
    if (~lst) {
      l[lst + 1] = 1, S.erase(1);
      if (tmp.size()) {
        for (auto &[L, R] : tmp) {
          for (int i = R; i >= L; i--) if (!l[i]) l[i] = *S.rbegin(), S.erase(*S.rbegin());
        }
      }
      else for (int i = 0; i < n; i++) if (!l[i]) l[i] = *S.rbegin(), S.erase(*S.rbegin());
    } else {
      num = 0;
      for (int i = 0; i < n; i++) l[i] = ++num;
    }
    for (int i = 0; i < n; i++) cout << l[i] << " \n"[i + 1 == n];
    for (int i = 0; i < n; i++) cout << r[i] << " \n"[i + 1 == n];
  }
  return 0;
}
