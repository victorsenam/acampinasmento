#include <bits/stdc++.h>

using namespace std;

const int N = 3007;

struct pii {
	int a, b, v;

	pii () {}
	pii (int x, int y, int z) : a(x), b(y), v(z) {}

	bool operator < (const pii & ot) const {
		if (a != ot.a)
			return a < ot.a;
		if (b != ot.b)
			return b < ot.b;
		return v < ot.v;
	}
};

int n;
int x[N], y[N];
char c[N];
set<pii>::iterator it;
set<pii> xyl[N], yxl[N];
pii vals[2][N];


int main () {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d %c", x+i, y+i, c+i);
		vals[0][i] = pii(x[i], y[i], i);
		vals[1][i] = pii(y[i], x[i], i);
	}
	int maxi = 0;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			xyl[j].insert(vals[0][i]);
			yxl[j].insert(vals[1][i]);
		}
	}
	
	for (int j = 0; j < n; j++) {
		set<pii> &xy = xyl[j];
		set<pii> &yx = yxl[j];

		int res = 0;
		int k = j;

		while (xy.size()) {
			res++;
			if (c[k] == '>') {
				it = yx.find(vals[1][k]);
				++it;
				if (it == yx.end())
					break;
				if (it->a != y[k])
					break;
			} else if (c[k] == '<') {
				it = yx.find(vals[1][k]);
				if (it == yx.begin())
					break;
				--it;
				if (it->a != y[k])
					break;
			} else if (c[k] == 'v') {
				it = xy.find(vals[0][k]);
				++it;
				if (it == xy.end())
					break;
				if (it->a != x[k])
					break;
			} else {
				it = xy.find(vals[0][k]);
				if (it == xy.begin())
					break;
				--it;
				if (it->a != x[k])
					break;
			}
			xy.erase(vals[0][k]);
			yx.erase(vals[1][k]);
			k = it->v;
		}
		maxi = max(maxi, res);
	}
	printf("%d\n", maxi);
}
