/**
 * author:  apikdech
 * created: 09.03.2020 21:42:58
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 105;

int a[N];

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
    sort(a, a+n);
    reverse(a, a+n);
    for (int i = 0; i < n; i++) {
      cout << a[i] << " \n"[i + 1 == n];
    }
  }
  return 0;
}
