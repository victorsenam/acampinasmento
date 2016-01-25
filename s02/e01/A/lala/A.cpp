#include <bits/stdc++.h>

using namespace std;

const int N = 1607;
int n;
char str[N];
int dp[N][N];
int lopt[N][N];
int ropt[N][N];

void printa(int l, int r) {
	//printf("call %d %d -> %d\n", l, r, opt[l][r]);
	if (l >= r)
		return;
	
	if (lopt[l][r] == -1) {
		printf("%d %d\n", l+1, r+1);
		printa(l+1, r-1);
	} else {
		printa(l, lopt[l][r]);
		printa(lopt[l][r]+1, r);
	}
}

int main () {
	freopen("cable.in", "r", stdin);
	freopen("cable.out", "w", stdout);
	scanf("%d", &n);
	scanf(" %s", str);

	if (n == 1) {
		printf("%d\n", 0);
	} else if (n == 2) {
		printf("%d\n", str[0] == str[1]);
		if (str[0] == str[1])
			printf("1 2\n");
	} else {
		for (int i = 0; i < n-1; i++) {
			if (str[i] == str[i+1]) {
				lopt[i][i+1] = ropt[i][i+1] = -1;
				dp[i][i+1] = 1;
			} else {
				lopt[i][i+1] = ropt[i][i+1] = i;
				dp[i][i+1] = 0;
			}
		}

		for (int d = 2; d < n; d++) {
			for (int i = 0; i < n-d; i++) {
				if (str[i] == str[i+d]) {
					lopt[i][i+d] = ropt[i][i+d] = -1;
					dp[i][i+d] = dp[i+1][i+d-1] + 1;
				} else {
					int l = lopt[i+1][i+d];
					if (l == -1)
						l = i;

					int r = ropt[i][i+d-1];
					if (r == -1)
						r = i+d-1;

					for (int k = l; k <= r; k++) {
						if (dp[i][i+d] < dp[i][k] + dp[k+1][i+d]) {
							lopt[i][i+d] = k;
							dp[i][i+d] = dp[i][k] + dp[k+1][i+d];
						} if (dp[i][i+d] == dp[i][k] + dp[k+1][i+d]) {
							ropt[i][i+d] = k;
						}
					}
				}
			}
		}

		printf("%d\n", dp[0][n-1]);
		printa(0, n-1);
	}
}
