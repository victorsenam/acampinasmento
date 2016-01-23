#include<bits/stdc++.h>
using namespace std;

int main(){
	multiset<int> s;
	s.insert(3);
	s.insert(3);
	printf("%d\n",s.size());
	s.erase(s.find(3));
	printf("%d\n",s.size());
}
