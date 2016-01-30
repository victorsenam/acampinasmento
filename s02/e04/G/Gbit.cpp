#include <bits/stdc++.h>
using namespace std;
typedef long long num;

const int N = 220000;
const int T = 20*N;

int n;
int a[N], b[N], c[N], p[N], in;
int bit[N];

num ans;
int l, r, ts;
int x[T], y[T], lc[T], rc[T], sz[T];

void update(int t) {
    if(t == -1) return;
    sz[t] = 1;
    if(lc[t] != -1) sz[t] += sz[lc[t]];
    if(rc[t] != -1) sz[t] += sz[rc[t]];
}

int merge(int tl, int tr) {
    int ans = tl;
    if(min(tl,tr) == -1) return max(tl, tr);
    if(y[tl] > y[tr]) rc[tl] = merge(rc[tl], tr);
    else lc[ans=tr] = merge(tl, lc[tr]);
    update(ans);
    return ans;
}

void split(int t, int k) {
    if(t == -1) return (void)(r = l = -1);
    if(k < x[t]) split(lc[t],k), lc[t] = r, r = t;
    else         split(rc[t],k), rc[t] = l, l = t;
    update(t);
}

int insert(int t, int k) {
    split(t,k);
    x[ts] = k;
    lc[ts] = rc[ts] = -1;
    sz[ts] = 1;
    return merge(merge(l, ts++), r);
}

int queryt(int t, int k) {
    split(t, k);
    ans += num(l == -1? 0 : sz[l]);
    return merge(l,r);
}

void query(int idx, int z) {
    for(int i = idx; i > 0; i -= i&-i)
        bit[i] = queryt(bit[i],z);
}

void t_insert(int idx, int k) {
    for(int i = idx; i <= n; i += i&-i)
        bit[i] = insert(bit[i],k);
}

bool aLess(int i, int j) {
    return a[i] < a[j]; 
}

int main() {
    srand(time(NULL)); rand(); rand();

    scanf(" %d", &n);

    for(int i=0;i<=n;i++) bit[i] = -1;
    for(int i=0;i<20*n;i++) y[i] = i;
    random_shuffle(y, y + (20*n));

    for(int i=0;i<n;i++) {
        scanf(" %d", &in);
        a[--in] = i+1;
    }
    for(int i=0;i<n;i++) {
        scanf(" %d", &in);
        b[--in] = i+1;
    }
    for(int i=0;i<n;i++) {
        scanf(" %d", &in);
        c[--in] = i+1;
    }
    for(int i=0;i<n;i++) p[i] = i;
    sort(p, p+n, aLess);
    for(int i= 0;i < n; i++) {
        query(b[p[i]], c[p[i]]);
        t_insert(b[p[i]], c[p[i]]);
    }
    printf("%lld\n", ans);
}
