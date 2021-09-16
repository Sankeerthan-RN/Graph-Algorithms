#include<bits/stdc++.h>
using namespace std;
typedef vector<int> v;
typedef pair<int, int> pii;
int main()
{
    int x,y; // x - no of vertices ; y - no of edges 
    cin>>x>>y;
    vector<vector<pair<int ,int>>>p(x+1);
    int u,v,w;
    for(int i=0; i<y;i++)
    {
        
        cin>>u>>v>>w;
        p[u].push_back({v,w});
        p[v].push_back({u,w});
    }
    priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>>pq;
    vector<int>visited(x+2,0);
    int msp=0;
    visited[1]=1;
    for(auto u :p[1])
    {
        int v=u.first;
        int w=u.second;
        pq.push({w,{1,v}});
    }
    while(!pq.empty())
    {
         int w=pq.top().first; //weight
         int u=pq.top().second.first; // starting vertex
         int v=pq.top().second.second;  // ending vertex
         pq.pop();
         if(!visited[v])
         {
         	 cout<<u <<""<<v<<"\n";
             msp+=w;
             visited[v]=1;
             for(auto x :p[v])
             {
                 int new_vertex=x.first, new_weight=x.second;
                 if(!visited[new_vertex]){
                     pq.push({new_weight,{v,new_vertex}});
                    
                 }
             }
         }
    }
    cout<<msp<<"\n";

     
   return 0;
}