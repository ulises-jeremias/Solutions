/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=472
 * Name: Compromise
 * Date: 4/10/2017
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int n, m, LCS[105][105];
string sequence1[105], sequence2[105];
stack<string> p;


void lcs ()
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
                        if (sequence1[i] == sequence2[j]) {
                                LCS[i][j] = LCS[i - 1][j - 1] + 1;
                        } else {
                                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
                        }
                }
        }
}

void print ()
{
        int i = n, j = m;
        while (i >= 1 && j >= 1) {
                if (sequence1[i] == sequence2[j]) {
                        p.push(sequence1[i]);
                        i--;
                        j--;
                } else if (LCS[i - 1][j] > LCS[i][j - 1]) {
                        i--;
                } else {
                        j--;
                }
        }

        if (!p.empty()) {
                cout << p.top();
                p.pop();
        }

        while (!p.empty()) {
                cout << " " << p.top();
                p.pop();
        }

        cout << endl;
}

int main(int argc, char const *argv[])
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        while (cin >> sequence1[1]) {
                n = 2;
                while (cin >> sequence1[n], sequence1[n][0] != '#') {
                        n++;
                }
                n--;

                m = 1;
                while (cin >> sequence2[m], sequence2[m][0] != '#') {
                        m++;
                }
                m--;

                lcs();
                print();
        }
        return 0;
}
