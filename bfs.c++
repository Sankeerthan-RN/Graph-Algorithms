
#include<bits/stdc++.h>
using namespace std;
#define sz  1000
vector < int >adj[sz];
vector < int >vis;

void bfs (int x)
    
    {
      queue < int >q;
      q.push (x);
      vis[x] = 1;
      while (!q.empty ())
        {
          int u = q.front ();
    
          cout << u<<" ";
          q.pop ();
          for (int v = 0; v < adj[u].size (); v++)
    	 {
    	  int p = adj[u][v];
    	  if (!vis[p])
    	    {
    	      q.push (p);
    	      vis[p] = 1;
    	    }
    
    	  }
      }
    
    }

int main ()
{
  int n, m, u, v;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
    {
      cin >> u >> v;
      adj[u].push_back (v);
      adj[v].push_back (u);
 }

  vis.assign (n+1, 0);

  bfs (0);

}
