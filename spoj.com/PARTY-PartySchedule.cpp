/*
 * By: ulises-jeremias
 * From: http://www.spoj.com/problems/PARTY/
 * Name: PARTY - Party Schedule
 * Date: 27/09/2017
 */

#include <iostream>
#include <utility>

using namespace std;

int n, k, party[105][2];
pair<int, int> DP[105][505];

pair<int, int> dp(int i, int cap)
{
        if (i == n || cap == 0) {
                return pair<int, int>(0, 0);
        }
        if (DP[i][cap].first != -1) {
                return DP[i][cap];
        }
        DP[i][cap] = dp(i + 1, cap);
        if (cap >= party[i][0]) {
                pair<int, int> a = dp(i + 1, cap - party[i][0]);
                a.first += party[i][0];
                a.second += party[i][1];
                if (a.second > DP[i][cap].second) {
                        DP[i][cap] = a;
                } else if (a.second == DP[i][cap].second) {
                        DP[i][cap].first = min(a.first, DP[i][cap].first);
                }
        }
        return DP[i][cap];
}

int main(int argc, char const *argv[])
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int i, j;
        while (cin >> k >> n, n || k) {
                for (i = 0; i < n; i++) {
                        cin >> party[i][0] >> party[i][1];
                }
                for (i = 0; i < n; i++) {
                        for (j = 0; j <= k; j++) {
                                DP[i][j] = pair<int, int>(-1, -1);
                        }
                }
                pair<int, int> answer = dp(0, k);
                cout << answer.first << " " << answer.second << endl;
        }
        return 0;
}
