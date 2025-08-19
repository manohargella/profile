#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int N = 110, M = 10010, INF = 0x3f3f3f3f;
int n, m, h[N], e[M], ne[M], w[M], idx, dist[N];
bool st[N];
void add(int a, int b, int c)
{
 e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++ ;
}
int prim()
{
 memset(dist, 0x3f, sizeof dist);
 memset(st, false, sizeof st);
 priority_queue<pair<int, int> > heap;
 heap.push({0, 1});
 dist[1] = 0;
 int res = 0;
 while (heap.size())
 {
 int ver = heap.top().second, distance = -heap.top().first;
 heap.pop();
 if (st[ver]) continue;
 st[ver] = true, res += distance;
 for (int i = h[ver]; ~i; i = ne[i])
 {
 int j = e[i];
 if (!st[j] && dist[j] > w[i])
 {
 dist[j] = w[i];
 heap.push({-dist[j], j});
 }
 }
 }
 return res;
}

int main()
{
 memset(h, -1, sizeof h);
 cin >> n >> m;
 while (m -- )
 {
 int a, b, c;
 cin >> a >> b >> c;
 add(a, b, c), add(b, a, c);
 }
 cout << prim() << endl;
 return 0;
}