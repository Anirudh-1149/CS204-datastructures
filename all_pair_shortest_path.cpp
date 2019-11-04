#include <bits/stdc++.h> 
using namespace std;
#define ll long long 
#define f(i, a, b) for(ll i=a;i<b;i++)
#define fi(i, a, b) for(ll i=b-1;i>=a;i--)
#define pb push_back
#define VI vector<int>
#define Vll vecotr<long long>

int main()
{
	int V,e;
	cin>>V>>e;
	int adj[V][V];
	f(i,0,V)
	{
		f(p,0,V)
		{
			if(i!=p){
				adj[i][p]=1000;
			}
			else
				adj[i][p]=0;
		}
	}
	f(i,0,e)
	{
		int x,y;
		cin>>x>>y;
		adj[x][y]=1;
		adj[y][x]=1;
	}
	for (int k = 0; k < V; k++)  
    {  
        for (int i = 0; i < V; i++)  
        {  
            for (int j = 0; j < V; j++)  
            {  
                if (adj[i][k] + adj[k][j] < adj[i][j]){  
                    adj[i][j] = adj[i][k] + adj[k][j]; 
                    cout<<adj[i][j]<<" "<<adj[i][k]<<" "<<adj[k][j]<<"\n";
                } 
            }  
        }  
    }
    f(i,0,V)
    {
    	f(p,0,V)
    	{	
    		cout<<adj[i][p]<<" ";
    	}
    		
    	cout<<"\n";
    }  

}