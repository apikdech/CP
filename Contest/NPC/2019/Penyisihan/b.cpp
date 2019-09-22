#include <bits/stdc++.h>
using namespace std;

long long power(long long base, long long exponent, long long m)
{
	long long result = 1;
	base = base % m;
	while (exponent > 0)
	{
		if (exponent % 2 == 1)
		result = (result * base)% m;
		exponent = exponent >> 1;
		base = (base * base) % m;
	}
	return result;
}

long long ord(long long n){
    long long p=0;
    for(long long i=2; i<=sqrt(n); i++){
        if(n%i==0){
            p=i;
            break;
        }
    }
    return (p-1)*(n/p -1 );
}

long long phi(long long n) {
    long long result = n;

    for (long long p = 2; p * p <= n; ++p) {

        if (n % p == 0) {

            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }

    if (n > 1)
        result -= result / n;
    return result;
}

int main()
{
	int t;
	cin >> t;
	while(t--){
        long long c, e, n;
        cin >> c >> e >> n;
        long long order = ord(n);
        long long piii = phi(order);
        long long d = power(e, piii-1, order);

        long long ans = power(c, d, n);
        cout << ans << "\n";
	}
}
