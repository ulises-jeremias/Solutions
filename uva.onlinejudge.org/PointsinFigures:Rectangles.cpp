/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=417
 * Name: Points in Figures: Rectangles
 * Date: 20/11/2017
 */

#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>

#define EPS 1e-9
#define INF 1 << 30

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;


struct point_i {
        int x, y;

        point_i () {
                x = y = 0;
        }

        point_i (int _x, int _y) : x(_x), y(_y) {
        };
};

struct point {
        double x, y;

        point () {
                x = y = 0.0;
        }

        point (double _x, double _y) : x(_x), y(_y) {
        };
};

int n, np;
char op;
point upper_left, lower_right, p;
point rectangles[15][5];

point to_vec(const point &a, const point &b)
{
        return point(a.x - b.x, a.y - b.y);
}

double cross(point a, point b)
{
        return (double) ((a.x * b.y) - (b.x * a.y));
}

bool ccw(point a, point b, point p)
{
        return cross(to_vec(a, p), to_vec(b, p)) > 0.0;
}

bool is_inside(int idx)
{
        for (int i = 0; i < 4; i++) {
                if (!ccw(rectangles[idx][i], rectangles[idx][i + 1], p)) {
                        return false;
                }
        }

        return true;
}

int main(int argc, char const *argv[]) {
        #ifndef ONLINE_JUDGE
        #define ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #endif

        int i;

        n = 1;
        while (scanf(" %c", &op), op != '*') {
                scanf("%lf %lf", &upper_left.x, &upper_left.y);
                scanf("%lf %lf", &lower_right.x, &lower_right.y);

                rectangles[n][0].x = upper_left.x;
                rectangles[n][0].y = upper_left.y;

                rectangles[n][1].x = upper_left.x;
                rectangles[n][1].y = lower_right.y;

                rectangles[n][2].x = lower_right.x;
                rectangles[n][2].y = lower_right.y;

                rectangles[n][3].x = lower_right.x;
                rectangles[n][3].y = upper_left.y;

                rectangles[n][4].x = upper_left.x;
                rectangles[n][4].y = upper_left.y;

                n++;
        }

        np = 1;
        while (scanf("%lf %lf", &p.x, &p.y), !((fabs(p.x - 9999.9) < EPS) && (fabs(p.y - 9999.9) < EPS))) {

                bool any = false;
                for (i = 1; i <= n; i++) {
                        if (is_inside(i)) {
                                printf("Point %d is contained in figure %d\n", np, i);
                                any = true;
                        }
                }

                if (!any) {
                        printf("Point %d is not contained in any figure\n", np);
                }

                np++;
        }

        return 0;
}
