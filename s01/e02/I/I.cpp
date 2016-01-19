#include <bits/stdc++.h>

using namespace std;

typedef long long int num;
const int N = 4007;

struct cvx {
	int ss;
	int a[N], b[N], s[N];

	void reset()
	{ ss = 0; }

	inline num numdiv (num a, num b) {
		return (a+b-1)/b;
	}

	num inter () {
		if (!ss)
			return LLONG_MIN;

		return numdiv(b[ss-1]-b[ss], a[ss]-a[ss-1]);
	}

	void insert (num va, num vb) {
		a[ss] = va;
		b[ss] = vb;
		s[ss] = inter();

		while (ss && s[ss] <= s[ss-1]) {
			a[ss-1] = a[ss];
			b[ss-1] = b[ss];
			--ss;
			s[ss] = inter();
		}
		ss++;
	}

	num get (num x) {
		if (!ss)
			return 0;

		int l = upper_bound(s, s+ss, x) - s - 1;
		return a[l]*x + b[l];
	}
};

int n, t;
num dp[2][N];
num d[N], p[N], f[N];
int p[N];
cvx trick;

bool cmp_p (int i, int j) {
	return f[i] < f[j];
}

int main () {
	scanf("%d %d", &n, &t);

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", d+i, v+i, f+i);
		p[i] = i;
	}

	sort(p, p+n, cmp_p);

	
	for (int at = 1; at <= t; at++) {
		int ty = (at&1);
		trick.reset();

		for (int i = 0; i < n; i++) {
			int u = p[i];

			if (t[u] > at)
				continue;

			pd[ty][i] = max(v[i], get(		
		}
	}
}
