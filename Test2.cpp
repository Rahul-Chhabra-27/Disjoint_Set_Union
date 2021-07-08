#include<bits/stdc++.h>

using namespace std;
#define ll     long long int
#define endl   "\n"
#define ll     long long int

// Time complexity will be O(log *V);
ll find(int i ,vector<ll> &parent, vector<ll> &rank) {

    if(parent[i] == i){
        return i;
    }
    else {
        return parent[i] = find(parent[i],parent,rank);
    }
}
// Time complexity will be O(1)
void Union(int x,int y,vector<ll> &parent,vector<ll> &rank) {

    x = find(x,parent,rank);
    y = find(y,parent,rank);

    if(x != y) {

        if(rank[x] > rank[y]) {
            parent[y] = x;
            rank[x] += rank[y];
        }
        else {
            parent[x] = y;
            rank[y] += rank[x];
        }
    }
}
int main(int argc, char const *argv[])
{   
    int n;
    std::cin>>n;
    vector<ll> parent(n,0);
    for(int i = 0;i<n;i++)parent[i] = i;
    vector<ll> rank(n,1);
    Union(1,2,parent,rank);
    Union(4,3,parent,rank);
    Union(3,2,parent,rank);
    Union(0,4,parent,rank);
    for(auto el : parent) {
        cout<<el << " ";
    }
    cout<<endl;
    for(auto el : rank){
        cout<<el<<" ";
    }
    cout<<endl;
    return 0;
}
