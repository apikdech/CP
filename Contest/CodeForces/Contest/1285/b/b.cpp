/**
 * author:  apikdech
 * created: 10.01.2020 21:14:42
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;

ll a[N], sum, pref[N], suf[N];

void reset(int n) {
  for (int i = 0; i <= n+5; i++) suf[i] = pref[i] = 0;
  sum = 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n; 
    ll mpref = (ll)1e15, msuf = (ll)1e15, il = 0, ir = 0;
    reset(n);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum += a[i];
      pref[i] = pref[i-1] + a[i];
      if (mpref > pref[i]) mpref = pref[i], il = i;
    }
    for (int i = n; i >= 1; i--){
      suf[i] = suf[i+1] + a[i];
      if (msuf > suf[i]) msuf = suf[i], ir = i;
    }
    // cout << mpref << " " << il << " " << pref[il] << "\n";
    // cout << msuf << " " << ir << " " << suf[ir] << "\n";
    // cout << pref[ir-1] << " " << suf[il + 1] << " " << pref[ir - 1] - pref[il] << "\n";
    if (pref[ir - 1] >= sum || suf[il + 1] >= sum || pref[ir - 1] - pref[il] >= sum) cout << "NO\n";
    else cout << "YES\n";
  }
  return 0;
}
