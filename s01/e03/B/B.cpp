#include <bits/stdc++.h>

using namespace std;

const int N =100;

int n, t, s;
int c, d;

int main () {
	scanf("%d %d %d", &n, &t, &s);

	for (int i = 0; i < n; i++) {
		scanf("%d", &c);

		d = abs(s-c);

		printf("%.20f\n", double(max(c, s) + double(t-d)/2.0));
	}
}
