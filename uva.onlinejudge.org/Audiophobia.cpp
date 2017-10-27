/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=989
 * Name: Audiophobia
 * Date: 27/10/2017
 */

#include <iostream>
#define INF (int)1e9
#define N 105

using namespace std;

int c, s, q, adj[N][N], a, b, d;

void init()
{
        int i, j;
        for (i = 0; i < N; i++) {
                for (j = 0; j < N; j++) {
                        adj[i][j] = INF;
                }
        }
}

int main(int argc, char const *argv[])
{

        int i, j, k, TC = 1;
        while (cin >> c >> s >> q, c || s || q) {
                if (TC != 1) {
                        cout << endl;
                }

                init();

                for (i = 0; i < s; i++) {
                        cin >> a >> b >> d;
                        a--;
                        b--;
                        adj[a][b] = adj[b][a] = d;
                }

                for (k = 0; k < c; k++) {
                        for (i = 0; i < c; i++) {
                                for (j = 0; j < c; j++) {
                                        adj[i][j] = min(
                                                adj[i][j],
                                                max(adj[i][k], adj[k][j])
                                                );
                                }
                        }
                }

                cout << "Case #" << TC++ << endl;

                for (i = 0; i < q; i++) {
                        cin >> a >> b;
                        a--;
                        b--;
                        if (adj[a][b] == INF) {
                                cout << "no path" << endl;
                        } else {
                                cout << adj[a][b] << endl;
                        }
                }
        }
        return 0;
}
