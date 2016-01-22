#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000000;

int x, y;
int hi, lo;

bool read () {
	int a;
	scanf(" %d", &a);
	return a;
}

inline void printa (int x, int y) {
	printf("%d %d\n", x, y);
	fflush(stdout);
}

int main () {
	hi = MAX;
	lo = 0;
	y = 0;

	bool ch = 1;
	bool val;

	while (lo < hi) {
		printa(lo, y);
		val = read();

		x = lo + ((hi-lo)>>1);
		printa(hi, y);
		val = read();

		if (val) {
			lo = x+1;
		} else {
			hi = x;
		}
	}

	x = lo;

	lo = 0;
	hi = MAX;

	while (lo < hi) {
		printa(x, lo);
		val = read();

		y = lo + ((hi-lo)>>1);
		printa(x, hi);
		val = read();

		if (val) {
			lo = y+1;
		} else {
			hi = y;
		}
	}
	
	y = lo;

	printf("A %d %d\n", x, y);
	fflush(stdout);
	return 0;
}
