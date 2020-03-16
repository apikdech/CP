/**
 * author:  apikdech
 * created: 04.03.2020 21:35:11
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1005;

int a[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, m, sum = 0, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    cout << min(sum, m) << "\n";
  }
  return 0;
}
