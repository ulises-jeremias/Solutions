/*
 * By: ulises-jeremias
 * From: http://www.spoj.com/problems/ELIS/
 * Name: ELIS - Easy Longest Increasing Subsequence
 * Date: 25/09/2017
 */

#include <iostream>

using namespace std;

int n;
int inputs[15];

int lis()
{
        int i, j, max = -1;
        int dp[15];
        for (i = 0; i < n; i++) {
                dp[i] = 1;
                for (j = 0; j < i; j++) {
                        if (inputs[j] < inputs[i] && dp[j] + 1 > dp[i]) {
                                dp[i] = dp[j] + 1;
                        }
                }
                if (dp[i] > max) {
                        max = dp[i];
                }
        }

        return max;
}

int main(int argc, char const *argv[])
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int i;
        cin >> n;
        for (i = 0; i < n; i++) {
                cin >> inputs[i];
        }

        cout << lis() << endl;

        return 0;
}
