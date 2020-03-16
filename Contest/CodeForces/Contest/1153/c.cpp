#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (s[0] == ')' || s[n-1] == '(') return cout << ":(\n", 0;
	s.erase(s.begin());
	s.erase(s.end()-1);
	n--;
	for (int i = 0; i < n; i++) {
		
	}
	cout << s << "\n";
	return 0;
}