/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2737
 * Name: Money Matters
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
        int sets, *parents, *rank, *money;

        DisjointSet(int n)
        {
                int i;

                sets = n;
                parents = new int[n + 5];
                rank = new int[n + 5];
                money = new int[n + 5];

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
                        money[yRoot] += money[xRoot];
                } else if (rank[xRoot] > rank[yRoot]) {
                        parents[yRoot] = xRoot;
                        money[xRoot] += money[yRoot];
                } else {
                        parents[yRoot] = xRoot;
                        money[xRoot] += money[yRoot];
                        rank[xRoot]++;
                }

                sets--;

                return true;
        }
};

int n, m, o, x, y;

bool check(DisjointSet *ds)
{
        for (int i = 0; i < n; i++) {
                if (ds->money[ds->findSet(i)] != 0) {
                        return false;
                }
        }

        return true;
}

int main(int argc, char const *argv[]) {
        #ifndef ONLINE_JUDGE
        #define ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #endif

        int N, i, m_i;

        scanf("%d", &N);

        while (N--) {
                scanf("%d %d", &n, &m);

                DisjointSet ds(n);
                for (i = 0; i < n; i++) {
                        scanf("%d", &m_i);
                        ds.money[i] = m_i;
                }

                for (i = 0; i < m; i++) {
                        scanf("%d %d", &x, &y);
                        ds.unionSet(x, y);
                }

                if (check(&ds)) {
                        printf("POSSIBLE\n");
                } else {
                        printf("IMPOSSIBLE\n");
                }
        }

        return 0;
}
