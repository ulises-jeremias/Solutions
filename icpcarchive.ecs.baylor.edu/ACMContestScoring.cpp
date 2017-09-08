/*
 * By: ulises-jeremias
 * From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5372
 * Name: ACM Contest Scoring
 * Date: 07/09/2017
 */

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int t[27];
        bool solved[27];
        int minutes, i, right, total_time;
        char problem;
        int key;
        string state;

        while (cin >> minutes) {
                total_time = right = 0;
                key = problem - 'A';
                *t = {0};
                *solved = {false};

                while (minutes != -1) {
                        cin >> problem >> state;
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
