#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPrime(ll n) 
{ 
	if (n <= 1) return false;
	if (n <= 3) return true;
    for (ll i=2; i<=sqrt(n); i++) 
        if (n%i == 0) 
           return false; 
  
    return true; 
} 

int main() {
	int t;
	cin >> t;
	// for (int i = 1; i <= 10; i++) cout << isPrime(i) << "\n";
	while(t--) {
		ll a, b;
		cin >> a >> b;
		ll p, q;
		p = a+b, q = a-b;
		if (q == 1) {
			if (isPrime(p)) cout << "YES\n";
			else cout << "NO\n";
			
		}
		else cout << "NO\n";
	}
	return 0;
}