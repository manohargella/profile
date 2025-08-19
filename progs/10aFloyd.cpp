#include <iostream>
#include <cmath>
using namespace std;
#define V 4 
#define INF 99999 
void floyd(int graph[][V]) {
 int dist[V][V];

 for (int i = 0; i < V; i++)
 for (int j = 0; j < V; j++)
 dist[i][j] = graph[i][j];
 for (int k = 0; k < V; k++) {
 for (int i = 0; i < V; i++) {
 for (int j = 0; j < V; j++) {
 if (dist[i][k] + dist[k][j] < dist[i][j])
 dist[i][j] = dist[i][k] + dist[k][j];
 }
 }
 }
 cout << "The following matrix shows the shortest distances between every pair of vertices:" <<
endl;
 for (int i = 0; i < V; i++) {
 for (int j = 0; j < V; j++) {
 if (dist[i][j] == INF)
 cout << "INF" << " ";
 else
 cout << dist[i][j] << " ";
 }
 cout << endl;
 }
}
int main() {
 int graph[V][V] = {
    {2, 0, 1, 2},
    {3, 0, 1, 8},
    {4, 0, 1, 2},
    {5, 0, 3, 2}
};

 floyd(graph);
 return 0;
}