#include <bits/stdc++.h>

using namespace std;

const int N = 30;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m;
char mat[N][N];
bool visi[N][N];
int ns, es;
int res[N][2];

void dfs (int u, int d, int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= m)
		return;
	
	if (mat[i][j] == 79) {
		res[es][0] = u;
		res[es++][1] = ++ns;
		int att = ns;
		for (int k = 0; k < 4; k++) 
			if (k != (d^1))
				dfs(att, k, i+dx[k], j+dy[k]);
	} else if( mat[i][j] == 124 && d < 2) {
		dfs(u, d, i+dx[d], j+dy[d]);
	} else if( mat[i][j] == 45 && d >= 2) {
		dfs(u, d, i+dx[d], j+dy[d]);
	} else if (mat[i][j] == 43) {
		dfs(u, (d^2), i+dx[d^2], j+dy[d^2]);
		dfs(u, (d^3), i+dx[(d^3)], j+dy[(d^3)]);
	}
}

int main () {
	//freopen("picture.in", "r", stdin);
	freopen("picture.out", "w", stdout);
	scanf("%d %d", &n, &m);
	int pi = -1;
	int pj = -1;
	for (int i = 0; i < n; i++) {
		scanf("%c", &mat[i][0]);
		for (int j = 0; j < m; j++) {
			scanf("%c", &mat[i][j]);
			if (mat[i][j] == 79) {
				pi = i; pj = j;
			}
		}
	}

	if (pi == -1 || pj == -1) {
		printf("0\n");
		return 0;
	}

	ns = 1;
	es = 0;
	for (int k = 0; k < 4; k++)
		dfs(1, k, pi+dx[k], pj+dy[k]);

	printf("%d\n", ns);
	for (int i = 0; i < es; i++)
		printf("%d %d\n", res[i][0], res[i][1]);
}
