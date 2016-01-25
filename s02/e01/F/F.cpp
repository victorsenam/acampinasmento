#include <bits/stdc++.h>
using namespace std;
typedef long long num;

num n, nat, k, m, p, h;

int main(){
	freopen("scarf.in","r",stdin);
	freopen("scarf.out","w",stdout);
	scanf("%lld %lld %lld",&n,&k,&m);
	while(m--){
		scanf("%lld",&p);
		nat = n;
		h = 1; p--;
		for(num i = 0; i < k; i++){
			if(p < nat/4ll){
				h = (1ll<<(i+1)) -h + 1ll;
				p = nat/4ll - p-1ll;
			}
			else if(p >= 3ll*nat/4ll){
				p = nat/4ll + nat-p-1ll;
				h = (1ll<<(i+1)) -h + 1ll;
			}
			else{
				p -= nat/4ll;	
			}
			nat /= 2ll;
		}
		printf("%lld %lld\n",h,p+1);
	}
	
}
