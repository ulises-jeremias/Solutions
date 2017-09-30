/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1133
 * Name: Vacation
 * Date: 29/09/2017
 */

#include <iostream>
#include <string>

using namespace std;

int LCS[105][105];
string s1, s2;

int lcs()
{
        int i, j, s1_size = (int) s1.size(), s2_size = (int) s2.size();

        for (i = 0; i <= s1_size; i++) {
                LCS[0][i] = 0;
        }
        for (i = 0; i <= s2_size; i++) {
                LCS[i][0] = 0;
        }

        for (i = 1; i <= s1_size; i++) {
                for (j = 1; j <= s2_size; j++) {
                        if (s1[i-1] == s2[j-1]) {
                                LCS[i][j] = LCS[i-1][j-1] + 1;
                        } else {
                                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
                        }
                }
        }

        return LCS[s1_size][s2_size];
}

int main(int argc, char const *argv[]) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int TC = 1;
        while (getline(cin, s1), s1[0] != '#') {
                getline(cin, s2);
                cout << "Case #" << TC++ << ": you can visit at most " << lcs() << " cities." << endl;
        }

        return 0;
}
