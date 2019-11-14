#include <bits/stdc++.h> 
using namespace std;
#define ll long long 
#define f(i, a, b) for(ll i=a;i<b;i++)
#define fi(i, a, b) for(ll i=b-1;i>=a;i--)
#define pb push_back
#define VI vector<int>
#define Vll vector<long long>

class Graph
{
	int V;
	list<int> *adj;
public:
	Graph(int V);
	void addEdge(int v,int w);
	void BFS(int s);
	void DFS(int v);
	void DFSUtil(int v, bool visited[]);
};

Graph::Graph(int V)
{
	this->V=V;
	adj = new list<int>[V];
}

void Graph::DFSUtil(int v, bool visited[])
{
	visited[v]=true;
	cout<<v<<" ";
	list<int>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();i++)
		{
			if(!visited[*i])
			{
				visited[*i] = true;
				DFSUtil(*i, visited);
			}
		}
}

void Graph::DFS(int v)
{
	bool *visited = new bool[V];
	f(i,0,V) visited[i]=false;
	DFSUtil(v,visited);
}

void Graph::addEdge(int v,int w)
{
	adj[v].pb(w);
}

void Graph::BFS(int s)
{
	list<int> q;
	bool *visited = new bool[V];
	f(i,0,V){
		visited[i] =false;
	}
	visited[s] =true;
	q.pb(s);
	list<int>::iterator i;
	while(!q.empty())
	{
		s = q.front();
		cout<<s<<" ";
		q.pop_front();
		for(i=adj[s].begin();i!=adj[s].end();i++)
		{
			if(!visited[*i])
			{
				visited[*i] = true;
				q.pb(*i);
			}
		}
	}
		

}

int main() 
{ 
	int v,e;
	cin>>v>>e;
    Graph g(v);
	f(i,0,e)
	{
		int x,y;
		cin>>x>>y;
		g.addEdge(x,y);
	} 
    g.BFS(0); 
	cout<<"\n";
	g.DFS(0);
    return 0; 
} 