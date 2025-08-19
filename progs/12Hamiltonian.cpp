#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> graph;
vector<int> soln;
int n, ncount = 0;
void hamiltonian(int k);
void printArray() {
 ncount += 1;
 cout << "Hamiltonian Cycle: ";
 for(int i = 0; i < n; i++) {
 cout << soln[i] << " ";
 }
 cout << soln[0] << endl;
}
void nextValue(int k) {
 while(true) {
 soln[k] = (soln[k] + 1) % (n);
 if(soln[k] == 0) {
 return;
 }
 if(graph[soln[k - 1]][soln[k]] != 0) {
 int j;
 for(j = 0; j < k; j++) {
 if(soln[j] == soln[k]) {
 break;
 }
 }
 if(j == k) {
 if(k < n - 1 || (k == n - 1 && graph[soln[n - 1]][soln[0]] != 0)) {
 return;
 }
 }
 }
 }
}
void hamiltonian(int k) {
 while(true) {
 nextValue(k);
 if(soln[k] == 0) {
 return;
 }
 if(k == n - 1) {
 printArray();
 } else {
 hamiltonian(k + 1);
 }
 }
}
int main() {
 cout << "Enter Number of Vertices: ";
 cin >> n;
 graph.resize(n, vector<int>(n));
 soln.resize(n);
 cout << "Enter Adjacency Matrix: " << endl;
 for(int i = 0; i < n; i++) {
 for(int j = 0; j < n; j++) {
 cin >> graph[i][j];
 }
 }
 soln[0] = 0;
 cout << "Hamiltonian Cycles are:" << endl;
 hamiltonian(1);
 if(ncount == 0) {
 cout << "No Hamiltonian Cycle" << endl;
 }
 return 0;
}