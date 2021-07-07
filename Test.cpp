#include<bits/stdc++.h>

using namespace std;

#define ll   long long int
#define vi   vector<int> vi;
// find the leader of set
// Time complexity will be O(n);
int find(vector<ll> &parent,ll i) {

    if(parent[i] == i){
        return i;
    }
    else {
        return find(parent,parent[i]);
    }
}
// combine two sets or union two sets
// Time complexity will be O(n);
void Union(ll x,ll y,vector<ll> &parent) {

    x = find(parent,x);
    y = find(parent,y);
    if(x != y) 
     parent[y] = x;
}
int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;
    vector<ll> parent(n,0);
    for(int i = 0;i<n;i++)parent[i] = i;
    Union(1,2,parent);
    Union(3,4,parent);
    Union(1,3,parent);
    Union(0,4,parent);
    for(auto i : parent) {
        cout<< i << "\n";
    }
    return 0;
}
