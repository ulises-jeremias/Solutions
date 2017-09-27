/*
 * By: ulises-jeremias
 * From: http://www.spoj.com/problems/EDIST/
 * Name: EDIST - Edit distance
 * Date: 27/09/2017
 */

#include <iostream>
#include <string>

using namespace std;

int LD[2005][2005];
string s1, s2;

int ld()
{
        int i, j, s1_size, s2_size;

        s1_size = (int) s1.size();
        s2_size = (int) s2.size();
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
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int tc;
        cin >> tc;
        while (tc--) {
                cin >> s1 >> s2;
                cout << ld() << endl;
        }
        return 0;
}
