#include <bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
const int N=1e7+5e6+10;
const int INF=0x3f3f3f3f;
int arr[maxn];
int cnt[N];
bool vis[N];

int main(){
	memset(vis,false,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	int n;
	scanf("%d",&n);
	int g=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		g=__gcd(g,arr[i]);
	}
	int maxi=0;
	for(int i=1;i<=n;i++){
		arr[i]/=g;
		cnt[arr[i]]++;
		maxi=max(maxi,arr[i]);
	}
	int ans=INF;
	for(int i=2;i<=maxi;i++){
		if(vis[i]) continue;
		int tmp=0;
		for(int j=i;j<=maxi;j+=i){
			vis[j]=true;
			tmp+=cnt[j];
		}
		ans=min(ans,n-tmp);
	}
	if(ans==INF) printf("-1");
	else printf("%d",ans);
	return 0;
} 