#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 4;

multiset<int> v;
int n,s,a;
int ans[N], k;

int main(){
	scanf("%d %d",&n,&s);
	for(int i = 0; i < n; i++){
		scanf("%d",&a);
		v.insert(a);
	}
	multiset<int>::iterator it;

	k = 0;
	int x, cnt = 0;
	while(v.size() > 1){
		it = v.begin();
		x = *it;
		ans[k++] = x;
		v.erase(it);
		x = ans[k-1];
		it = v.lower_bound(s-x+1);
		if(it == v.end()){
			it = v.begin();
			ans[k++] = *it;
			v.erase(it);
		}
		else {
			ans[k++] = *it;
			v.erase(it);
			cnt++;
		}
		cnt++;
	}
	if(v.size())
		ans[k++] = *(v.begin());
	printf("%d\n",cnt + v.size());
	for(int i = 0; i < n; i++) printf("%d ",ans[i]);
	printf("\n");

}
