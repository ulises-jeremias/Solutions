/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=251
 * Name: Network
 * Date: 24/11/2017
 */

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

#define N 105

int n, v, e, u, dfs_root, root_children, df_number[N], low[N], father[N];
bool art[N];
vector<int> graph[N];

int dfs(int index)
{
        int i, act, size = (int) graph[index].size();

        for (i = 0; i < size; i++) {
                act = graph[index][i];
                if (df_number[act] == -1) {
                        df_number[act] = df_number[index] + 1;
                        father[act] = index;
                        low[act] = df_number[act];

                        if (dfs_root == index) {
                                root_children++;
                        }

                        dfs(act);

                        if (low[act] >= df_number[index]) {
                                if (dfs_root != index) {
                                        art[index] = true;
                                }
                        }

                        low[index] = min(low[index], low[act]);
                } else if (father[index] != act) {
                        low[index] = min(low[index], df_number[act]);
                }
        }
}

int dfs_main()
{
        int i, sum = 0;

        memset(df_number, -1, sizeof df_number);

        for (i = 0; i < n; i++) {
                if (df_number[i] == -1) {
                        father[i] = i;
                        dfs_root = i;
                        root_children = 0;
                        df_number[i] = 0;
                        art[i] = false;
                        low[i] = 0;
                        dfs(i);

                        if (root_children > 1) {
                                art[i] = true;
                        }
                }
        }

        for (i = 0; i < n; i++) {
                sum += (int) art[i];
        }

        return sum;
}

int main(int argc, char const *argv[]) {
        #ifndef ONLINE_JUDGE
        #define ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #endif

        string line;

        while (cin >> n, n) {
                memset(graph, 0, sizeof graph);

                while (getline(cin, line), line != "0") {
                        stringstream ss(line);
                        ss >> u;

                        --u;
                        while (ss >> v) {
                                graph[u].push_back(--v);
                                graph[v].push_back(u);
                        }
                }

                cout << dfs_main() << endl;
        }
        return 0;
}
