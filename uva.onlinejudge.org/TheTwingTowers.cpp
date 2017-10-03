/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1007
 * Name: The Twin Towers
 * Date: 3/10/2017
 */

#include <iostream>

using namespace std;

int n, m, s1[105], s2[105], LCS[105][105];

int lcs()
{
        int i, j;

        for (i = 0; i <= n; i++) {
                LCS[i][0] = 0;
        }

        for (i = 0; i <= m; i++) {
                LCS[0][i] = 0;
        }

        for (i = 1; i <= n; i++) {
                for (j = 1; j <= m; j++) {
                        if (s1[i] == s2[j]) {
                                LCS[i][j] = LCS[i-1][j-1] + 1;
                        } else {
                                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
                        }
                }
        }

        return LCS[n][m];
}

int main(int argc, char const *argv[]) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int TC = 1, i;

        while (cin >> n >> m, n || m) {
                for (i = 1; i <= n; i++) {
                        cin >> s1[i];
                }

                for (i = 1; i <= m; i++) {
                        cin >> s2[i];
                }

                cout << "Twin Towers #" << TC++ << endl;
                cout << "Number of Tiles : " << lcs() << endl << endl;
        }

        return 0;
}
