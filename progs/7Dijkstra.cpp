#include <bits/stdc++.h>
using namespace std;
const int MAX = 100; 
int graph[MAX][MAX]; 
int dist[MAX]; 
bool sptSet[MAX]; 

int minDistance(int V)
{
 int min = INT_MAX, min_index;
 for (int v = 0; v < V; v++)
 if (sptSet[v] == false && dist[v] <= min)
 min = dist[v], min_index = v;
 return min_index;
}

void dijkstra(int src, int V)
{
 for (int i = 0; i < V; i++)
 dist[i] = INT_MAX, sptSet[i] = false;

 dist[src] = 0;

 for (int count = 0; count < V-1; count++)
 {
 int u = minDistance(V);

 sptSet[u] = true;

 for (int v = 0; v < V; v++)
 if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
 dist[v] = dist[u] + graph[u][v];

 cout << "Vertex \t Distance from Source" << endl;
 for (int i = 0; i < V; i++)
 cout << i << "\t\t " << dist[i] << endl;
}
}
int main()
{
 int V, src;
 cout << "Enter the number of vertices: ";
 cin >> V;
 cout << "Enter the adjacency matrix representation of the graph: " << endl;
 for (int i = 0; i < V; i++)
 for (int j = 0; j < V; j++)
 cin >> graph[i][j];
 cout << "Enter the source vertex: ";
 cin >> src;
 dijkstra(src, V);
 return 0;
}