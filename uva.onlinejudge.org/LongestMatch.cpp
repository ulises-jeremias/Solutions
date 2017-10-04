/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1041
 * Name: Longest Match
 * Date: 29/09/2017
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int LCS[1005][1005];
string s;
vector<string> sequence1, sequence2;

int lcs()
{
        int i, j, n = (int) sequence1.size(), m = (int) sequence2.size();

        for (i = 0; i <= n; i++) {
                LCS[0][i] = 0;
        }

        for (i = 0; i <= m; i++) {
                LCS[i][0] = 0;
        }

        for (i = 1; i <= n; i++) {
                for (j = 1; j <= m; j++) {
                        if (sequence1[i-1] == sequence2[j-1]) {
                                LCS[i][j] = LCS[i-1][j-1] + 1;
                        } else {
                                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
                        }
                }
        }

        return LCS[n][m];
}


void push_without_separators(vector<string> *sequence)
{
        char *p = new char[25];
        char * c = &s[0];
        p = strtok(c, " !#$%&'()*+,-./:;<=>?@[]^_`{|}~");
        while (p != NULL) {
                (*sequence).push_back(string(p));
                p = strtok(NULL, " !#$%&'()*+,-./:;<=>?@[]^_`{|}~");
        }
}

int main(int argc, char const *argv[])
{
        #ifndef ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #endif

        int TC = 1;

        while (getline(cin, s)) {
                sequence1.clear();
                sequence2.clear();

                if (s[0] != 0) {
                        push_without_separators(&sequence1);
                }

                getline(cin, s);

                if (s[0] != 0) {
                        push_without_separators(&sequence2);
                }

                printf("%2d. ", TC++);

                if (sequence1.empty() || sequence2.empty()) {
                        cout << "Blank!" << endl;
                } else {
                        cout << "Length of longest match: " << lcs() << endl;
                }
        }

        return 0;
}
