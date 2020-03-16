#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ll a, b, lim = 0;
	cin >> a >> b;
	ll l = 0, r = 1e10;
	while(l < r) {
		ll m = (l + r)/2;
		if ((m * (m + 1))/2 == a + b) {
			lim = m;
			// cout << "HEHE\n";
			break;
		}
		if ((m * (m + 1))/2 > a + b) r = m - 1;
		else l = m + 1, lim = m;
	}
	vector<int> p, q;
	bool cnt[lim+5];
	memset(cnt, 0, sizeof cnt);
	int res = 0, ptr = 1;
	while(res < min(a, b)) {
		if (ptr > lim) break;
		if (!cnt[ptr]) {
			res += ptr;
			cnt[ptr] = 1;
			ptr++;
			p.push_back(ptr);
		}
	}
	res = 0;
	while(res < max(a, b)) {
		if (ptr > lim) break;
		if (!cnt[ptr]) {
			res += ptr;
			ptr++;
			cnt[ptr] = 1;
			q.push_back(ptr);
		}
	}
	if (a < b) {
		cout << p.size() << "\n";
		for (int i = 0; i < p.size(); i++) {
			cout << p[i];
			if (i != p.size()-1)cout << " ";
			else cout << "\n";
		}
		cout << q.size() << "\n";
		for (int i = 0; i < q.size(); i++) {
			cout << q[i];
			if (i != q.size()-1)cout << " ";
			else cout << "\n";
		}
	}
	else {
		cout << q.size() << "\n";
		for (int i = 0; i < q.size(); i++) {
			cout << q[i];
			if (i != q.size()-1)cout << " ";
			else cout << "\n";
		}
		cout << p.size() << "\n";
		for (int i = 0; i < p.size(); i++) {
			cout << p[i];
			if (i != p.size()-1)cout << " ";
			else cout << "\n";
		}
	}
	return 0;
}
