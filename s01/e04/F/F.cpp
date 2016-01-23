#include <bits/stdc++.h>

using namespace std;

int t, n, k;

int main (){ 
	freopen("foss.in", "r", stdin);
	freopen("foss.out", "w", stdout);
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &k);

		if (k == 3) {
			printf("1\n0 0\n1 0\n0 1\n");
		} else if (k == 4) {
			printf("4\n0 0\n1 0\n1 1\n0 1\n");
		} else if (k == 5) {
			printf("3\n2 0\n0 0\n0 2\n2 2\n3 1\n");
		} else {
			printf("%d\n", (k-4)/2 + 4);

			n = (k>>1);
			printf("0 0\n");
			for (int i = 1; i < n; i++) {
				printf("%d %d\n%d %d\n", ((i-1)<<1), (i<<1), (i<<1), (i<<1));
				if ((k&1) && i == 1)
					printf("1 3\n");
			}
			printf("%d %d\n", ((n-1)<<1), 0);
		}
	}

}
