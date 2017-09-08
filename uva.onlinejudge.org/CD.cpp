/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2949
 * Name: CD
 * Date: 07/09/2017
 */

 #include <iostream>

 using namespace std;


 int main(int argc, char const *argv[]) {
     #ifdef ONLINE_JUDGE
         ios_base::sync_with_stdio(false);
         cin.tie(NULL);
     #endif

     int i, n, m, a, ans, jack[1000005];

     while (cin >> n >> m, n || m) {
         for (i = 0; i < n; i++) {
             cin >> jack[i];
         }

         ans = i = 0;
         while (m--) {
             cin >> a;
             while (i < n && jack[i] < a) {
                 i++;
             }
             if (i < n && jack[i] == a) {
                 ans++;
             }
         }

         cout << ans << endl;
     }

     return 0;
 }
