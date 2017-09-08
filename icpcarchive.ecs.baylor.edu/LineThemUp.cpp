/*
 * By: ulises-jeremias
 * From: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&Itemid=99999999&category=706&page=show_problem&problem=5377
 * Name: Line Them Up
 * Date: 07/09/2017
 */

 #include <iostream>

using namespace std;

bool incresing (string *s, int n) {
        for (int i = 1; i < n; i++) if (s[i-1] > s[i]) return false;
        return true;
}

bool decresing (string *s, int n) {
        for (int i = 1; i < n; i++) if (s[i-1] < s[i]) return false;
        return true;
}

int main(int argc, char const *argv[]) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int tc, n;
        string s[30];

        tc = 1;
        while (cin >> n) {
                for (int i = 0; i < n; i++) {
                        cin >> s[i];
                }

                if (incresing(s, n)) {
                        cout<<"INCREASING"<<endl;
                } else if (decresing(s, n)) {
                        cout<<"DECREASING"<<endl;
                } else {
                        cout<<"NEITHER"<<endl;
                }
        }

        return 0;
}
