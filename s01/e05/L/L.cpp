#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6+4;

int n;
long long ans = 0, bit[N], c[N], v[N];

ll query(int idx){
	ll sum = 0;
	for(int i = idx; i > 0; i -= i&-i)
		sum += bit[i];
	return sum;
}

void update(int idx, ll val){
	for(int i = idx; i <= n; i += i&-i)
		bit[i] += val;
}

int main(){
	scanf("%d",&n);
	int a;
	for(int i = 0; i < n; i++){
		scanf("%lld",v+i);
		c[i] = v[i];
	}

	sort(c, c+n);
	int m = unique(c, c+n) - c;

	for (int i = 0; i < n; i++)
		v[i] = lower_bound(c, c+m, v[i]) - c + 1;

	for(int i = 0; i < n; i++){
		ans += ll(i)-query(v[i]);
		update(v[i],1);
	}
	printf("%lld\n",ans);
}
