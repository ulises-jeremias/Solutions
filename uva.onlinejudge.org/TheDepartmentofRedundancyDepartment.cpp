/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=425
 * Name: The Department of Redundancy Department
 * Date: 07/09/2017
 */

 #include <iostream>
 #include <map>
 #include <queue>

 using namespace std;

 int main(int argc, char const *argv[]) {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);

     int n;
     map<int, int> map;
     queue<int> q;

     while (cin >> n) {
         if (map.find(n) != map.end()) {
             map[n]++;
         } else {
             map[n] = 1;
             q.push(n);
         }
     }

     while (q.size()) {
         cout << q.front() << " " << map[q.front()] << endl;
         q.pop();
     }

     return 0;
 }
