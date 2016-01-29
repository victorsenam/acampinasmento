#include <bits/stdc++.h>

using namespace std;

const int N = 1000007;

typedef long long int num;

int n;
num tr, tp;
num memo[N];
int visi[N];

num pd (num n) {
	if (n == 1)
		return 0;

	if (visi[n])
		return memo[n];
	visi[n] = 1;
	memo[n] = LLONG_MAX;

	for (num i = 2; i <= n; i++)
		memo[n] = min(memo[n], pd((n+i-1)/i) + tr + (i-1)*tp);
	return memo[n];
}

int main () {
	scanf("%d %lld %lld", &n, &tr, &tp);
	printf("%lld\n", pd(n));
}
