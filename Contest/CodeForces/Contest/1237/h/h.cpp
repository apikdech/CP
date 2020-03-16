/*
 * Author: apikdech
 * Time: 09:08:42 17-10-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		string a, b;
		vector<int> x, y, ans;
		cin >> a >> b;
		if (a == b) {
			cout << "0\n\n";
			continue;
		}
		int n = a.length(), x_nol = 0, x_satu = 0, x_dua = 0, y_nol = 0, y_satu = 0, y_dua = 0;
		for (int i = 0; i < n; i+=2) {
			if (a[i] == '0' && a[i+1] == '0') x_nol++;
			else if (a[i] == '0' && a[i+1] == '1') x_satu++;
			else if (a[i] == '1' && a[i+1] == '0') x_satu++;
			else x_dua++;
		}
		for (int i = 0; i < n; i+=2) {
			if (b[i] == '0' && b[i+1] == '0') y_nol++;
			else if (b[i] == '0' && b[i+1] == '1') y_satu++;
			else if (b[i] == '1' && b[i+1] == '0') y_satu++;
			else y.push_back(3), y_dua++;
		}
		if (x_nol != y_nol || x_satu != y_satu || x_dua != y_dua) cout << "-1\n";
		else {
			for (int j = n-2; j >= 0; j-=2) {
				int ok = 0, idx = 0;
				for (int i = j; i >= 0; i-=2) {
					if (i == j && a[i] == b[j] && a[i+1] == b[j+1]) {
						ok = 1;
						continue;
					}
					if (a[i] == b[j] && a[i+1] == b[j+1]) {
						ok = 1;
						if (i == 0) {
							if (a[i] == a[i+1]) ans.push_back(j+2), reverse(a.begin(), a.begin()+j+2);
							else ans.push_back(2), ans.push_back(j+2), reverse(a.begin(), a.begin()+2), reverse(a.begin(), a.begin()+j+2);
						}
						else ans.push_back(i+2), ans.push_back(j+2), reverse(a.begin(), a.begin()+i+2), reverse(a.begin(), a.begin()+j+2);
						break;
					} else if (a[i] == b[j+1] && a[i+1] == b[j]) idx = max(idx, i);
				}
				if (!ok) {
					if (idx == 0) ans.push_back(j+2), reverse(a.begin(), a.begin()+j+2);
					else ans.push_back(idx+2), ans.push_back(2), ans.push_back(j+2), reverse(a.begin(), a.begin()+idx+2), reverse(a.begin(), a.begin()+2), reverse(a.begin(), a.begin()+j+2);
				}
			}
			cout << ans.size() << "\n";
			for (int i = 0; i < (int)ans.size(); i++) {
				cout << ans[i] << " \n"[i == (int)ans.size() - 1];
			}
		}

	}
	return 0;
}
