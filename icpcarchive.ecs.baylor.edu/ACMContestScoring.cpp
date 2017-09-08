/*
 * By: ulises-jeremias
 * From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5372
 * Name: ACM Contest Scoring
 * Date: 07/09/2017
 */

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        bool solved[30];
        int minutes, i, right, total_time, t[30];
        char problem;
        int key;
        string state;

        while (cin >> minutes) {
                total_time = right = 0;
                memset(t, 0, sizeof t);
                memset(solved, 0, sizeof solved);

                while (minutes != -1) {
                        cin >> problem >> state;
                        key = problem - 'A';

                        if (!solved[key]) {
                                if (state[0] == 'r') {
                                        solved[key] = true;
                                        right++;
                                        total_time += minutes + t[key];
                                } else {
                                        t[key] += 20;
                                }
                        }

                        cin >> minutes;
                }

                cout << right << " " << total_time << endl;
        }

        return 0;
}
