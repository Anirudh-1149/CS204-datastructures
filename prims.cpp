#include <bits/stdc++.h> 
using namespace std; 
#include <bits/stdc++.h> 
using namespace std;
#define ll long long 
#define f(i, a, b) for(ll i=a;i<b;i++)
#define fi(i, a, b) for(ll i=b-1;i>=a;i--)
#define pb push_back
#define VI vector<int>
#define Vll vecotr<long long>

int minKey(int key[], bool mstSet[],int V) 
{ 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (mstSet[v] == false && key[v] < min) 
			min = key[v], min_index = v; 

	return min_index; 
} 

void printMST(int parent[], vector<vector<int>> graph,int V1) 
{ 
	cout<<"Edge \tWeight\n"; 
	for (int i = 1; i < V1; i++) 
		cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n"; 
} 

void primMST(vector<vector<int>> graph,int V1) 
{ 
	int parent[V1]; 
	 
	int key[V1]; 
	
	bool mstSet[V1]; 

	for (int i = 0; i < V1; i++) 
		key[i] = INT_MAX, mstSet[i] = false; 

	key[0] = 0; 
	parent[0] = -1;

	for (int count = 0; count < V1 - 1; count++) 
	{ 
		int u = minKey(key, mstSet,V1); 

		mstSet[u] = true; 

		for (int v = 0; v < V1; v++) 
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
				parent[v] = u, key[v] = graph[u][v]; 
	} 

	printMST(parent, graph,V1); 
} 

int main() 
{ 
	int V1,E;
    cin>>V1>>E;
    vector<vector<int>> v(V1);
    f(i,0,V1)
    {
        v[i] = vector<int> (V1);
    }
    f(i,0,E)
    {
        int x,y,w;
        cin>>x>>y>>w;
        v[x][y] = v[y][x] =w;
    }
    primMST(v,V1);
    /*f(i,0,V1)
    {
        f(p,0,V1)
        {
            cout<<v[i][p]<<" ";
        }
        cout<<"\n";
    }*/

	return 0; 
} 

