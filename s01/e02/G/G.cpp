#include <bits/stdc++.h>

using namespace std;

typedef long long int num;

struct ped {
	num x, y, z;
	
	bool operator < (const ped & ot) const {
		if (x != ot.x)
			return x < ot.x;
		if (y != ot.y)
			return y < ot.y;
		return z < ot.z;
	}
};

const int mv[6][3] = {
	{0, 0, 1},
	{0, 0, -1},
	{0, 1, 0},
	{0, -1, 0},
	{1, 0, 0},
	{-1, 0, 0}
};

int n;
num a, b, c;
set<ped> s;
ped aux, ott;

inline bool isval (ped & aux) {
	if (aux.x < 0 || aux.x >= a)
		return 0;
	if (aux.y < 0 || aux.y >= b)
		return 0;
	if (aux.z < 0 || aux.z >= c)
		return 0;
	return 1;
}

int main () {
	scanf("%d %d %d %d", &a, &b, &c, &n);

	num res = ((a*b+b*c+a*c)<<1);

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &aux.x, &aux.y, &aux.z);
		
		for (int k = 0; k < 6; k++) {
			ott = aux;

			ott.x += mv[k][0];
			ott.y += mv[k][1];
			ott.z += mv[k][2];

			if (s.count(ott) || !isval(ott)) {
				res--;
			} else {
				res++;
			}
		}
		s.insert(aux);
	}

	printf("%lld\n", res);
}
