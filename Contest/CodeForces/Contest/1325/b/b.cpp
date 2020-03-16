/**
 * author:  apikdech
 * created: 14.03.2020 21:40:45
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
    set<int> s;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      s.insert(x);
    }
    cout << s.size() << "\n";
  }
  return 0;
}
