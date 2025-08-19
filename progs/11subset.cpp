#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, e, u, v, g[N][N], path[N];
bool vis[N];
bool isValid(int pos) {
 if (g[path[pos - 1]][path[pos]] == 0) {
 return false;
 }
 for (int i = 0; i < pos; i++) {
 if (path[i] == path[pos]) {
 return false;
 }
 }
 return true;
}
void printPath(int pos) {
 cout << "Hamiltonian cycle: ";
 for (int i = 0; i < pos; i++) {
 cout << path[i] << " ";
 }
 cout << path[0] << endl;
}
void findCycle(int pos) {
 if (pos == n) {
 if (g[path[pos - 1]][path[0]]) {
 printPath(pos);
 }
 return;
 }
 for (int i = 1; i <= n; i++) {
 path[pos] = i;
 if (isValid(pos)) {
 findCycle(pos + 1);
 }
 }
}
int main() {
 cin >> n >> e;
 for (int i = 0; i < e; i++) {
 cin >> u >> v;
 g[u][v] = g[v][u] = 1;
 }
 path[0] = 1;
 findCycle(1);
 return 0;
}