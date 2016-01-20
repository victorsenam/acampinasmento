#include <bits/stdc++.h>

using namespace std;

const int N = 507;

int a[N][N];
int g[N][N];
int n, k;
int memo[N][N];
bool visi[N][N];
int sol[N][N];

int pd (int i, int k) {
	if (i == n || k == 0)
		return 0;
	
	int & me = memo[i][k];
	if (visi[i][k])
		return me;
	visi[i][k] = 1;
	me = 0;

	for (int j = i+1; j < n-k+1; j++) {
		int val = g[j][j] - g[i][j] + pd(j,k-1);
		if (me <= val) {
			me = val;
			sol[i][k] = j;
		}
	}
	return me;
}

void solve (int i, int k) {
	if (i == n || k == 0)
		return;
	printf("%d ", sol[i][k]);
	solve(sol[i][k], k-1);
}


int main () {
	scanf("%d %d", &n, &k);

	for (int i = 1; i < n; i++)
		for (int j = i; j < n; j++)
			scanf("%d", &a[i][j]);

	for (int i = 1; i < n; i++)
		for (int j = n-1; j >= 0; j--)
			g[i][j] = g[i-1][j] + g[i][j+1] - g[i-1][j+1] + a[i][j];

	printf("%d\n", pd(0, k));
	solve(0, k);
	printf("\n");
}
