#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	if (n > 2) {
		cout << "Yes\n";
		cout << "1 " << n << "\n";
		cout << n-1 << " ";
		for (int i = 1; i < n; i++) cout << i << " ";
	}
	else cout << "No\n";
	return 0;
}

//misal angkanya 1 2 3 4 kita ambil 4 sum 1 to 3 itu kan 3(1+3)/2 nah itu pasti udah 