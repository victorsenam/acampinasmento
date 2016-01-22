#include <bits/stdc++.h>

using namespace std;

const int N = 200007;
const int M = 400007;

priority_queue<pair<int, int> > pq;
int n, m;
int hd[N], nx[M], to[M], es;
bool us[N];
int inp[N];
int pri[N];
bool visi[N];

int dfs (int u) {
	if (visi[u])
		return pri[u];

	visi[u] = 1;
	pri[u] = u;

	for (int ed = hd[u]; ed; ed = nx[ed])
		pri[u] = min(dfs(to[ed]), pri[u]);
	return pri[u];
}

int main () {
	scanf("%d %d", &n, &m);

	es = 2;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		nx[es] = hd[a]; hd[a] = es; to[es] = b; es++;
		inp[b]++;
	}
	
	for (int i = 0; i < n; i++)
		dfs(i);

	for (int i = 0; i < n; i++)
		if (inp[i] == 0)
			pq.push(make_pair(-pri[i], i));

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		if (us[u]) {
			continue;
		}

		printf("%d ", u+1);
		us[u] = 1;

		for (int ed = hd[u]; ed; ed = nx[ed]) {
			int v = to[ed];

			inp[v]--;
			if (inp[v] == 0)
				pq.push(make_pair(-pri[v], v));
		}
	}
	printf("\n");
}
