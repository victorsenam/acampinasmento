#include <bits/stdc++.h>

using namespace std;

const int N = 1007;

double x[N], y[N], r[N];
int uf[N], wf[N];
int n;
int p[N];
double maxy[N], miny[N];

int find (int i) {
	if (uf[i] == i)
		return i;
	return uf[i] = find(uf[i]);
}

void join (int i, int j) {
	i = find(i); j = find(j);
	if (i == j)
		return;
	if (wf[i] < wf[j])
		swap(i, j);
	wf[i] += wf[j];
	uf[j] = i;
}

int main () {
	memset(uf, -1, sizeof uf);
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lf %lf %lf", x+i, y+i, r+i);
		for (int j = 0; j < i; j++)
			if (dist(i, j) <= r[i] + r[j])
				join(i, j);
		if (y[i] - r[i] <= 0.)
			join(i, n);
		if (y[i] + r[i] >= 1000.)
			join(i, n+1);
	}
	
	for (int i = 0; i < n; i++) {
		maxy[find(i)] = max(maxy[find(i)], 0.0);
		miny[find(i)] = min(miny[find(i)], 0.0);
		p[i] = find(i);
	}

	sort(p, p+n);
	int m = unique(p, p+n) - p;

	for (int i = 0; i < n; i++) {
			
	}
}
