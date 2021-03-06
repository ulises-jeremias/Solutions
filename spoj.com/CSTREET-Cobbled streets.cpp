/*
 * By: ulises-jeremias
 * From: http://www.spoj.com/problems/CSTREET/
 * Name: CSTREET - Cobbled streets
 * Date: 24/11/2017
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

        vector <edge> kruskal()
        {
                int i, w, from, to;
                vector <edge> MST;

                DisjointSet ds(V);
                sort(edges.begin(), edges.end());

                for(i = 0; i < edges.size(); i++) {
                        w = edges[i].first;
                        from = edges[i].second.first;
                        to = edges[i].second.second;

                        if (ds.unionSet(from, to)) {
                                MST.push_back(edge(w, ii(from, to)));
                        }
                }

                return MST;
        }
};

int main()
{
        int i, size, ans, TC, V, E, p, a, b, w, s1, s2;
        vector <edge> MST;

        cin >> TC;
        while(TC--)
        {
                cin >> p >> V >> E;

                Graph graph(V, E);

                for (i = 0; i < E; i++) {
                        cin >> a >> b >> w;
                        graph.addEdge(w, --a, --b);
                }

                MST = graph.kruskal();
                s1 = 0, s2 = INF;
                size = MST.size();

                for (i = 0; i < size; i++) {
                        s1 += MST[i].first;
                }

                cout << (int) (s1 * p) << endl;
        }

        return 0;
}
