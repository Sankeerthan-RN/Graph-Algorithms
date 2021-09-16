
#include<bits/stdc++.h>
using namespace std;
#define sz  1000
vector < int >adj[sz];
vector < int >vis;



 void dfs (int u)
    {
      vis[u] = 1;
      cout << u << " ";
      for (int v = 0; v < adj[u].size (); v++)
        {
          int p = adj[u][v];
          if (!vis[p])
    	{
    
    	  dfs (p);
    	}
    
        }
    
    }



int
main ()
{
  int n, m, u, v;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
    {
      cin >> u >> v;
      adj[u].push_back (v);
      adj[v].push_back (u);
 }

  vis.assign(n+1,0); 
  dfs (1);
  cout << "\n\n";
 
}
