/**
 * author:  apikdech
 * created: 07.03.2020 16:36:51
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
    vector<int> odd, even;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] % 2 == 0) even.push_back(i);
      else odd.push_back(i);
    }
    if (!even.empty()) {
      cout << "1\n";
      cout << even[0] + 1 << "\n";
    } else if (odd.size() > 1) {
      cout << "2\n";
      cout << odd[0] + 1 << " " << odd[1] + 1 << "\n";
    } else cout << "-1\n";

  }
  return 0;
}
