#include <bits/stdc++.h>

using namespace std;

const int N = 300007;

int a[N], v[N];
int f[N], c[N], t[N], s[N];
int n;

int main () {
	freopen("gem.in", "r", stdin);
	freopen("gem.out", "w", stdout);
	scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", a+i);
			v[i] = a[i];
		}

		sort(v, v+n);
		int m = unique(v, v+n) - v;
		for (int i = 0; i < n; i++) {
			a[i] = lower_bound(v, v+m, a[i]) - v;
			t[a[i]]++;
		}

		int maxi = 0;
		for (int i = 0; i < n; i++) {
			f[a[i]]++;
			if (!c[a[i]] && a[i]) {
				if (c[a[i]-1] == t[a[i]-1])
					f[a[i]] = max(f[a[i]], f[a[i]-1]+1);
				f[a[i]] = max(f[a[i]], c[a[i]-1]+1);
			}

			c[a[i]]++;
			s[a[i]]++;
			s[a[i]] = max(s[a[i]], f[a[i]]);
			if (a[i]) {
				if (c[a[i]-1] == t[a[i]-1])
					s[a[i]] = max(s[a[i]], f[a[i]-1]+1);
				else
					s[a[i]] = max(s[a[i]], c[a[i]-1]+1);
			}
			maxi = max(maxi, s[a[i]]);

	//		printf("%d (%d,%d,%d)\n", a[i], f[a[i]], c[a[i]], t[a[i]]);
		}

		printf("%d\n", n-maxi);
}
