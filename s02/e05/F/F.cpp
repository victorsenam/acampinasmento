#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
typedef long long ll;

int l;
ll memo[N][N][2][2];

ll pd(int i, int r, int o, int c){
	if(r < 0) return 0;
	if(i == l) return ((r == 0)&&(!(c&&o)));
	ll &me = memo[i][r][o][c];
	if(me != -1) return me;
	me = 0;
	if (i == 0) {
		me += pd(i+1,r-1,0,0);
		me += pd(i+1,r,1,1);
	} else {
		me += pd(i+1,r-1,0,c);
		if(!o) me += pd(i+1,r,1,c);
	}
	return me;
}

int main(){
	int tc = 1;
	//freopen("museum.in","r",stdin);
	while(scanf("%d",&l) && l){
		memset(memo,-1,sizeof memo);
		printf("Case %d: ",tc++);
		if(l < 4 || l%2) printf("0\n"); 	
		else printf("%lld\n",pd(0,(l+4)/2,0,0));
	}
}
