// TC(Build Tree) --> O(N)
// TC(Querying) --> O(log N)
// TC(Point Update) --> O(log N)
// v-->1, tl-->0, tl-->n-1 and t of size(4n) vi t(4*n)
#include<bits.stdc++.h>
#define ll long long int
usning namespace std;
void buildtree(vi& a, ll v, ll tl, ll tr,vi& t)
{
    if (tl == tr)t[v] = a[tl];
    else {ll tm = (tl + tr) / 2;
    buildtree(a, v*2, tl, tm,t);
    buildtree(a, v*2+1, tm+1, tr,t);
    t[v] = t[v*2] + t[v*2+1];
    }
}
ll rangedsum(ll v, ll tl, ll tr, ll l, ll r,vi& t)
{
    if (l > r) return 0;
    if (l == tl && r == tr) {return t[v];}
    ll tm = (tl + tr) / 2;
    return rangedsum(v*2, tl, tm, l, min(r, tm),t)+ rangedsum(v*2+1, tm+1, tr, max(l, tm+1), r,t);
}
void update(ll v, ll tl, ll tr, ll pos, ll new_val,vi& t) 
{
    if (tl == tr) {t[v] = new_val;} 
    else {ll tm = (tl + tr) / 2;
    if (pos <= tm) update(v*2, tl, tm, pos, new_val,t);
    else update(v*2+1, tm+1, tr, pos, new_val,t);
    t[v] = t[v*2] + t[v*2+1];
    }
}
