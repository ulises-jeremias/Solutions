/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3301
 * Name: Feynman
 * Date: 4/10/2017
 */

#include <iostream>

using namespace std;

int n, memo[105];

void init () {
        memo[1] = 1;

        for (int i = 2; i < 105; i++) {
                memo[i] = memo[i - 1] + i*i;
        }
}

int main () {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);

        int i, j;

        init();

        while (cin >> n, n) {
                cout << memo[n] << endl;
        }

        return 0;
}
