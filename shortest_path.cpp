#include <bits/stdc++.h> 
using namespace std;
#define ll long long 
#define f(i, a, b) for(ll i=a;i<b;i++)
#define fi(i, a, b) for(ll i=b-1;i>=a;i--)
#define pb push_back
#define VI vector<int>
#define Vll vecotr<long long

class Graph
{
	int V;
	list<int> *adj;
public:
	Graph(int V);
	void AddEdge(int v,int w);
	void Get_Path(int s,int d);
};

Graph::Graph(int V){
	this->V=V;
	adj= new list<int>[V];
}

void Graph::AddEdge(int v,int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph::Get_Path(int s,int d){
	int pred[V],dist[V];
	bool *visited = new bool[V];
	f(i,0,V)
	{
		visited[i] = false; 
        dist[i] = INT_MAX; 
        pred[i] = -1; 
	}

	list<int>queue;

	visited[s]=true;
	queue.push_back(s);
	dist[s]=0;
	list<int>::iterator i;
	int flag=1;
	while(!queue.empty())
	{
		int u=queue.front();
		queue.pop_front();
		for(i=adj[u].begin();i!=adj[u].end();i++)
		{
			if (visited[*i] == false) { 
                visited[*i] = true; 
                dist[*i] = dist[u] + 1; 
                pred[*i] = u; 
                queue.push_back(*i); 
                if (*i == d){
                	flag=0; 
                	break;
                   }
			}
		}
		if(!flag)
			break;
	}
	if(flag)
		cout<<"The vertecis are not connected";
	else
	{
		vector<int> path; 
    int crawl = d; 
    path.push_back(crawl); 
    while (pred[crawl] != -1) { 
        path.push_back(pred[crawl]); 
        crawl = pred[crawl]; 
    } 
  
    cout << "Shortest path length is : "<< dist[d]; 
  
    cout << "\nPath is::\n"; 
    for (int i = path.size() - 1; i >= 0; i--) 
        cout << path[i] << " "; 
	}
}

int main()
{
	int n,e;
	cin>>n>>e;
	Graph g(n);
	f(i,0,e)
	{
		int x,y;
		cin>>x>>y;
		g.AddEdge(x,y);
	}
	int src,dest;
	cin>>src>>dest;
	g.Get_Path(src,dest);
}