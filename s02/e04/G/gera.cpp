#include <bits/stdc++.h>
using namespace std;

const int N = 200000;
int v[N];

int main(){
	srand(time(NULL));	
	for(int i = 0; i < N; i++) v[i] = i+1;
	printf("%d\n",N);
	random_shuffle(v, v+N);
	for(int i = 0; i < N; i++) printf("%d ",v[i]);
	putchar('\n');
	random_shuffle(v, v+N);
	for(int i = 0; i < N; i++) printf("%d ",v[i]);
	putchar('\n');
	random_shuffle(v, v+N);
	for(int i = 0; i < N; i++) printf("%d ",v[i]);
	putchar('\n');
}
