#include <bits/stdc++.h>
using namespace std;

long long a, m, s, res;
long long v[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
long long ans[15], ac[15];

inline long long q(){
	long long ret = v[m];
	if(m == 2){
		if(a%400 == 0) ret++;
		else if(a%100 && a%4 == 0) ret++;
	}
	return ret;
}

inline void fix(int f){
	m++;
	if(m == 13) {
		m = 1;
		a++;
		if(f) ans[res]++;
		res = 0;
	}
}

int main(){
	a = 1919;
	m = 1;
	s = 1;
	
	long long A, B;
	scanf("%lld %lld",&A,&B);

	while(a+400ll <= A) a += 400ll;

	while (a<A){
		s += q();
		s%=7;
		fix(0);
	}
	long long qt = 0;
	while(a+400ll<=B) a += 400ll, qt++;

	while(a <= B){
		if(s==5) res++;
		s += q();
		s %= 7;
		fix(1);
	}
	ac[1] = 171, ac[2] = 170, ac[3] = 59;
	for(int k = 0; k < 13; k++)
		printf("%d: %lld\n",k,ans[k]+qt*ac[k]);

}
