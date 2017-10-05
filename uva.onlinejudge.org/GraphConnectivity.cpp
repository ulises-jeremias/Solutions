/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=400
 * Name: Graph Connectivity
 * Date: 4/10/2017
 */

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int n;
string s;
bool adj[30][30], visited[30];


int dfs(int v)
{
        visited[v] = true;
        int i, answer = 1;
        for (i = 0; i < n; i++) {
                if (adj[v][i] && !visited[i]) {
                        answer += dfs(i);
                }
        }

        return answer;
}

int main(int argc, char const *argv[])
{
        #ifndef ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #endif

        int TC, i, answer;

        cin >> TC;
        getline(cin, s);
        getline(cin, s);
        while (TC--) {
                getline(cin, s);
                n = s[0] - 'A' + 1;

                memset(adj, 0, sizeof adj);

                while (getline(cin, s), s.length()) {
                        adj[s[0] - 'A'][s[1] - 'A'] = adj[s[1] - 'A'][s[0] - 'A'] = true;
                }

                answer = 0;
                memset(visited, 0, sizeof visited);

                for (i = 0; i < n; i++) {
                        if (!visited[i]) {
                                dfs(i);
                                answer++;
                        }
                }

                cout << answer << endl;
                if (TC) {
                        cout << endl;
                }
        }

        return 0;
}
