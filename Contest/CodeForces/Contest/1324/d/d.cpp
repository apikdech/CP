/**
 * author:  apikdech
 * created: 12.03.2020 20:35:50
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
//Tree.find_by_order() returns an iterator to the k-th largest element (counting from zero).
//Tree.order_of_key() the number of items in a set that are strictly smaller than our item.

ll a[N], b[N], v[N], ans = 0;
int cnt = 0;
Tree<pair<ll, int>> t;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    v[i] = a[i] - b[i];
  } 
  reverse(v, v + n);
  t.insert({-v[0], ++cnt});
  for (int i = 1; i < n; i++) {
    ans += t.order_of_key({v[i], 0});
    t.insert({-v[i], ++cnt});
  }
  cout << ans << "\n";
  return 0;
}
