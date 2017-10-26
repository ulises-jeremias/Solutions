/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1867
 * Name: How Many Dependencies?
 * Date: 20/10/2017
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define N 105

using namespace std;

int n, deep;
bool visited[N];
vector<int> graph[N];

int dfs(int v)
{
        visited[v] = true;
        int i, size = (int) graph[v].size();

        for (i = 0; i < size; i++) {
                if (!visited[graph[v][i]]) {
                        deep++;
                        dfs(graph[v][i]);
                }
        }
}

int main(int argc, char const *argv[])
{
        #ifndef ONLINE_JUDGE
        #define ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #endif

        int i, j, t, m, d[N + 5];

        while (cin >> n, n) {
                for (i = 1; i <= n; i++) {
                        graph[i].clear();
                        d[i] = 0;
                }

                for (i = 1; i <= n; i++) {
                        cin >> t;
                        while (t--) {
                                cin >> m;
                                graph[i].push_back(m);
                        }
                }

                int maxDeep = -1, index = 1;

                for (i = 1; i <= n; i++) {
                        memset(visited, false, sizeof visited);
                        deep = 0;
                        dfs(i);
                        d[i] = deep;
                }

                for (i = 1; i <= n; i++) {
                        maxDeep = max(maxDeep, d[i]);
                }

                for (i = 1; i <= n; i++) {
                        if (d[i] == maxDeep) {
                                index = i;
                                break;
                        }
                }

                cout << index << endl;
        }

        return 0;
}
