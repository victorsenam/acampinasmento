#include <bits/stdc++.h>

using namespace std;

typedef long long int num;
const int N = 100007;

int hd[N], nx[2*N], to[2*N], es;
num sz[N];
num res[N];

num dfs (int u, int fr) {
	sz[u] = 1;
	for (int ed = hd[u]; ed; ed = nx[ed]) {
		if (ed == (fr^1))
			continue;
		sz[u] += dfs(to[ed], ed);
	}
	res[u] = sz[u]+1;
	for (int ed = hd[u]; ed; ed = nx[ed]) {
		if (ed == (fr^1))
			continue;
		res[u] += (sz[u] - sz[to[ed]])*sz[to[ed]];
	}
	return sz[u];
}

int n;
int main () {
	freopen("lca.in", "r", stdin);
	freopen("lca.out", "w", stdout);
	scanf("%d", &n);

	es = 2;
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;

		nx[es] = hd[a]; hd[a] = es; to[es] = b; es++;
		nx[es] = hd[b]; hd[b] = es; to[es] = a; es++;
	}

	dfs(0, -1);
	num maxi = -1;
	int qtd=  0;
	
	for (int i = 0; i < n; i++) {
		if (res[i] > maxi) {
			maxi = res[i];
			qtd = 1;
		} else if (res[i] == maxi)
			qtd++;
	}
	printf("%d\n", qtd);
	for (int i = 0; i < n; i++)
		if (res[i] == maxi)
			printf("%d ", i+1);
	printf("\n");
}
