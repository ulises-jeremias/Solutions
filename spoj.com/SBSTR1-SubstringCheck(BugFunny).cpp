/*
 * By: ulises-jeremias
 * From: http://www.spoj.com/problems/SBSTR1/
 * Name: SBSTR1 - Substring Check (Bug Funny)
 * Date: 07/09/2017
 */

 #include <iostream>
 #include <string>

using namespace std;

static int max_cout = 2;

int main(int argc, char const *argv[])
{
        string input, pattern, output;
        int result, i;

        output = "";

        for (i = 0; i < max_cout; i++) {
                cin >> input >> pattern;
                result = (int) input.find(pattern) != -1;
                output += (result ? "1\n" : "0\n");
        }

        cout << output;

        return 0;
}
