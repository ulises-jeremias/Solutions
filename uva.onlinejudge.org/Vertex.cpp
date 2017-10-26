/*
 * By: ulises-jeremias
 * From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=216
 * Name: Vertex
 * Date: 25/10/2017
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define N 105

using namespace std;

int n, u, v, k;
vector<int> graph[N];
bool visited[N];
queue<int> q;

void bfs() {
        memset(visited, false, sizeof visited);
        int i, act, size = (int) graph[u].size();

        for (i = 0; i < size; i++) {
                q.push(graph[u][i]);
                visited[graph[u][i]] = true;
        }

        while (!q.empty()) {
                act = q.front();
                q.pop();
                size = (int) graph[act].size();
                for (i = 0; i < size; i++) {
                        if (!visited[graph[act][i]]) {
                                q.push(graph[act][i]);
                                visited[graph[act][i]] = true;
                        }
                }

        }
}


int main(int argc, char const *argv[]) {
        #ifndef ONLINE_JUDGE
        #define ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #endif

        int i;

        while (cin >> n, n) {
                for (i = 1; i <= n; i++) {
                        graph[i].clear();
                }

                while (cin >> u, u) {
                        while (cin >> v, v) {
                                graph[u].push_back(v);
                        }
                }

                cin >> k;
                while (k--) {
                        cin >> u;
                        bfs();

                        int count = 0;
                        for (i = 1; i <= n; i++) {
                                count += (int) !visited[i];
                        }

                        cout << count;

                        for (i = 1; i <= n; i++) {
                                if (!visited[i]) {
                                        cout << " " << i;
                                }
                        }

                        cout << endl;
                }
        }

        return 0;
}
