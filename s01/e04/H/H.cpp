#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+4;
int a[N], v[N], p[N];
multiset<int> s;
multiset<int>::iterator it;


int main(){
	freopen("hop.in","r",stdin);
	freopen("hop.out","w",stdout);
	int n, x, eu;
	scanf("%d %d",&n,&x);
	scanf("%d",&eu);
	for(int i = 0; i < n-1; i++) scanf("%d",a+i);
	for(int i = n-1; i >= 0; i--) {
		scanf("%d",p+i);
		s.insert(p[i]);
	}
	sort(a,a+n-1);
	int lo = 0, hi = n;
	while(lo != hi){
		int mid = (lo + hi)/2;
		int f = eu+p[mid], qt = 0;
		s.erase(s.find(p[mid]));
		for(int i = n-2; i >= 0; i--){
			it = s.upper_bound(f-a[i]);
			if(it == s.end()) it--;
			if(*it + a[i] > f) qt++;
			s.erase(it);
			v[i] = *it;
		}
		if(qt >= x){
			lo = mid+1;
		}
		else {
			hi = mid;
		}
		s.insert(p[mid]);
		for(int i = 0; i < n-1; i++) s.insert(v[i]);
	}
	printf("%d\n",lo != n ? n-lo : -1 );
} 
