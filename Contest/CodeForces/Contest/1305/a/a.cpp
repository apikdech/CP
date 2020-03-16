/**
 * author:  apikdech
 * created: 03.03.2020 21:37:10
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 105;

int a[N], b[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    for (int i = 0; i < n; i++) {
      cout << a[i] << " \n"[i + 1 == n];
    }
    for (int i = 0; i < n; i++) {
      cout << b[i] << " \n"[i + 1 == n];
    }
  }
  return 0;
}
