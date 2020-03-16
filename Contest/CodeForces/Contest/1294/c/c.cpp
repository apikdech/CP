/**
 * author:  apikdech
 * created: 22.01.2020 21:56:36
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

vector<pair<ll, int>> factor(ll x) {
  vector<pair<ll,int>> prime;
  for (ll i = 2; i * i <= x; i++) if (x % i == 0) {
    int t = 0;
    while (x % i == 0) x /= i, t++;
    prime.push_back({i,t});
  }
  if (x > 1) prime.push_back({x,1});
  return prime;
}

ll powmod(ll a,ll b) {ll res=1; assert(b>=0); for(;b;b>>=1){if(b&1)res=(res*a);a=(a*a);}return res;}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    vector<pair<ll, int>> f = factor(n);
    if (f.size() >= 3) {
      cout << "YES\n";
      n /= f[0].first;
      n /= f[1].first;
      cout << f[0].first << " " << f[1].first << " " << n << '\n';
    } else if (f.size() == 2) {
      if (f[0].second == 1 && f[1].second == 1) cout << "NO\n";
      else if (f[0].second == 1 && f[1].second == 2) cout << "NO\n";
      else if (f[0].second == 2 && f[1].second == 1) cout << "NO\n";
      else {
        cout << "YES\n";
        if (f[0].second == 2 && f[1].second == 2) cout << f[0].first << " " << f[1].first << " " << f[0].first * f[1].first << "\n";
        else {
          n /= f[0].first;
          n /= f[1].first;
          cout << f[0].first << " " << f[1].first << " " << n << "\n";
        }
      }
    } else {
      if (f[0].second < 6)  cout << "NO\n";
      else {
        n /= f[0].first;
        n /= f[0].first;
        n /= f[0].first;
        cout << "YES\n";
        cout << f[0].first << " " << f[0].first * f[0].first << " " << n << '\n';
      }
    }
  }
  return 0;
}
