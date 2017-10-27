/*
 * By: ulises-jeremias
 * From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=737
 * Name: Critical Links
 * Date: 26/10/2017
 */

#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <string>
#include <sstream>
#include <cstring>

#define N 100005

using namespace std;

int n, v, e, u, df_number[N], low[N], father[N];
vector<int> graph[N];
set<pair<int, int> > critical_links;
set<pair<int, int> >::iterator itr;


void dfs(int index)
{
        int i, act, size = (int) graph[index].size();

        for (i = 0; i < size; i++) {
                act = graph[index][i];
                if (df_number[act] == -1) {
                        df_number[act] = df_number[index] + 1;
                        father[act] = index;
                        low[act] = df_number[act];
                        dfs(act);

                        if (low[act] > df_number[index]) {
                                critical_links.insert(pair<int, int>(
                                                              min(act, index),
                                                              max(act, index)
                                                              ));
                        }

                        low[index] = min(low[index], low[act]);
                } else if (father[index] != act) {
                        low[index] = min(low[index], df_number[act]);
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

        int i, j;
        char c;

        while (cin >> n) {
                for (i = 0; i < n; i++) {
                        graph[i].clear();
                }

                for (i = 0; i < n; i++) {
                        cin >> v;
                        cin >> c >> e >> c;

                        for (j = 0; j < e; j++) {
                                cin >> u;
                                graph[v].push_back(u);
                                graph[u].push_back(v);
                        }
                }

                critical_links.clear();
                memset(df_number, -1, sizeof df_number);

                for (i = 0; i < n; i++) {
                        if (df_number[i] == -1) {
                                father[i] = i;
                                df_number[i] = 0;
                                low[i] = 0;
                                dfs(i);
                        }
                }

                cout << (int) critical_links.size() << " critical links" << endl;

                for (itr = critical_links.begin(); itr != critical_links.end(); itr++) {
                        cout << (*itr).first << " - " << (*itr).second << endl;
                }

                cout << endl;
        }

        return 0;
}
