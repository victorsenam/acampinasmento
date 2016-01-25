#include <bits/stdc++.h>
using namespace std;
typedef long long num;
typedef int node;
typedef int edge;

const int N = 1e5+3;
const int M = 2*N;
const int Q = 3e6+2;

int n;
int hd[N], root;
int to[M], nx[M], es;

int chain[N], anc[N], id[N], leaf[N], d[N], sz[N], tree[2*N], k[2*N];
int ps, ls;
int t_ans;

int dfs(node u, node p)
{
	int bst = 0, spc = u;
	sz[id[ps++] = u] = 1;
	d[u] = d[anc[u]=p] + 1;
	for(edge e=hd[u];e!=-1;e=nx[e])
		if(sz[to[e]] == 0)
		{
			sz[u] += dfs(to[e], u);
			if(sz[to[e]] > bst)
				bst = sz[to[e]], spc = to[e];
		}
	if(sz[u] == 1) leaf[ls++] = u;
	chain[u] = chain[spc] = u;
	return sz[u];
}

void build()
{
	dfs(root, root);
	for(int i=0;i<n;i++) chain[id[i]] = chain[chain[id[i]]];
	while(ls)
	{
		node u = leaf[--ls];
		while(u != chain[u])
		{
			id[u] = ps++;
			u = anc[u];
		}
		id[u] = ps++;
	}
	for(int i=n;i<2*n;i++)  k[i] = 1;
	for(int i=n-1;i>=0;--i) k[i] = k[i<<1] + k[i<<1|1];
}

int lazy[N], pend[N];

void force(int p, int x)
{
	tree[p] = k[p]*x;
	if(p < n) lazy[p] = x, pend[p] = 1;
}

void update(int p)
{
	if(p < 1) return;
	if(p < n)
	{
		if(pend[p]) tree[p] = k[p]*lazy[p];
		else tree[p] = tree[p<<1] + tree[p<<1|1];
	}
	update(p>>1);
}

void unlazy(int p)
{
	if(p < 1) return;
	unlazy(p>>1);
	if(p < n)
	{
		if(pend[p])
			force(p<<1, lazy[p]), force(p<<1|1, lazy[p]);
		pend[p] = 0;
	}
}

void force(int l, int r, int x)
{
	int il = l, ir = r;
	unlazy(il); unlazy(ir-1);
	for(;l<r;l>>=1,r>>=1)
	{
		if(l&1) force(l++, x);
		if(r&1) force(--r, x);
	}
	update(il); update(ir-1);
}

void query(int l, int r)
{
	int il = l, ir = r;
	t_ans = 0;
	unlazy(l); unlazy(r-1);
	for(;l<r;l>>=1,r>>=1)
	{
		if(l&1) t_ans += tree[l++];

		if(r&1) t_ans += tree[--r];
	}
}

void climb(node u)
{
	while(u != root)
	{
		force(id[u], id[chain[u]]+1, 1);
		u = anc[chain[u]];
	}
	force(id[u], id[u]+1, 1);
}

int q;
int main()
{
	freopen("genealogy.in", "r", stdin);
	freopen("genealogy.out", "w", stdout);
	scanf(" %d", &n);
	root = -1;
	memset(hd, -1, sizeof hd);
	for(node u=0;u<n;u++)
	{
		node v; scanf(" %d", &v); v--;
		if(v == -2) root = u;
		else
		{
			to[es] = v; nx[es] = hd[u]; hd[u] = es++;
			to[es] = u; nx[es] = hd[v]; hd[v] = es++;
		}
	}
	build();
	scanf(" %d", &q);
	while(q--)
	{
		int aux;
		force(n, 2*n, 0);
		scanf(" %d", &aux);
		while(aux--)
		{
			node u; scanf(" %d", &u);
			climb(--u);
		}
		t_ans = 0;
		query(n, 2*n);
		printf("%d\n", t_ans);
	}
}
