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
	if (n == 2)
		return tr+tp;

	if (visi[n])
		return memo[n];
	visi[n] = 1;
	memo[n] = LLONG_MAX;

	int lo = 2; int hi = n;

	while (lo < hi) {
		int q1 = lo + (hi-lo)/3;
		int q2 = hi - (hi-lo)/3;

		num r1 = pd((n+q1-1)/q1) + tr + tp*(q1-1);
		num r2 = pd((n+q2-1)/q2) + tr + tp*(q2-1);

		if (r1 > r2) {
			lo = q1+1;
		} else {
			hi = q2-1;
		}
	}

	memo[n] = pd((n+lo-1)/lo) + tr + tp*(lo-1);
	memo[n] = min(memo[n], pd((n+hi-1)/hi) + tr + tp*(hi-1));
	
	return memo[n];
}

int main () {
	scanf("%d %lld %lld", &n, &tr, &tp);
	printf("%lld\n", pd(n));
}
