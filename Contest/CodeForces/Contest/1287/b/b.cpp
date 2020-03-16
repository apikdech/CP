/**
 * author:  apikdech
 * created: 05.01.2020 23:01:58
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1505;

string s[N];
unordered_map<string, int> x;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, ans = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    x[s[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      string t = "";
      for (int k = 0; k < m; k++) {
        if (s[i][k] == s[j][k]) t += s[i][k];
        else if (s[i][k] == 'T' && s[j][k] == 'S') t += 'E';
        else if (s[i][k] == 'T' && s[j][k] == 'E') t += 'S';
        else if (s[i][k] == 'E' && s[j][k] == 'S') t += 'T';
        else if (s[i][k] == 'E' && s[j][k] == 'T') t += 'S';
        else if (s[i][k] == 'S' && s[j][k] == 'E') t += 'T';
        else t += 'E';
      }
      if (x.count(t)) {
        int idx = x[t];
        if (idx > i && idx > j) ans++;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
