#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 1e4 + 5, M = 55;
int a[M][N];

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int m, n;
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    int s;
    cin >> s;
    for (int j = 0; j < s; j++) {
      int x;
      cin >> x;
      a[i][x]++;
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = i+1; j < m; j++) {
      bool flag = 0;
      for (int k = 1; k <= n; k++) {
        if (a[i][k] == a[j][k] && a[i][k]) {
          flag = 1;
          break;
        }
      } if (!flag) return cout << "impossible\n", 0;
    }
  }
  cout << "possible\n";
  return 0;
}