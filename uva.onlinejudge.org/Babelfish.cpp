/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1223
 * Name: Babelfish
 * Date: 07/09/2017
 */

#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b, input;
    stringstream ss;
    map<string, string> dic;

    while (getline(cin, input), input.length()) {
        ss.clear();
        ss << input;
        ss >> a >> b;
        dic[b] = a;
    }

    while (cin >> b) {
        if (dic.find(b) == dic.end()) {
            cout << "eh" << endl;
        } else {
            cout << dic[b] << endl;
        }
    }

    return 0;
}
