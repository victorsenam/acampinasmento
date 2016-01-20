#include <bits/stdc++.h>
using namespace std;

const int N = 507;

int n, k;
int c[N];
int a[N];

bool cmp_c (int i, int j)
{ return c[i] < c[j]; }

int main( ){
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		int acc = 0;
		for (int j = i+1; j < n; j++) {
			scanf("%d", a+j);
			acc += a[j];
		}
		
		for (int j = i+1; j < n; j++) {
			c[j] += acc;
			acc -= a[j];
		}
	}

	for (int i = 0; i < n; i++)
		a[i] = i;
	sort(a, a+n, cmp_c);

	int res = 0;
	for (int i = n-1; i >= n-k; i--) {
		res += c[a[i]];
	}

	sort(a+n-k, a+n);

	
	printf("%d\n", res);
	for (int i = n-k; i < n; i++) {
		printf("%d", a[i]);
		if (i < n-1)
			printf(" ");
	}
	printf("\n");
}
