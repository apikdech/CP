/**
 * author:  apikdech
 * created: 24.02.2020 22:15:58
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;

int BIT[N][26];
int n, m;

void add(int idx, int c) {
  for (; idx <= n; idx += idx & -idx) {
    BIT[idx][c] += 1;
  }
}

int get(int idx, int c) {
  int res = 0;
  for (; idx > 0; idx -= idx & - idx) {
    res += BIT[idx][c];
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> ans(26);
    for (int i = 0; i < n; i++) {
      add(i + 1, s[i] - 'a');
    }
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      for (int j = 0; j < 26; j++) {
        ans[j] += get(x, j);
      }
    }
    for (int j = 0; j < 26; j++) ans[j] += get(n, j);
    for (int i = 0; i < 26; i++) cout << ans[i] << " \n"[i + 1 == 26];
    for (int i = 0; i <= n; i++) for (int j = 0; j < 26; j++) BIT[i][j] = 0;
  }
  return 0;
}
