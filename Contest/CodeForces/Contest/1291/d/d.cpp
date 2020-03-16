/**
 * author:  apikdech
 * created: 03.02.2020 00:28:59
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;

int BIT[N][26];
string s;

void add(int pos, int c, int val) {
  pos++;
  for (; pos < N; pos += pos & -pos) {
    BIT[pos][c] += val;
  }
}

vector<int> query(int pos) {
  vector<int> res(26);
  for (int i = pos; i > 0; i -= i & -i) {
    for (int j = 0; j < 26; j++) {
      res[j] += BIT[i][j];
    }
  }
  return res;
}

string query(int l, int r) {
  if (l == r) return "Yes";
  if (s[l-1] != s[r-1]) return "Yes";
  int cnt = 0;
  vector<int> lft = query(l-1);
  vector<int> rght = query(r);
  for (int i = 0; i < 26; i++) if (rght[i] > lft[i]) cnt++;
  if (cnt <= 2) return "No";
  return "Yes";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    add(i, s[i] - 'a', 1);
  }
  int q;
  cin >> q;
  while(q--) {
    int l, r;
    cin >> l >> r;
    cout << query(l, r) << "\n";
  }
  return 0;
}
