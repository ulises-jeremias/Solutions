/*
 * By: ulises-jeremias
 * From: http://coj.uci.cu/24h/problem.xhtml?pid=1855
 * Name: What are the Numbers
 * Date: 07/09/2017
 */

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
        ios_base::sync_with_stdio(false);

        vector<int> inputs;
        int t, n, i, j, c;
        bool found;

        inputs.resize(10005);
        cin >> t;

        for (i = 0; i < t; i++) {
                found = false;
                inputs.clear();
                inputs.assign(10005, 0);
                cin >> n;

                for (j = 0; j < n; j++) {
                        cin >> c;

                        if (inputs[c] == 0) {
                                inputs[c]++;
                        } else {
                                cout << c << endl;
                                if (!found) {
                                        found = true;
                                }
                        }
                }

                if (!found) {
                        cout << "Not Found!" << endl;
                }
        }

        return 0;
}
