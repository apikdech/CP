#include <bits/stdc++.h>
using namespace std;

bool check(long long k, long long n) {
	long long cur = n, ambil, sum = 0;
	while (cur > 0) {
		ambil = min(k, cur);
		sum += ambil;
		cur -= ambil;
		cur -= cur/10;
	}
	return sum * 2 >= n;
}

int main() {
	long long n;
	cin >> n;
	long long l = 1, r = n, ans = n;
	while (l <= r) {
		long long k = (l + r)/2;
		if (check(k, n)) {
			r = k - 1;
			ans = k;
		}
		else l = k + 1;
	}
	cout << ans << "\n";
	return 0;
}