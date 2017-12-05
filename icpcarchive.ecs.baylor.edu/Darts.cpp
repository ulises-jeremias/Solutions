/*
 * By: ulises-jeremias
 * From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4273
 * Name: Darts
 * Date: 05/12/2017
 */

#include <iostream>

using namespace std;

int n, x, y, ans, score, dist;

int main(int argc, char const *argv[])
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int TC;

        cin >> TC;
        while (TC--) {
                cin >> n;
                ans = 0;
                while (n--) {
                        cin >> x >> y;

                        score = 10;
                        dist = 20;

                        while (dist*dist < x*x + y*y && score) {
                                score--;
                                dist += 20;
                        }

                        ans += score;
                }

                cout << ans << endl;
        }

        return 0;
}
