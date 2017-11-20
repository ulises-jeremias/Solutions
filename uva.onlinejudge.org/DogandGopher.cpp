/*
 * By: ulises-jeremias
 * From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1251
 * Name: Dog and Gopher
 * Date: 08/11/2017
 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

#define INF 1 << 30

using namespace std;

struct point {
        double x, y;
        point () {
                x = y = 0.0;
        }

        point (double _x, double _y) : x(_x), y(_y) {
        };
};

int n;
double x, y;
point gopher, dog, escape;
vector<point> holes;

double dist_point (const point &a, const point &b) {
        return hypot(a.x-b.x, a.y-b.y);
}

bool can_escape()
{
        int i;

        for (i = 0; i < n; i++) {
                if (dist_point(gopher, holes[i]) <= dist_point(dog, holes[i]) * 0.5) {
                        escape.x = holes[i].x;
                        escape.y = holes[i].y;
                        return true;
                }
        }

        return false;
}

int main(int argc, char const *argv[])
{
        #ifndef ONLINE_JUDGE
        #define ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #endif

        // cout << fixed << setprecision(3);

        int i, j;

        while (cin >> n >> gopher.x >> gopher.y >> dog.x >> dog.y) {
                holes.clear();

                for (i = 0; i < n; i++) {
                        cin >> x >> y;
                        holes.push_back(point(x, y));
                }

                if (can_escape()) {
                        printf("The gopher can escape through the hole at (%.03lf,%.03lf).\n", escape.x, escape.y);
                } else {
                        printf("The gopher cannot escape.\n");
                }
        }

        return 0;
}
