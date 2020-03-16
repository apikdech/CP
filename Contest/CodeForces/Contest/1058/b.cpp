#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double grad(int x1, int y1, int x2, int y2) {
	return (y2-y1)*1.0/(x2-x1);
}

int main() {
	int n, d;
	cin >> n >> d;
	double g = grad(0, d, n-d, n);
	int q;
	cin >> q;
	while(q--) {
		int x, y;
		bool ans;
		cin >> x >> y;
		if ((x + y) >= d && ((x - y) <= d) && ((x - y) >= -d) && (x + y) <= (2*n-d)) ans = 1;
		else ans = 0;
		puts (ans ? "YES" : "NO");
	}
	return 0;
}


// dx + dy > 0
// dx > dy
// 2x + 2y = 0
// 2x + 2y > 0

// x > -y
// translasi sebesar n-d

// 2x + 2y < 0

// x - y + d> 0

// n-d , d

// y - y1 = m(x - x1) + c


// y = mx + c

// m = dy = n-d dx = n - d translasi kebawah sebesar d

// jadinya x + y < d

// y = mx + c
// m = -1

// y = -x + c
// x + y = 0
