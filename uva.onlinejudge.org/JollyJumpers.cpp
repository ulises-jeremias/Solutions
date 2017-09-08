/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=979
 * Name: JollyJumpers
 * Date: 07/09/2017
 */

 #include <iostream>
 #include <string>

using namespace std;

int main(int argc, char const *argv[]) {
        ios_base::sync_with_stdio(false);

        int n, i, c, p, diff;
        bool jolly;
        string output;

        while (cin >> n) {
                jolly = true;
                p = 3005;
                diff = n - 1;

                for (i = 0; i < n; i++) {
                        cin >> c;

                        if (p == 3005 or !jolly) {
                                p = c;
                                continue;
                        }

                        if (abs(c - p) != diff) {
                                jolly = false;
                        }

                        p = c;
                        diff--;
                }

                output = !jolly ? "Not Jolly" : "Jolly";
                cout << output << endl;
        }

        return 0;
}
