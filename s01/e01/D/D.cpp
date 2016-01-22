#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-9;

double h[2], t[2];


inline double sqr (double a)
{ return a*a; }

int main() { 
	for (int i = 0; i < 2; i++)
		scanf("%lf %lf", h+i, t+i);

	if (h[0] < h[1]) {
		swap(h[0], h[1]);
		swap(t[0], t[1]);
	}


	double lo = 0.0;
	double hi = t[1];

	while (hi - lo > eps) {
		double mid = .5*(hi+lo);

		double val = sqr((t[0] - mid)/(t[1]-mid));

		if (val - h[0]/h[1] > eps) {
			hi = mid;
		} else {
			lo = mid;
		}
	}

	printf("%.20f\n", lo);
}
