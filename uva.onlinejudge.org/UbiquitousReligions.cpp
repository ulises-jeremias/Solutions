/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1524
 * Name: Ubiquitous Religions
 * Date: 22/11/2017
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

int main(int argc, char const *argv[]) {
        #ifndef ONLINE_JUDGE
        #define ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #endif

        int TC = 1, n, m, i, j;

        while (scanf("%d %d", &n, &m), n | m) {
                DisjointSet ds(n);

                while (m--) {
                        scanf("%d %d", &i, &j);
                        ds.unionSet(i, j);
                }

                printf("Case %d: %d\n", TC++, ds.sets);
        }

        return 0;
}
