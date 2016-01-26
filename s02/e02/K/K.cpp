#include <bits/stdc++.h>

using namespace std;

int n;
double a, t;

int main () {
	scanf("%d ", &n);

	int c = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lf", &a);
		if (a == 3.0)
			c++;
		t += a;
	}

	if (c) {
		printf("None\n");
	} else if (t == 5.0*n) {
		printf("Named\n");
	} else if (t >= 4.5*n) {
		printf("High\n");
	} else {
		printf("Common\n");
	}

}
