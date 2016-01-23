#include <bits/stdc++.h>
using namespace std;

const int N = 1500;

int main(){
	int n, v[N];
	while(scanf("%d",&n) && n){
		for(int i = 0; i < n; i++) scanf("%d",v+i);
		v[n++] = 1422;
		sort(v,v+n);
		bool ans = true;
		for(int i = 0; i < n-1; i++)
			if(v[i+1]-v[i] > 200) {
				ans = false;
				break;
			}

		if(2*(1422-v[n-2]) > 200) ans = false;
		if(ans) puts("POSSIBLE");
		else puts("IMPOSSIBLE");
	}
}
