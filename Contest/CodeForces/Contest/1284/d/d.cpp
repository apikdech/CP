/**
 * author:  apikdech
 * created: 07.01.2020 13:58:54
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;

int n, ans;

struct Event {
  int t, st, en, ok;
  Event(int t, int st, int en, int ok) : t(t), st(st), en(en), ok(ok) {}
  bool operator<(const Event &rhs) {
    if (t == rhs.t) return ok < rhs.ok;
    return t < rhs.t;
  }
};

bool cek(vector<int> &sa, vector<int> &ea, vector<int> &sb, vector<int> &eb) {
  multiset<int> s, e;
  vector<Event> events;
  for (int i = 0; i < n; i++) {
    events.emplace_back(sa[i], sb[i], eb[i], 1);
    events.emplace_back(ea[i] + 1, sb[i], eb[i], 0);
  }
  sort(events.begin(), events.end());
  for (auto &[t, st, en, ok] : events) {
    if (ok) {
      if (!s.empty()) {
        int st_mx = *s.rbegin();
        int en_mn = *e.begin();
        if (st_mx > en || en_mn < st) return false;
      }
      s.insert(st);
      e.insert(en);
    } else {
      s.erase(s.find(st));
      e.erase(e.find(en));
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  vector<int> sa(n), sb(n), ea(n), eb(n);
  for (int i = 0; i < n; i++) {
    cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];
  }
  ans = (cek(sa, ea, sb, eb) & cek(sb, eb, sa, ea));
  if (ans) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}
