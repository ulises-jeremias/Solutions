/*
 * By: ulises-jeremias
 * From: http://codeforces.com/problemset/problem/313/B
 * Name: B. Ilya and Queries
 * Date: 25/09/2017
 */

#include <iostream>
#include <string>

using namespace std;

int n, l, r;
int dp[100005];
string s;

int main(int argc, char const *argv[]) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int i, size;
        cin >> s;
        size = s.size();
        dp[1] = 0;
        for (i = 1; i < size; i++) {
                if (s[i] == s[i - 1]) {
                        dp[i + 1] = dp[i] + 1;
                } else {
                        dp[i + 1] = dp[i];
                }
        }

        cin >> n;
        while (n--) {
                cin >> l >> r;
                cout << dp[r] - dp[l] << endl;
        }
        return 0;
}
