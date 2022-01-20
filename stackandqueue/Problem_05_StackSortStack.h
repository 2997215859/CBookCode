//
// Created by admin on 2021/11/14.
//
#include <stack>

using namespace std;

void StackSortStack(stack<int> &s) {
    stack<int> help;
    while (!s.empty()) {
        int t = s.top(); s.pop();

        while (!help.empty() && t > help.top()) {
            s.push(help.top()); help.pop();
        }
        help.push(t);
    }
    while (!help.empty()) {
        s.push(help.top()); help.pop();
    }
}

void TestStackSortStack() {
    stack<int> s;
    s.push(1);
    s.push(3);
    s.push(5);
    s.push(3);
    s.push(2);
    s.push(4);

    StackSortStack(s);

}