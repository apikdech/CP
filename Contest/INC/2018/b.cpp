#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt1[30], cnt2[30];

int main() {
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++) cnt1[a[i]-'a']++;
	for (int i = 0; i < b.length(); i++) {
		cnt1[b[i]-'a']--;
		if (cnt1[b[i]-'a'] < 0)  return cout << "NO\n", 0;
	}
	cout << "YES\n";
	return 0;
}