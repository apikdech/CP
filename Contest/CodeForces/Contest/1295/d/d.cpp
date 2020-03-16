/**
 * author:  apikdech
 * created: 29.01.2020 23:06:22
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

namespace factorBasic {
  template<class T> vector<T> factor(T x) { 
    vector<T> prime;
    for (T i = 2; i * i <= x; i++) if (x % i == 0) {
      while (x % i == 0) x /= i;
      prime.push_back(i);
    }
    if (x > 1) prime.push_back(x);
    return prime;
  }
  /* Note:
   * number of operations needed s.t.
   *          phi(phi(...phi(n)...))=1
   * is O(log n).
   * Euler's theorem: a^{\phi(p)}\equiv 1 (mod p), gcd(a,p)=1
   */
  template<typename T>
  T phi(T x) {
    for (auto &it : factor(x)) {
      x -= x/it;
    }
    return x;
  }
}
 
using namespace factorBasic;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    ll a, m, ans = 0, g = 0;
    cin >> a >> m;
    m /= __gcd(a, m);
    cout << phi(m) << "\n";
  }
  return 0;
}