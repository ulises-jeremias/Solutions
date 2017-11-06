/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=568
 * Name: The Net
 * Date: 30/10/2017
 */

#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>

#define INF 1 << 30
#define N 305

using namespace std;

int n, m, idv, idu, v, u, adj[N][N], p[N][N];
unordered_map<int, int> id_to_idx, idx_to_id;
bool first;
string s;
char c;

void init()
{
        int i, j;
        for (i = 0; i < N; i++) {
                for (j = 0; j < N; j++) {
                        adj[i][j] = INF;
                        p[i][j] = i;
                }

                adj[i][i] = 0;
        }
}

void floyd()
{
        int i, j, k;

        for (k = 0; k < n; k++) {
                for (i = 0; i < n; i++) {
                        for (j = 0; j < n; j++) {
                                if (adj[i][k] + adj[k][j] < adj[i][j]) {
                                        adj[i][j] = adj[i][k] + adj[k][j];
                                        p[i][j] = p[k][j];
                                }
                        }
                }
        }
}

void print_path(int i, int j)
{
        if (i != j) {
                print_path(i, p[i][j]);
        }

        if (first) {
                first = false;
        } else {
                cout << " ";
        }

        cout << idx_to_id[j];
}

int main(int argc, char const *argv[]) {
        #ifndef ONLINE_JUDGE
        #define ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #endif

        int i, j, idn;

        while (cin >> n) {
                id_to_idx.clear();
                idx_to_id.clear();

                init();

                idn = 0;

                for (i = 0; i < n; i++) {
                        cin >> idu;
                        if (id_to_idx.find(idu) == id_to_idx.end()) {
                                id_to_idx[idu] = idn;
                                idx_to_id[idn++] = idu;
                        }

                        u = id_to_idx[idu];
                        getline(cin, s);
                        stringstream ss(s);

                        while (ss >> c >> idv) {
                                if (id_to_idx.find(idv) == id_to_idx.end()) {
                                        id_to_idx[idv] = idn;
                                        idx_to_id[idn++] = idv;
                                }

                                v = id_to_idx[idv];
                                adj[u][v] = 1;
                        }
                }

                floyd();

                cin >> m;
                cout << "-----" << endl;

                while (m--) {
                        cin >> idu >> idv;
                        u = id_to_idx[idu];
                        v = id_to_idx[idv];

                        if (adj[u][v] == INF) {
                                cout << "connection impossible" << endl;
                                continue;
                        }

                        first = true;
                        print_path(u, v);
                        cout << endl;
                }
        }

        return 0;
}
