#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long num;
typedef int node;
typedef int edge;

const int N = 1e6 + 7;

int id[N];
int to[N], fr[N], w[N], p[N];
int ans, cmp, n, m, es;

int find(node u)
{ return id[u] < 0? u : (id[u]=find(id[u])); }
int merge(node u, node v)
{
	if((u=find(u)) == (v=find(v))) return 0;
	if(id[u] < id[v]) swap(u,v);
	id[v] += id[u]; id[u] = v; return 1;
}
bool wLess(int i, int j)
{ return mp(w[i],i) < mp(w[j],j); }

int main()
{
	while(scanf(" %d%d", &n, &m) != EOF && n)
	{
		memset(id, -1, sizeof id);
		es = 0;
		cmp = n;
		while(m--)
		{
			node u, v;
			int c;
			scanf(" %d%d%d", &u, &v, &c);
			to[es] = u; fr[es] = v; w[es] = c;
			p[es] = es++;
		}
		sort(p, p+es, wLess);
		for(int i=0;i<es;i++)
		{
			cmp -= merge(to[p[i]], fr[p[i]]);
			if(cmp == 1)
			{
				ans = w[p[i]];
				break;
			}
		}
		if(cmp == 1) printf("%d\n", ans);
		else printf("IMPOSSIBLE\n");
	}
}
