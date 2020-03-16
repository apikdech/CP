#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 2e5 + 5;
ll a[N];

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n, sum = 0, ans = 0, cnt, T, cur = 1;
  cin >> n >> T;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  ans += (T/sum)*n;
  T %= sum;
  while (cur > 0) {
    cur = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] <= T) {
        T -= a[i];
        cnt++, ans++;
        cur += a[i];
      }
    }
    if (cur > 0 && cur <= T) {
      ans += (T/cur)*cnt;
      T %= cur;
    }
  }
  cout << ans << "\n";
  return 0;
}