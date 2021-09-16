#include<bits/stdc++.h>
using namespace std;


//adjacency list with wieghts
vector<vector<pair<int,int> > >graph;

void addedges(int u, int v, bool bidir,int w=0)
{
	graph[u].push_back(make_pair(v,w));
	if(bidir==true)
	{
		graph[v].push_back(make_pair(u,w));
	}
}
//vector of vectors
void display()
{
    
	for(auto i :graph)
	{
		for(auto j:i)
		{
			cout<<"("<<j.first<<","<<j.second<<")";
		}
	}
}

int main()
{
	int vertices,edges;
	cin>>vertices>>edges;
	graph.resize(vertices);
	int u,v,w;
	while(edges--)
	{
	  cin>>u>>v>>w;
	  addedges(u,v,true,w);
	}
	 display();
	
	
}
