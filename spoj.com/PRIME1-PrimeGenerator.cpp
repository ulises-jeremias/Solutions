/*
 * By: ulises-jeremias
 * From: http://www.spoj.com/problems/PRIME1/
 * Name: PRIME1 - Prime Generator
 * Date: 07/09/2017
 */

 #include <iostream>
 #include <string>

 using namespace std;

 static int max_cout;

 bool prime(int n)
 {
     int i;
     if (n == 1) {
         return false;
     }

     for (i = 2; i*i <= n; i++) {
         if (n % i != 0) {
             continue;
         }
         return false;
     }
     return true;
 }

 int main(int argc, char const *argv[])
 {
     ios_base::sync_with_stdio(0);

     int i, j, from, to;
     string output = "";
     cin >> max_cout;

     for (i = 0; i < max_cout; i++) {
         cin >> from >> to;

         for (j = from; j <= to; j++) {
             output = prime(j) ? to_string(j) + "\n" : "";
             cout << output;
             output.clear();
         }
     }

     return 0;
 }
