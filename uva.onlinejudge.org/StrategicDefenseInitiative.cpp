/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=438
 * Name: Strategic Defense Initiative
 * Date: 07/09/2017
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cstdio>

using namespace std;

typedef pair<int, int> ii;

vector<int> seq, previous, dp;

ii lis()
{
        int i, j, idx, size = (int) seq.size(), max = 1;

        for (i = 0; i < size; i++) {
                dp.push_back(1);
                previous.push_back(i);

                for (j = 0; j < i; j++) {
                        if (seq[j] < seq[i] && dp[i] < dp[j] + 1) {
                                dp[i] = dp[j] + 1;
                                previous[i] = j;
                        }
                }

                if (max < dp[i]) {
                        max = dp[i];
                        idx = i;
                }
        }

        return ii(max, idx);
}

void print(int idx)
{
        if (previous[idx] != idx) {
                print(previous[idx]);
        }

        printf("%d\n", seq[idx]);
}

int main(int argc, char const *argv[]) {
        #ifndef ONLINE_JUDGE
        #define ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #endif

        int tc, i, n;
        string s;

        cin >> tc;

        cin.ignore();
        cin.ignore();

        while (tc--) {
                seq.clear();

                while (getline(cin, s) && s != "") {
                        stringstream ss(s);
                        ss >> n;
                        seq.push_back(n);
                }

                ii last = lis();

                printf("Max hits: %d\n", last.first);

                print(last.second);

                printf("\n");
        }

        return 0;
}
