/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=4&page=show_problem&problem=206
 * Name: Lining Up
 * Date: 21/11/2017
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <utility>

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

int x, y;
point_i a, b;
pair<double, int> slope;
vector<point_i> points;
map<double, int> slopes;
map<double, int>::iterator itr;
pair<map<double, int>::iterator, bool> ret;
string line;

int solve()
{
        int i, j, ans = 2, size = points.size();

        for (i = 0; i < size; i++) {
                if (ans > size - i) {
                        break;
                }

                slopes.clear();

                for (j = i + 1; j < size; j++) {
                        a = points[i];
                        b = points[j];
                        slope = make_pair((a.x == b.x ? 1.0 : ((double)(a.y - b.y) / (double)(a.x - b.x))), 2);
                        ret = slopes.insert(slope);

                        if (!ret.second) {
                                (*ret.first).second++;
                        }
                }

                for (itr = slopes.begin(); itr != slopes.end(); itr++) {
                        if (ans < (*itr).second) {
                                ans = (*itr).second;
                        }
                }
        }

        return ans;
}

int main(int argc, char const *argv[])
{
        #ifndef ONLINE_JUDGE
        #define ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #endif

        int TC, x, y;

        cin >> TC;

        getline(cin, line);
        getline(cin, line);

        while (TC--) {
                while (getline(cin, line), line.length()) {
                        istringstream sstrm(line);
                        sstrm >> x >> y;
                        points.push_back(point_i(x, y));
                }

                cout << solve() << endl;

                if (TC) {
                        cout << endl;
                }
        }

        return 0;
}
