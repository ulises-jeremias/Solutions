/*
 * By: ulises-jeremias
 * From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3146
 * Name: I Can Guess the Data Structure!
 * Date: 08/09/2017
 */

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(int argc, char const *argv[]) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n, i, op, v;
        stack<int> stk;
        queue<int> q;
        priority_queue<int> pq;
        bool is_stack, is_queue, is_priority_queue;

        while (cin >> n) {
                while (stk.size()) stk.pop();
                while (q.size()) q.pop();
                while (pq.size()) pq.pop();
                is_stack = is_queue = is_priority_queue = true;

                for (i = 0; i < n; i++) {
                        cin >> op >> v;

                        if (op == 1) {
                                stk.push(v);
                                q.push(v);
                                pq.push(v);
                        } else {
                                if (stk.size() == 0) {
                                        is_stack = is_queue = is_priority_queue = false;
                                } else {
                                        if (stk.top() != v) is_stack = false;
                                        stk.pop();
                                        if (q.front() != v) is_queue = false;
                                        q.pop();
                                        if (pq.top() != v) is_priority_queue = false;
                                        pq.pop();
                                }
                        }
                }

                if (!is_stack && !is_queue && !is_priority_queue) {
                        cout<<"impossible\n";
                } else if ((is_stack && is_queue) || (is_stack && is_priority_queue) || (is_queue && is_priority_queue)) {
                        cout<<"not sure\n";
                } else if (is_stack) {
                        cout<<"stack\n";
                } else if (is_queue) {
                        cout<<"queue\n";
                } else {
                        cout<<"priority queue\n";
                }
        }

        return 0;
}
