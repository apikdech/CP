/**
 * author:  apikdech
 * created: 19.01.2020 20:50:52
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
  // ios::sync_with_stdio(0); cin.tie(0);
  int n;
  double ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    ans += 1.0/i;
  }
  printf("%.12f\n", ans);
  return 0;
}
