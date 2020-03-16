#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 2e5 + 5;
int a[N];

struct BIT{
  vector<long long> dat;
  BIT(int sz) : dat(sz + 1) {}

  void update(int idx, long long val) {
  idx++;
    while(idx < dat.size()) {
      dat[idx] += val;
      idx += idx & -idx;
    }
  }

  long long query(int idx) {
    long long res = 0;
    while(idx > 0) {
      res += dat[idx];
      idx -= idx & -idx;
    }
    return res;
  }
  //call sum from [l, r) 0 indexed
  long long query(int l, int r) {
    return query(r) - query(l);
  }
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, t = 0, k = 0;
	ll T, ans = 0;
	cin >> n >> T;
	BIT bit1(2*n);
	BIT bit2(2*n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		bit1.update(i, 1);
		bit1.update(i+n, 1);
		bit2.update(i, a[i]);
		bit2.update(i+n, a[i]);
	}
	while(t < n) {
		ll s = bit2.query(k, k+n);
		if (s > T) {
			int l = k, r = k+n;
			while (r - l > 1) {
				int m = (l+r)/2;
				if (bit2.query(k, m) <= T) l = m;
				else r = m;
			}
			ans += bit1.query(k, l);
			T -= bit2.query(k, l);
			k = l % n;
			bit1.update(k, -1);
			bit1.update(k+n, -1);
			bit2.update(k, -a[k]);
			bit2.update(k+n, -a[k]);
			t++;
		}
		else {
			ans += (T/s)*bit1.query(k, k+n);
			T %= s;
		}
	}
	cout << ans << "\n";
	return 0;
}