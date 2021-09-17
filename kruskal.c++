#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 5;
int id[MAX];

void init()
{
    for(int i=0;i<MAX;i++)id[i]=i;

}
int root(int x)
{
    while(id[x]!=x)
    {
        id[x]=id[id[x]];
        x=id[x];
    }
    return x;
}
void combine(int x ,int y)
{
    int p=root(x);
    int q=root(y);
    id[p]=id[q];
}
int mst(vector<pair<int,pair<int,int>>>& p ,int m)
{
    int x,y;
    int cost,mincost=0;
    for(int i=0;i<m;i++)
    {
        x=p[i].second.first;
        y=p[i].second.second;
        cost=p[i].first;
        cout<<root(x)<<" " <<root(y)<<"\n";
        if(root(x)!=root(y))
        {
            mincost+=cost;
            combine(x,y);
        }
    }
    return mincost;
}

int main()
{
  
    int n,m;
    cin>>n>>m; //n is no of vertices ,  m is no of edges
    vector<pair<int,pair<int,int>>>edge(MAX);
    // pair <long long, pair<int, int> > edge[MAX];
    init();
    int u,v,w;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
      
        edge[i]=make_pair(w, make_pair(u, v));
    }
    sort(edge.begin(),edge.begin()+m);
  
    int ans= mst(edge,m);
    cout<<ans;
    
    
    
    return 0;
}