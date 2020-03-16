/**
 * author:  apikdech
 * created: 04.01.2020 19:07:30
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 25;

string s[N], t[N], x[N*N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < n*m; i++) {
    x[i] = s[i % n] + t[i % m];
  }
  int q;
  cin >> q;
  while(q--) {
    int y;
    cin >> y;
    y--;
    y %= n*m;
    cout << x[y] << "\n";
  }
  return 0;
}
