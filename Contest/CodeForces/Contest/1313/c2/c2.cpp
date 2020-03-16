/**
 * author:  apikdech
 * created: 23.02.2020 16:43:26
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 5e5 + 5;
const int K = 26;

int m[N];
int n;

int lg[N];
int st[N][K];

void pre() {
  lg[1] = 0;
  for (int i = 2; i < N; i++) lg[i] = lg[i/2] + 1;
}

void sparse() {
  for (int i = 0; i < n; i++) {
    st[i][0] = a[i];
  }
  for (int j = 1; j < K; j++) {
    for (int i = 0; i + (1 << j) <= n; i++) {
      st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
}

ll query(int l, int r) {
  int j = lg[r - l + 1];
  ll res = min(st[l][j], st[r - (1 << j) + 1][j]);
  return res;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> m[i];
  }
  return 0;
}
