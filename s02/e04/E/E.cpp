#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

map<ll,int> m; 
const int N = 2503;
int ans;

int n, vis[N], M[5*N];
ll v[N][2], val[5*N];
vector<int> adj[N];

bool dfs(int u){
	if(vis[u]) return false;
	vis[u] = true;
	vector<int>::iterator it;
	for(it = adj[u].begin(); it != adj[u].end(); it++){
		int v = *it;
		if(M[v] == -1 || dfs(M[v])){
			M[u] = v;
			M[v] = u;
			return true;	
		}
	}
	return false;
}

int main(){
	scanf("%d",&n);
	int k = n;
	for(int i = 0; i < n; i++){
		ll a, b;
		scanf("%lld %lld", &a, &b);
		v[i][0] = a; v[i][1] = b;
		if(!m[a+b]) m[a+b] = k, val[k++] = a+b;
		adj[i].pb(m[a+b]);
		if(!m[a-b]) m[a-b] = k, val[k++] = a-b;
		adj[i].pb(m[a-b]);
		if(!m[a*b]) m[a*b] = k, val[k++] = a*b;
		adj[i].pb(m[a*b]);
	}
	memset(M,-1,sizeof M);
	for(int i = 0; i < n; i++){
		memset(vis,0,sizeof vis);
		if(dfs(i)) ans++;
	}
	if(ans != n) puts("impossible");
	else {
		for(int i = 0; i < n; i++){
			printf("%lld ",v[i][0]);
			if(val[M[i]] == v[i][0]+v[i][1]) putchar('+');
			else if(val[M[i]] == v[i][0]-v[i][1]) putchar('-');
			else if(val[M[i]] == v[i][0]*v[i][1]) putchar('*');
			printf(" %lld = %lld\n",v[i][1],val[M[i]]);
			
		}	
	}


}
