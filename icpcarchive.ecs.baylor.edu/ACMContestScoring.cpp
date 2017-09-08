/*
 * By: ulises-jeremias
 * From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5372
 * Name: ACM Contest Scoring
 * Date: 07/09/2017
 */

 #include <iostream>

 using namespace std;

 int main(int argc, char const *argv[])
 {
     ios_base::sync_with_stdio(0);

     int wrong[27];
     int minutes, i, right, total_time;
     char problem;
     int key;
     string state;

     while (cin >> minutes >> problem >> state) {
         total_time = right = 0;
         key = problem - 'A';
         *wrong = {0};

         while (minutes != -1) {
             if (state == "wrong") {
                 wrong[key]++;
             } else {
                 right++;
                 total_time += minutes;
                 total_time += wrong[key]*20;
             }

             cin >> minutes >> problem >> state;
         }

         cout << to_string(right) + " " + to_string(total_time) << "\n";
     }

     return 0;
 }
