/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1867
 * Name: How Many Dependencies?
 * Date: 20/10/2017
 */

#include <iostream>
#include <vector>
#include <queue>

#define N 105

using namespace std;

int n;
bool visited[N];
vector<int> adj[N];

int dfs(int v)
{
        visited[v] = true;
        int i, deep = 1;

        for (i = 0; i < n; i++) {
                if (adj[v][i] && !visited[i]) {
                        deep += dfs(i);
                }
        }

        return deep;
}

int main(int argc, char const *argv[])
{
        #ifndef ONLINE_JUDGE
        #define ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #endif

        int i, j, t, m;

        while (cin >> n, n) {
              for (i = 0; i < n; i++) {
                      adj[i].clear();
                      cin >> t;
                      for (j = 0; j < t; j++) {
                             cin >> m;
                             adj[i][m] = true;
                      }
              }

              int max = -1, index = -1, deep[n + 5];

              for (i = 0; i < n; i++) {
                    memset(visited, false, sizeof visited);
                    deep[i] = dfs(i);
              }

              for (i = 0; i < n; i++) {
                      if (deep[i] > max) {
                          max = deep[i];
                          index = i;
                      }
              }

              cout << index << endl;
        }

        return 0;
}
