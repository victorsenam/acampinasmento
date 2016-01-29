#include <bits/stdc++.h>

using namespace std;

typedef long long int num;

const int dx[4] = {0, 1, 0, 1};
const int dy[4] = {0, 0, 1, 1};

char str[40];
num x, y;

int main () {
	x = y = 0;
	int z = 0;
	scanf(" %s", str);

	for (int i = 0; str[i]; i++) {
		x <<= 1; y <<= 1;
		x += dx[str[i]-'0'];	
		y += dy[str[i]-'0'];	
		z++;
	}

	printf("%d %lld %lld\n", z, x, y);
}
