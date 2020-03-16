#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 2e5 + 5;
vector<int> ans;
deque<int> v;
string res = "";

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	if (v.front() > v.back()) {
		ans.push_back(v.back());
		res += "R";
		v.pop_back();
	} else {
		ans.push_back(v.front());
		res += "L";
		v.pop_front();
	}
	while(true) {
		if (v.front() >= v.back()) {
			if (ans.back() < v.back()) {
				ans.push_back(v.back());
				v.pop_back();
				res += "R";
			} else if (ans.back() < v.front()) {
				ans.push_back(v.front());
				v.pop_front();
				res += "L";
			} else break;
		} else if (v.front() <= v.back()) {
			if (ans.back() < v.front()) {
				ans.push_back(v.front());
				v.pop_front();
				res += "L";
			} else if (ans.back() < v.back()) {
				ans.push_back(v.back());
				v.pop_back();
				res += "R";
			} else break;
		} else break;
		if (v.empty()) break;
	}
	cout << ans.size() << "\n";
	cout << res << "\n";
	return 0;
}