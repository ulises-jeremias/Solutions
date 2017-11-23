/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2498
 * Name: Virtual Friends
 * Date: 23/11/2017
 */

#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

#define INF 1 << 30

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> edge;

struct cmp
{
        bool operator() (char * a, char * b)
        {
                return strcmp(a, b) > 0;
        }
};

map<char*, int, cmp> hash_map;
char s1[25], s2[25], *c;
int f, cant;

struct DisjointSet
{
        int sets, *parents, *rank, *set_size;

        DisjointSet(int n)
        {
                int i;

                sets = n;
                parents = new int[n + 5];
                rank = new int[n + 5];
                set_size = new int[n + 5];
                for (i = 0; i < n; i++) {
                        parents[i] = i;
                        rank[i] = 0;
                        set_size[i] = 1;
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
                        set_size[yRoot] += set_size[xRoot];
                } else if (rank[xRoot] > rank[yRoot]) {
                        parents[yRoot] = xRoot;
                        set_size[xRoot] += set_size[yRoot];
                } else {
                        parents[yRoot] = xRoot;
                        set_size[xRoot] += set_size[yRoot];
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

        int TC, n, m, i, j;

        scanf("%d", &TC);
        while (TC--) {
                scanf("%d", &f);

                DisjointSet ds(f * 2);

                cant = 0;

                while (f--) {
                        scanf("%s %s", s1, s2);

                        if (hash_map.find(s1) == hash_map.end()) {
                                c = new char[25];
                                strcpy(c, s1);
                                hash_map.insert(make_pair(c, cant++));
                        }
                        if (hash_map.find(s2) == hash_map.end()) {
                                c = new char[25];
                                strcpy(c, s2);
                                hash_map.insert(make_pair(c, cant++));
                        }

                        ds.unionSet(hash_map[s1], hash_map[s2]);

                        printf("%d\n", ds.set_size[ds.findSet(hash_map[s1])]);
                }

                if (TC) {
                        hash_map.clear();
                }
        }

        return 0;
}
