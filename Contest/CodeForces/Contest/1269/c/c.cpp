/**
 * author:  apikdech
 * created: 21.12.2019 18:55:58
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	string s, t = "";
	cin >> s;
	for (int i = 0; i < k; i++) {
		t += s[i];
	}
	for (int i = k; i < n; i++) {
		t += t[i - k];
	}
	if (t < s) {
		int ptr = k-1;
		if (t[ptr] != '9') {
			int num = t[ptr] - '0';
			num++;
			t[ptr] = num + '0';
			for (int i = k; i < n; i++) t[i] = t[i-k];
		} else {
			while(ptr >= 0 && t[ptr] == '9') {
				t[ptr] = '0';
				ptr--;
			}
			if (ptr >= 0) {
				int num = t[ptr] - '0';
				num++;
				t[ptr] = num + '0';
				for (int i = k; i < n; i++) t[i] = t[i-k];
			} else {
				t = '1' + t;
				for (int i = k; i <= n; i++) t[i] = t[i-k];
			}
		}
	}
	cout << t.length() << "\n";
	cout << t << "\n";
	return 0;
}
