#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
 
signed main()
{
    FastIO;
    int T;
    cin>>T;
    while(T--)
    {
        int n,x;
    	cin>>n>>x;
    	int dd,hh;
    	int max_d = 0, maxx_diff = -1;
    	for(int i=0; i<n; i++)
    	{
    		cin>>dd>>hh;
    		max_d = max(dd, max_d);
    		maxx_diff = max(maxx_diff, dd-hh);
    	}
 
    	if(max_d >= x)
    		cout<<1<<"\n";
    	else
    	{
    		if(maxx_diff <= 0)
    			cout<<"-1\n";
    		else
    		{
    			int curr = x, ans=1;
    			ans += (curr - max_d)/maxx_diff;
    			ans += (((curr - max_d)%maxx_diff) != 0);
    			cout<<ans<<"\n";
    		}
    	}
    }
}