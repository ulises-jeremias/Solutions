/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=419
 * Name: Points in Figures: Rectangles, Circles, Triangles
 * Date: 21/11/2017
 */

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>

#define EPS 1e-9
#define INF 1 << 30

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

struct point_i
{
        int x, y;

        point_i () {
                x = y = 0;
        }

        point_i (int _x, int _y) : x(_x), y(_y) {
        };
};

struct point
{
        double x, y;

        point () {
                x = y = 0.0;
        }

        point (double _x, double _y) : x(_x), y(_y) {
        };
};

struct shape
{
        vector<point> points;
        double radius;
        int sh;

        shape(point upper_left, point lower_right)
        {
                sh = 1;

                points.push_back(point(upper_left.x, upper_left.y));
                points.push_back(point(upper_left.x, lower_right.y));
                points.push_back(point(lower_right.x, lower_right.y));
                points.push_back(point(lower_right.x, upper_left.y));
                points.push_back(point(upper_left.x, upper_left.y));
        }

        shape(point center, double radius)
        {
                sh = 2;

                points.push_back(center);
                this->radius = radius;
        }

        shape(point a, point b, point c)
        {
                sh = 3;

                points.push_back(a);
                points.push_back(b);
                points.push_back(c);
        }
};

int n, np;
char op;
double radius;
point upper_left, lower_right, center, a, b, c, p;
vector<shape> shapes;

double dist_point (const point &a, const point &b) {
        return hypot(a.x-b.x, a.y-b.y);
}

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

bool is_inside_box(int idx)
{
        shape rectangle = shapes[idx];

        for (int i = 0; i < 4; i++) {
                if (!ccw(rectangle.points[i], rectangle.points[i + 1], p)) {
                        return false;
                }
        }

        return true;
}

bool is_inside_circle(int idx)
{
        return (dist_point(shapes[idx].points[0], p) < shapes[idx].radius);
}

bool is_inside_triangle(int idx)
{
        shape triangle = shapes[idx];
        a = triangle.points[0];
        b = triangle.points[1];
        c = triangle.points[2];

        if (to_vec_cross(a, b, p)*to_vec_cross(a, c, p) > 0.0) {
                return false;
        } else if (to_vec_cross(b, a, p)*to_vec_cross(b, c, p) > 0.0) {
                return false;
        } else if (to_vec_cross(c, b, p)*to_vec_cross(c, a, p) > 0.0) {
                return false;
        }

        return true;
}

bool is_inside(int idx)
{
        if (shapes[idx].sh == 1) {
                return is_inside_box(idx);
        } else if (shapes[idx].sh == 2) {
                return is_inside_circle(idx);
        } else {
                return is_inside_triangle(idx);
        }
}

int main(int argc, char const *argv[]) {
        #ifndef ONLINE_JUDGE
        #define ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #endif

        int i;

        n = 0;
        while (scanf(" %c", &op), op != '*') {
                if (op == 'r') {
                        scanf("%lf %lf", &upper_left.x, &upper_left.y);
                        scanf("%lf %lf", &lower_right.x, &lower_right.y);

                        shapes.push_back(shape(upper_left, lower_right));
                } else if (op == 'c') {
                        scanf("%lf %lf", &center.x, &center.y);
                        scanf("%lf", &radius);

                        shapes.push_back(shape(center, radius));
                } else {
                        scanf("%lf %lf", &a.x, &a.y);
                        scanf("%lf %lf", &b.x, &b.y);
                        scanf("%lf %lf", &c.x, &c.y);

                        shapes.push_back(shape(a, b, c));
                }

                n++;
        }

        np = 1;
        while (scanf("%lf %lf", &p.x, &p.y), !((fabs(p.x - 9999.9) < EPS) && (fabs(p.y - 9999.9) < EPS))) {

                bool any = false;
                for (i = 0; i < n; i++) {
                        if (is_inside(i)) {
                                printf("Point %d is contained in figure %d\n", np, i + 1);
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
