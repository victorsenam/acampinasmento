#include <bits/stdc++.h>

using namespace std;

struct vert {
	int u;
	int t;

	bool operator < (const vert & v) const {
		if (u == v.u)
			return t < v.t;
		return u < v.u;
	}
	
	bool operator == (const vert & v) const {
		return (u == v.u && t == v.t);
	}
};

const int N = 300007;

int hd[N], to[N], nx[N], nm[N], es;
int n, m;
vert v[N];
int edge[N][4];
vert aux;
int dest, mintime;
bool visi[N];
int res[N], rs;

int dfs (int u) {
	if (v[u].u == dest && v[u].t <= mintime)
		return 0;
	
	if (visi[u] == 1)
		return INT_MAX;
	visi[u] = 1;

	for (int ed = hd[u]; ed; ed = nx[ed]) {
		int val = dfs(to[ed]);
		if (val != INT_MAX) {
			if (nm[ed] != -1)
				res[rs++] = nm[ed];
			return val + (nm[ed] != -1);
		}
	}
	return INT_MAX;
}

int main () {
	scanf("%d %d", &n, &m);

	es = 2;
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j < 4; j++)
			scanf("%d", &edge[i][j]);

		if (i == m) {
			swap(edge[m][0], edge[m][1]);
			swap(edge[m][2], edge[m][3]);
		}

		v[i].u = edge[i][1];
		v[i].t = edge[i][3];
	}
	dest = edge[m][0];
	mintime = edge[m][2];


	sort(v, v+m+1);
	n = unique(v, v+m+1) - v;

	for (int i = 0; i < n-1; i++) {
		if (v[i].u != v[i+1].u)
			continue;

		nx[es] = hd[i]; hd[i] = es; to[es] = i+1; nm[es] = -1; es++;
	}

	for (int i = 0; i < m; i++) {
		aux.u = edge[i][0];
		aux.t = edge[i][2];
		int f = upper_bound(v, v+n, aux) - v - 1;
		if (f == -1 || v[f].u != aux.u) {
			continue;
		}
		aux.u = edge[i][1];
		aux.t = edge[i][3];
		int d = lower_bound(v, v+n, aux) - v;

		nx[es] = hd[f]; hd[f] = es; to[es] = d; nm[es] = i; es++;
	}

	aux.u = edge[m][1];
	aux.t = edge[m][3];
	int f = lower_bound(v, v+n, aux) - v;
	int ans = dfs(f);

	if (ans == INT_MAX) {
		printf("Impossible\n");
	} else {
		printf("%d\n", ans);
		for (int i = rs-1; i >= 0; i--) {
			printf("%d", res[i]+1);
			if (i)
				printf(" ");
			else
				printf("\n");
		}
	}

}
