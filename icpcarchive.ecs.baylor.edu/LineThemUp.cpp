/*
 * By: ulises-jeremias
 * From: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&Itemid=99999999&category=706&page=show_problem&problem=5377
 * Name: Line Them Up
 * Date: 07/09/2017
 */

 #include <iostream>
 #include <string>

using namespace std;

bool is_less(string a, string b)
{
        return a < b;
}

bool is_greater(string a, string b)
{
        return a > b;
}

int main(int argc, char const *argv[]) {
        ios_base::sync_with_stdio(0);

        int i, j, k;
        bool (*block)(string, string);
        bool ordered;
        string name, previous, output = "";

        while (cin >> k) {
                output.clear();
                previous.clear();
                ordered = true;
                block = NULL;

                for (j = 0; j < k; j++) {
                        cin >> name;

                        if (!ordered) {
                                continue;
                        }

                        if (previous == "") {
                                previous = name;
                                continue;
                        }

                        if (block == NULL) {
                                block = name < previous ? &is_less : &is_greater;
                        }

                        ordered = block(name, previous);
                }

                if (!ordered) {
                        output += "NEITHER";
                } else {
                        output += block == is_less ? "DECREASING" : "INCREASING";
                }

                cout << output << '\n';
        }

        return 0;
}
