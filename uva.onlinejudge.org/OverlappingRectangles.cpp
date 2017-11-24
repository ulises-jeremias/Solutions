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
#include <cstdio>

#define EPS 1e-9
#define INF 1 << 30

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

int n;
char op;
point lower_left, upper_right, p, q;
point rectangles[2][5];

point to_vec(const point &a, const point &b)
{
        return point(a.x - b.x, a.y - b.y);
}

double cross(point a, point b)
{
        return (double) ((a.x * b.y) - (b.x * a.y));
}

double to_vec_cross(point a, point b, point c)
{
        return cross(to_vec(a, c), to_vec(b, c));
}

bool ccw(point a, point b, point p)
{
        return to_vec_cross(a, b, p) > 0.0;
}

bool is_inside(int idx)
{
        for (int i = 0; i < 4; i++) {
                if (!ccw(rectangles[0][i], rectangles[0][i + 1], rectangles[1][idx])) {
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

        int TC, i;
        string line;
        bool overlap;

        scanf("%d", &TC);
        getchar();
        getline(cin, line);

        while (TC--) {
                for (i = 0; i < 2; ++i)
                {
                        scanf("%d %d", &lower_left.x, &lower_left.y);
                        scanf("%d %d", &upper_right.x, &upper_right.y);

                        rectangles[i][0].x = lower_left.x;
                        rectangles[i][0].y = upper_right.y;

                        rectangles[i][1].x = lower_left.x;
                        rectangles[i][1].y = lower_left.y;

                        rectangles[i][2].x = upper_right.x;
                        rectangles[i][2].y = lower_left.y;

                        rectangles[i][3].x = upper_right.x;
                        rectangles[i][3].y = upper_right.y;

                        rectangles[i][4].x = lower_left.x;
                        rectangles[i][4].y = upper_right.y;
                }

                overlap = false;
                for (i = 0; i < 4; ++i)
                {
                        if (is_inside(i)) {
                                overlap = true;
                                break;
                        }
                }

                if (overlap) {
                        point w;
                        p = rectangles[1][i];
                        if (i == 0) {
                                w = rectangles[0][2];
                                printf("%d %d %d %d\n", p.x, w.y, w.x, p.y);
                        } else if (i == 1) {
                                w = rectangles[0][3];
                                printf("%d %d %d %d\n", p.x, p.y, w.x, w.y);
                        } else if (i == 2) {
                                w = rectangles[0][0];
                                printf("%d %d %d %d\n", w.x, p.y, p.x, w.y);
                        } else {
                                w = rectangles[0][1];
                                printf("%d %d %d %d\n", w.x, w.y, p.x, p.y);
                        }
                } else {
                        cout << "No Overlap" << endl;
                }
        }

        return 0;
}
