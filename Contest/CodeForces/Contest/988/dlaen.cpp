#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
// #ifdef _DEBUG
// 	freopen("input.txt", "r", stdin);
// //	freopen("output.txt", "w", stdout);
// #endif
	
	int n, ok = 0;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	
	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	vector<int> res = { x[0] };
	
	for (int i = 0; i < x.size(); ++i) {
		for (int j = 0; j < 31; ++j) {
			int lx = x[i] - (1 << j);
			int rx = x[i] + (1 << j);
			bool isl = binary_search(x.begin(), x.end(), lx);
			bool isr = binary_search(x.begin(), x.end(), rx);
			if (isl && isr && int(res.size()) < 3) {
				res = { lx, x[i], rx };
				ok = 1;
				break;
			}
			if (isl && int(res.size()) < 2) {
				res = { lx, x[i] };
			}
			if (isr && int(res.size()) < 2) {
				res = { x[i], rx };
			}
		} if (ok) break;
	}
	
	cout << int(res.size()) << endl;
	for (auto it : res)
		cout << it << " ";
	cout << endl;
	
	return 0;
}