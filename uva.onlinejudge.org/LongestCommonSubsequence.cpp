/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1346
 * Name: Longest Common Subsequence
 * Date: 29/09/2017
 */

#include <iostream>
#include <string>

using namespace std;

int LCS[1005][1005];
string s1, s2;

int lcs()
{
        int i, j, size1 = (int)s1.size(), size2 = (int)s2.size();

        for (i = 0; i <= size1; i++) {
                LCS[0][i] = 0;
        }
        for (i = 0; i <= size2; i++) {
                LCS[i][0] = 0;
        }

        for (i = 1; i <= size1; i++) {
                for (j = 1; j <= size2; j++) {
                        if (s1[i-1] == s2[j-1]) {
                                LCS[i][j] = LCS[i-1][j-1] + 1;
                        } else {
                                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
                        }
                }
        }
        return LCS[size1][size2];
}

int main(int argc, char const *argv[])
{
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);

        while (getline(cin, s1)) {
                getline(cin, s2);
                cout << lcs() << endl;
        }

        return 0;
}
