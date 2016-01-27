#include <bits/stdc++.h>

using namespace std;

const int N = 107;
const int H = 107;
const int P = 107;

int hpp, hpe;
int gs, ps;
int vp[N], d[N][N], p[N][N];
int pe, de;
double tp[N][N][P];

int visi[H][H];
double memo[H][H];

double pd (int hpp, int hpe, bool ty) {
	if (hpe <= 0)
		return 1.;
	if (hpp <= 0)
		return 0.;

	if (ty) {
		double res =  (
			(double(pe)/100.)*pd(hpp-de, hpe, 0) + 
			(double(100.-pe)/100.)*pd(hpp, hpe, 0)
		);
	}

	double & res = memo[hpp][hpe];
	if (visi[hpp][hpe])
		return res;
    visi[hpp][hpe] = 1;

	res = 0.;
	for (int i = 0; i < gs; i++) {
		for (int j = 0; j < ps; j++) {
			double loc = 0.0;
			double pb = 0.0;

			pb = tp[i][j][0]*((100.-double(pe))/100.);
			loc += pd(hpp-de, hpe, 0)*tp[i][j][0]*(double(pe)/100.);
			
			for (int k = 1; k <= vp[i]; k++) {
				loc += tp[i][j][k]*pd(hpp, hpe-k*d[i][j], 1);
			}
			loc = loc/(1.-pb);

			res = max(res, loc);
		}
	}

	return res;
}

int main () {
	freopen("whats.in", "r", stdin);
	freopen("whats.out", "w", stdout);
	scanf("%d %d", &hpp, &hpe);
	scanf("%d %d", &gs, &ps);
	for (int i = 0; i < gs; i++) {
		scanf("%d", vp+i);
		for (int j = 0; j < ps; j++)
			scanf("%d %d", &p[i][j], &d[i][j]);
	}
	scanf("%d %d", &pe, &de);

	for (int i = 0; i < gs; i++) {
		for (int j = 0; j < ps; j++) {
			double pr = 1.0;
			for (int k = 0; k <= vp[i]; k++) {
				tp[i][j][k] = pr;
				pr *= (double(p[i][j])/100.);
			}

			pr = 1.0;
			for (int k = vp[i]; k >= 0; k--) {
				tp[i][j][k] *= pr;
				pr *= (double(100-p[i][j])/100.);
			}
		}
	}

	printf("%.20f\n", pd(hpp, hpe, 0));
}
