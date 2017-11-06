/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=950
 * Name: All Roads Lead Where?
 * Date: 1/11/2017
 */

#include <iostream>
#include <string>

using namespace std;

#define INF (int) 1e9
#define N 30

int n, m, q, u, v, adj[N][N], p[N][N];
string s, t;

void init()
{
        int i, j;
        for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                        adj[i][j] = INF;
                        p[i][j] = i;
                }

                adj[i][j] = 0;
        }
}

void floyd()
{
        int i, j, k;

        for (k = 0; k < n; k++) {
                for (i = 0; i < n; i++) {
                        for (j = 0; j < n; j++) {
                                if (adj[i][j] > adj[i][k] + adj[k][j]) {
                                        adj[i][j] = adj[i][k] + adj[k][j];
                                        p[i][j] = p[k][j];
                                }
                        }
                }
        }
}

void print_path (int i, int j)
{
        if (i != j) {
                print_path(i, p[i][j]);
        }

        cout << (char) (j + 'A');
}

int main(int argc, char const *argv[])
{
        #ifndef ONLINE_JUDGE
        #define ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #endif

        int TC;

        cin >> TC;
        while (TC--) {
                n = 26;
                cin >> m >> q;

                init();

                while (m--) {
                        cin >> s >> t;
                        adj[s[0]-'A'][t[0]-'A']  = adj[t[0]-'A'][s[0]-'A'] = 1;
                }

                floyd();

                while (q--) {
                        cin >> s >> t;
                        print_path(s[0] - 'A', t[0] - 'A');
                        cout << endl;
                }

                if (TC != 0) {
                        cout << endl;
                }
        }

        return 0;
}
