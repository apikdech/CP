/**
 * author:  apikdech
 * created: 27.12.2019 21:43:23
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
    int x[3];
    for (int i = 0; i < 3; i++) {
      cin >> x[i];
    }
    sort(x, x+3);
    if (x[2] - 1 > x[0] + x[1]) cout << "No\n";
    else cout << "Yes\n";
  }
	return 0;
}
