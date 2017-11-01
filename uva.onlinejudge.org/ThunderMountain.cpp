/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1744
 * Name: Thunder Mountain
 * Date: 31/10/2017
 */

#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>

#define INF 1e9
#define EPS 1e-9
#define N 105

using namespace std;

int n, r[N][2];
bool imp;
double adj[N][N], aux, ans;

double dist(int i, int j)
{
        return hypot(r[i][0] - r[j][0], r[i][1] - r[j][1]);
}

void floyd()
{
        int i, j, k;

        for (k = 0; k < n; ++k) {
                for (i = 0; i < n; ++i) {
                        for (j = 0; j < n; ++j) {
                                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
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

        cout << fixed << setprecision(4);

        int TC, i, j;

        cin >> TC;
        for (int it = 1; it <= TC; ++it) {
                cin >> n;

                for (i = 0; i < n; ++i) {
                        cin >> r[i][0] >> r[i][1];
                }

                for (i = 0; i < n; ++i) {
                        adj[i][i] = 0.0;
                }

                for (i = 0; i < n; ++i) {
                        for (j = i + 1; j < n; ++j) {
                                if ((aux = dist(i, j)) < 10.0 + EPS) {
                                        adj[i][j] = adj[j][i] = aux;
                                } else {
                                        adj[i][j] = adj[j][i] = INF;
                                }
                        }
                }

                floyd();

                imp = false;
                ans = -INF;

                for (i = 0; i < n; ++i) {
                        for (j =  i + 1; j < n; ++j) {
                                if (fabs(adj[i][j] - INF) < EPS) {
                                        imp = true;
                                }

                                ans = max(ans, adj[i][j]);
                        }
                }

                cout << "Case #" << it << ":" << endl;

                if (imp) {
                        cout << "Send Kurdy" << endl;
                } else {
                        cout << ans << endl;
                }

                cout << endl;
        }

        return 0;
}
