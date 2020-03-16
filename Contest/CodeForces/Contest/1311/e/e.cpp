/**
 * author:  apikdech
 * created: 27.02.2020 08:53:32
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 5005;

int pref[N];

void pre() {
  for (int i = 2; i < N; i++) {
    pref[i] = pref[i-1] + 31 - __builtin_clz(i);
  }
}

vector<int>

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  pre();
  int t;
  cin >> t;
  while(t--) {
    int n, d;
    cin >> n >> d;
    if (d < pref[n] || d > n * (n - 1) / 2) cout << "NO\n";
    else {
      cout << "YES\n";
      vector<int> p = build();
    }
  }
  return 0;
}
