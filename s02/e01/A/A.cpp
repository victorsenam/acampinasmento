#include <bits/stdc++.h>
using namespace std;

const int N = 1600;

int n;
char str[N];
int visi[N][N];
int memo[N][N];
int res[N][N];

int pd( int i, int j ) {
	if (i >= j)
		return 0;
	int & me = memo[i][j];
	if (visi[i][j])
		return me;
	visi[i][j] = 1;

	if (i - j == 1) {
		res[i][j] = -1;
		me = (str[i] == str[j]);
		return me;
	}

	me = 0;
	if (str[i] == str[j]) {
		me = pd(i+1, j-1)+1;
		res[i][j] = -1;
	}
	pd(i+1, j);
	pd(i, j-1);
	
	int r = res[i+1][j];
	int l = res[i][j-1];

	if (l == -1 || r == -1 || r < l) {
		l = i; r = j-1;
	}

	for (int k = l; k <= r; k++) {
		if( pd(i, k) + pd(k+1, j) > me ) {
			me = pd(i, k) + pd(k+1, j);
			res[i][j] = k;
		}
	}
	return me;
}

void mount (int i, int j) {
	if (i >= j)
		return;
	
	if (res[i][j] == -1) {
		printf("%d %d\n", i+1, j+1);
		mount(i+1, j-1);
	} else {
		mount(i, res[i][j]);
		mount(res[i][j]+1, j);
	}
}

int main(){
	freopen("cable.in", "r", stdin);
	freopen("cable.out", "w", stdout);
	memset(res, -1, sizeof res);
	scanf("%d %s", &n, str);

	for (int d = 1; d < n; d++) {
		for (int i = 0; i < n-d; i++) {
			int j = i + d;
			int & me = memo[i][j];
			if (str[i] == str[j]) {
				me = 1+pd(i+1, j-1);
				res[i][j] = -1;
			}
			for (int k = i; k < j; k++) {
				if (memo[i][k] +memo[k+1][j] > me) {
					me = memo[i][k] + memo[k+1][j];
					res[i][j] = k;
				}
			}
		}
	}

	printf("%d\n", memo[0][n-1]);
	mount(0, n-1);
}
