/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=401
 * Name: Overlapping Rectangles
 * Date: 24/11/2017
 */

#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>

#define EPS 1e-9
#define INF 1 <<  30

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;


struct point
{
        int x, y;

        point() {
                x = y = 0;
        }

        point(int _x, int _y) : x(_x), y(_y) {
        };
};

point p1, p2, p3, p4, p5, p6;

int main () {
        #ifndef ONLINE_JUDGE
        #define ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #endif

        int TC, i, j;

        cin >> TC;
        while (TC--) {
                cin >> p1.x >> p1.y >> p2.x >> p2.y;
                cin >> p3.x >> p3.y >> p4.x >> p4.y;

                p5.x = max(p1.x, p3.x);
                p5.y = max(p1.y, p3.y);
                p6.x = min(p2.x, p4.x);
                p6.y = min(p2.y, p4.y);

                if (p5.x >= p6.x || p5.y >= p6.y) {
                        cout << "No Overlap" << endl;
                } else {
                        cout << p5.x << " " << p5.y << " " << p6.x << " " << p6.y << endl;
                }

                if (TC) {
                        cout << endl;
                }
        }

        return 0;
}
