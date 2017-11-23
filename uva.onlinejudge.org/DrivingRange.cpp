/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2957
 * Name: Driving Range
 * Date: 23/11/2017
 */

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

#define INF 1 << 30

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> edge;

bool operator < (const edge a, const edge b)
{
        return a.first < b.first;
}

struct DisjointSet
{
        int sets, *parents, *rank;

        DisjointSet(int n)
        {
                int i;

                sets = n;
                parents = new int[n + 5];
                rank = new int[n + 5];
                for (i = 0; i < n; i++) {
                        parents[i] = i;
                        rank[i] = 0;
                }
        }

        int findSet(int x)
        {
                return (x == parents[x]) ? x : parents[x] = findSet(parents[x]);
        }

        bool isSameSet(int x, int y)
        {
                return findSet(x) == findSet(y);
        }

        bool unionSet(int x, int y)
        {
                int xRoot = findSet(x), yRoot = findSet(y);

                if (isSameSet(xRoot, yRoot)) {
                        return false;
                }

                if (rank[xRoot] < rank[yRoot]) {
                        parents[xRoot] = yRoot;
                } else if (rank[xRoot] > rank[yRoot]) {
                        parents[yRoot] = xRoot;
                } else {
                        parents[yRoot] = xRoot;
                        rank[xRoot]++;
                }

                sets--;

                return true;
        }
};

struct Graph
{
        int V, E;
        vector <edge> edges;

        Graph(int V, int E)
        {
                this->V = V;
                this->E = E;
        }

        void addEdge(int w, int a, int b)
        {
                edges.push_back(edge(w, ii(a, b)));
        }

        int kruskal()
        {
                DisjointSet ds(V);
                int i, ans = 0, size = (int) edges.size();

                sort(edges.begin(), edges.end());

                for (i = 0; i < size; i++) {
                        edge e = edges[i];

                        if (ds.unionSet(e.second.first, e.second.second)) {
                                ans = max(ans, e.first);
                        }
                }

                if (ds.sets != 1) {
                        return INF;
                }

                return ans;
        }
};

int main(int argc, char const *argv[]) {
        int TC, i, n, m, ans, u, v, w;

        while (cin >> n >> m, n || m) {

                Graph graph(n, m);

                for (i = 0; i < m; i++) {
                        cin >> u >> v >> w;

                        graph.addEdge(w, u, v);
                }

                if (ans = graph.kruskal(), ans == INF) {
                        cout << "IMPOSSIBLE" << endl;
                } else {
                        cout << ans << endl;
                }

        }
        return 0;
}
