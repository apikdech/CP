#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int md = 1000000007;
ll N, T;
 
ll p(ll A, ll B) {
	if (B == 0) return 1;
	if (B == 1) return A % md;
 
	ll c = p(A, B / 2);
 
	if (B % 2 == 0) return (c * c) % md;
	return (A * ((c * c) % md)) % md;
}
 
int main() {
	cin >> T;
	
 
	vector<ll> F;
	F.push_back(1LL);
	F.push_back(1LL);
 
	while (F[F.size() - 1] <= 100000000) {
		F.push_back(F[F.size() - 1] + F[F.size() - 2]);
	}
	//cout << F[F.size()-1] << "\n";
 
	while (T--) {
		cin >> N;
 		//cout << F.size() << " \n";
		bool yey = false;
		for (int i = 0; i < F.size(); i++) {
			if (F[i] > 10 and F[i] == N) {
				yey = true;
				break;
			}
		}
 
		if (yey) cout << "YEY\n";
		else cout << (p(2, N + 1) + 2) % md << endl;
	}
}