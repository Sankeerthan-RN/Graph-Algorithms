#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>edge;

//Detecting   NEGATIVE EDGE CYCLE
bool bfd(int src,int n)
{
	vector<int>d(n);
	for(int i=0;i<n;i++)d[i]=INT_MAX;
	d[src]=0;
	for(int i=0;i<=n;i++){
		
			
		for(auto x:edge){
			
			int u=x[0];
			int v=x[1];
			int w=x[2];
			if(i<n){
				if(d[v]<INT_MAX){
					d[v]=min(d[v],d[u]+w);
				}
			}
			else{
				if(d[u]<INT_MAX){
					if(d[v]>d[u]+w)
					{
						cout<<"NEGATIVE EDGE CYCLE";
						return true;
					}
					
				}
			}
		}
	}
	return false;
}

//shortest path from source

vector<int> bf(int src,int n)
{
	vector<int>d(n);
	for(int i=0;i<n;i++)d[i]=INT_MAX;
	d[src]=0;
	for(int i=0;i<n;i++){
		
			
		for(auto x:edge){
			
			int u=x[0];
			int v=x[1];
			int w=x[2];
			
				if(d[u]<INT_MAX){
					d[v]=min(d[v],d[u]+w);
				}
			
			
			}
		}
		return d;
	}


int main() {
	int n,m,u,v,w;
	cin>>n>>m;
	// edge.resize(n+1);
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		edge.push_back({u,v,w});
	}
	
	bool res=bfd(0,n);
	if(!res){
	   cout<<"NO NEGATIVE EDGE CYCLE"<<"\n";
	   vector<int> dis=bf(0,n);
	   for(int i=0;i<n;i++)cout<<dis[i]<<"\n";
	}
	
	return 0;
}