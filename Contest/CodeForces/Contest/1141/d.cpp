#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int N = 2e5;
pair<char, pair<int, bool>> a[N], b[N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, ptr = 0, aidx = 2e5, bidx = 2e5;
	vector<pair<int, int>> ans;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = {i, 0};
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i].first;
		b[i].second = {i, 0};
	}
	sort(a, a+n);
	sort(b, b+n);
	reverse(a, a+n);
	reverse(b, b+n);
	for (int i = 0; i < n; i++) {
		while(b[ptr].first > a[i].first && ptr < n) ptr++;
		if (a[i].first == '?' && !a[i].second.second) aidx = min(aidx, i);
		if (b[ptr].first == '?' && !b[ptr].second.second) bidx = min(bidx, ptr);
		if (a[i].first == '?' && b[ptr].first == '?') break;
		if ((a[i].first == b[ptr].first || a[i].first == '?' || b[ptr].first == '?') && ptr < n) {
			ans.push_back({a[i].second.first, b[ptr].second.first});
			a[i].second.second = b[ptr].second.second = 1;
			ptr++;
		}
	}
	ptr = 0;
	for (int i = aidx; i < n; i++) {
		while(b[ptr].second.second && ptr < n) ptr++;
		if (a[i].first == '?' && b[ptr].first == '?' && !a[i].second.second  && !b[ptr].second.second) {
			aidx = i;
			break;
		}
		if (b[ptr].second.second == 0 && ptr < n && a[i].second.second == 0) {
			ans.push_back({a[i].second.first, b[ptr].second.first});
			a[i].second.second = b[ptr].second.second = 1;
			ptr++;
		}
	}
	ptr = 0;
	for (int i = bidx; i < n; i++) {
		while(a[ptr].second.second && ptr < n) ptr++;
		if (a[ptr].first == '?' && b[i].first == '?' && !a[ptr].second.second && !b[i].second.second) {
			bidx = i;
			break;
		}
		if (a[ptr].second.second == 0 && ptr < n && b[i].second.second == 0) {
			ans.push_back({a[ptr].second.first, b[i].second.first});
			a[ptr].second.second = b[i].second.second = 1;
			ptr++;
		}
	}
	ptr = bidx;
	for (int i = aidx; i < n; i++) {
		if (ptr < n && a[i].second.second == 0 && b[ptr].second.second == 0) {
			ans.push_back({a[i].second.first, b[ptr].second.first});
			a[i].second.second = b[ptr].second.second = 1;
			ptr++;
		}
	}
	cout << ans.size() << "\n";
	for (auto it : ans) cout << it.first+1 << " " << it.second+1 << "\n";
	return 0;
}