#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll findParent(ll node,vector<ll>& par)
{
    if(par[node]==node)return node;
    return par[node]=findParent(par[node],par);
}
void Union(ll u,ll v,vector<ll> &size,vector<ll> &par)
{
    ll pu=findParent(u,par);
    ll pv=findParent(v,par);
    if(pu==pv)return;
    if(size[pu]<=size[pv])
    {
        par[pu]=pv;
        size[pv]++;
    }
    else
    {
        par[pv]=pu;
        size[pu]++;
    }
}
