/**
 * author:  apikdech
 * created: 03.02.2020 12:38:02
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5, INF = 2e9;

ll cost[N], a[N], seg[N << 2], lazy[N << 2], sum = 0, ans = INF;
int n, pos[N];

void build(int id = 1, int l = 0, int r = n) {
  if (r - l < 2) {
    seg[id] = a[l];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  seg[id] = min(seg[il], seg[ir]);
}

void push(int id) {
  int il = id << 1, ir = il | 1;
  seg[il] += lazy[id];
  seg[ir] += lazy[id];
  lazy[il] += lazy[id];
  lazy[ir] += lazy[id];
  lazy[id] = 0;
}

ll query(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || y <= l) return INF;
  if (x <= l && r <= y) return seg[id];
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id);
  return min(query(x, y, il, l, mid), query(x, y, ir, mid, r));
}

void update(int x, int y, int val, int id = 1, int l = 0, int r = n) {
  if (x >= r || y <= l) return;
  if (x <= l && r <= y) {
    seg[id] += val;
    lazy[id] += val;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id);
  update(x, y, val, il, l, mid);
  update(x, y, val, ir, mid, r);
  seg[id] = min(seg[il], seg[ir]);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pos[x] = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> cost[i];
  }
  for (int i = 0; i < n; i++) {
    sum += cost[i];
    a[i] = sum;
  }
  build();
  ans = min(ans, query(0, n-1));
  for (int i = 1; i <= n; i++) {
    update(pos[i], n, -cost[pos[i]]);
    update(0, pos[i], cost[pos[i]]);
    ans = min(ans, query(0, n-1));
  }
  cout << ans << "\n";
  return 0;
}
