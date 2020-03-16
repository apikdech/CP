/**
 * author:  apikdech
 * created: 15.01.2020 19:27:07
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 3e5 + 5;

int l[N], r[N], pos[N], BIT[N << 1];

void update(int idx, int val) {
  for (int i = idx; i < N << 1; i += i & -i) {
    BIT[i] += val;
  }
}

int get(int idx) {
  int res = 0;
  for (int i = idx; i; i -= i & -i) {
    res += BIT[i];
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    l[i] = r[i] = i;
    pos[i] = m + i;
    update(pos[i], 1);
  }
  for (int i = m; i >= 1; i--) {
    int x;
    cin >> x;
    l[x] = 1;
    r[x] = max(r[x], get(pos[x]));
    update(pos[x], -1);
    pos[x] = i;
    update(pos[x], 1);
  }
  for (int i = 1; i <= n; i++) {
    r[i] = max(r[i], get(pos[i]));
    cout << l[i] << " " << r[i] << "\n";
  }
  return 0;
}
