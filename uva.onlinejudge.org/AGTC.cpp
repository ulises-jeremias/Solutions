/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3648
 * Name: AGTC
 * Date: 24/11/2017
 */

#include <iostream>
#include <string>

using namespace std;

int n, m, LD[2005][2005];
string s1, s2;

int ld()
{
        int i, j, s1_size, s2_size;

        s1_size = s1.size();
        s2_size = s2.size();
        for (j = 0; j <= s1_size; j++) LD[0][j] = j;
        for (i = 0; i <= s2_size; i++) LD[i][0] = i;

        for (i = 1; i <= s2_size; i++) {
                for (j = 1; j <= s1_size; j++) {
                        LD[i][j] = min(min(LD[i-1][j-1] + (s1[j-1] != s2[i-1]), LD[i-1][j] + 1), LD[i][j-1] + 1);
                }
        }
        return LD[s2_size][s1_size];
}

int main(int argc, char const *argv[]) {
        #ifndef ONLINE_JUDGE
        #define ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #endif

        while (cin >> n >> s1) {
                cin >> m >> s2;

                cout << ld() << endl;
        }

        return 0;
}
