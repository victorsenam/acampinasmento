#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll n, tr, tp;

ll solve (ll p) {
	ll ds = 0;
	ll ps = 0;
	ll q = n;
	ll res = LLONG_MAX;

	while (q >= p) {
		ds++;
		ps += p-1;

		q = (q+p-1)/p;

		res = min(res, (ds+1)*tr + ((q-1)+ps)*tp);
	}

	if (q > 1) {
		ps += q-1;
		ds++;
	}

	return min(res, ds*tr + ps*tp);
}

int main () {
	scanf("%lld %lld %lld", &n, &tr, &tp);
	
	ll res = solve(2);
	for (int i = 3; i <= n; i++)
		res = min(res, solve(i));

	printf("%lld\n", res);
}
