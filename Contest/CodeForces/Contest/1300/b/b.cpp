/**
 * author:  apikdech
 * created: 09.02.2020 21:26:29
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < 2*n; i++) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    sort(v.begin(), v.end());
    cout << v[n] - v[n-1] << "\n";
  }
  return 0;
}
