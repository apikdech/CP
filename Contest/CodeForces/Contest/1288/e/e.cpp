/**
 * author:  apikdech
 * created: 15.01.2020 19:04:48
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 3e5 + 5;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
//Tree.find_by_order() returns an iterator to the k-th largest element (counting from zero).
//Tree.order_of_key() the number of items in a set that are strictly smaller than our item.

int mx[N], mn[N], a[N], last[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  iota(mn, mn + n, 0);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    mn[--a[i]] = 0;
  }
  Tree<pair<int, int>> ordered_set;
  for (int i = 0; i < n; i++) {
    mx[i] = i;
    ordered_set.insert({1, i});
    last[i] = 1;
  }
  for (int i = 0; i < m; i++) {
    mx[a[i]] = max(mx[a[i]], (int)ordered_set.order_of_key({last[a[i]], a[i]}));
    ordered_set.erase({last[a[i]], a[i]});
    ordered_set.insert({-i, a[i]});
    last[a[i]] = -i;
  }
  for (int i = 0; i < n; i++) {
    mx[i] = max(mx[i], (int)ordered_set.order_of_key({last[i], i}));
  }
  for (int i = 0; i < n; i++) {
    cout << mn[i] + 1 << " " << mx[i] + 1 << "\n";
  }
  return 0;
}
