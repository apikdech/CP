/*
 * Author: apikdech
 * Time: 23:00:37 17-05-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 2e5 + 5;
int a[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  ll ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
  	cin >> a[i];
  	if (a[i] < 0) a[i] *= -1;
  }
  sort(a, a+n);
  for (int i = 0; i < n; i++) {
  	int id = upper_bound(a, a+n, a[i]*2) - a;
  	// cerr << id << "\n";
  	id--;
  	if (id >= n) continue;
  	ans += (ll)id - (ll)i;
  }
  cout << ans << "\n";
	return 0;
}
